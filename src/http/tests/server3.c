#include "iwn_tests.h"
#include "iwn_wf.h"
#include "iwn_wf_files.h"

#include <iowow/iwconv.h>

#include <string.h>
#include <signal.h>
#include <errno.h>

#define S_ROOT_DISPOSED 0x01U
static int _handle_get_empty_cnt;
static int _handle_root_cnt;

static volatile uint32_t state;
static struct iwn_poller *poller;
static struct iwn_wf_ctx *ctx;

static void _on_signal(int signo) {
  if (poller) {
    iwn_poller_shutdown_request(poller);
  }
}

static void _on_root_dispose(struct iwn_wf_ctx *ctx, void *data) {
  state |= S_ROOT_DISPOSED;
}

static int _handle_root(struct iwn_wf_req *req, void *user_data) {
  ++_handle_root_cnt;
  if (!iwn_http_response_write(req->http, 404, "text/plain", "Not found from root", -1)) {
    return -1;
  } else {
    return IWN_WF_RES_PROCESSED;
  }
}

static int _handle_echo(struct iwn_wf_req *req, void *user_data) {
  struct iwn_val val = iwn_http_request_header_get(req->http, "Forwarded", IW_LLEN("Forwarded"));
  if (val.len) {
    iwn_http_response_header_add(req->http, "Forwarded", val.buf, val.len);
  }
  if (req->flags & IWN_WF_GET) {
    iwn_http_response_write(req->http, 200, "text/plain", "/echo", IW_LLEN("/echo"));
  } else {
    iwn_http_response_printf(req->http, 200, "text/plain", "%.*s\n%s\n",
                             (int) req->body_len, req->body, (char*) user_data);
  }
  return IWN_WF_RES_PROCESSED;
}

static int _handle_get(struct iwn_wf_req *req, void *user_data) {
  return 0;
}

static int _handle_get_empty(struct iwn_wf_req *req, void *user_data) {
  ++_handle_get_empty_cnt;
  fprintf(stderr, "Line: %d, Route: %s; Path: %s\n", __LINE__, req->route->pattern, req->path);
  if (req->body_len) {
    fprintf(stderr, "Line: %d, Body: %.*s\n", __LINE__, (int) req->body_len, req->body);
  }
  IWN_ASSERT((intptr_t) user_data == 1);
  return 200; // Empty reponse with ok status
}

static int _handle_get_query(struct iwn_wf_req *req, void *user_data) {
  struct iwn_val foo = iwn_pair_find_val(&req->query_params, "foo", -1);
  IWN_ASSERT(foo.len && foo.buf);
  struct iwn_val baz = iwn_pair_find_val(&req->query_params, "baz", -1);
  IWN_ASSERT(baz.len && baz.buf);
  IWN_ASSERT(strcmp(baz.buf, "a@z") == 0);
  IWN_ASSERT(strcmp(foo.buf, "bar") == 0);
  bool ret = iwn_http_response_printf(req->http, 200, "text/plain;", "foo=%s&baz=%s", foo.buf, baz.buf);
  IWN_ASSERT(ret);
  return 1;
}

static int _handle_fail(struct iwn_wf_req *req, void *user_data) {
  return -1;
}

static int _handle_post_urlencoded(struct iwn_wf_req *req, void *user_data) {
  struct iwn_val foo = iwn_pair_find_val(&req->form_params, "foo", -1);
  IWN_ASSERT(foo.len && foo.buf);
  struct iwn_val baz = iwn_pair_find_val(&req->form_params, "baz", -1);
  IWN_ASSERT(baz.len && baz.buf);
  IWN_ASSERT(strcmp(baz.buf, "a@z") == 0);
  IWN_ASSERT(strcmp(foo.buf, "bar") == 0);
  bool ret = iwn_http_response_printf(req->http, 200, "text/plain;", "foo=%s&baz=%s", foo.buf, baz.buf);
  IWN_ASSERT(ret);
  return 1;
}

static int _handle_put_data(struct iwn_wf_req *req, void *user_data) {
  IWN_ASSERT(req->body && req->body_len);
  bool ret = iwn_http_response_write(req->http, 200, "text/plan", req->body, req->body_len);
  IWN_ASSERT(ret);
  return 1;
}

static int _handle_post_bigparam(struct iwn_wf_req *req, void *user_data) {
  struct iwn_val bigparam = iwn_pair_find_val(&req->form_params, "bigparam", -1);
  IWN_ASSERT(bigparam.len && bigparam.buf);
  bool ret = iwn_http_response_write(req->http, 200, "text/plain", bigparam.buf, bigparam.len);
  IWN_ASSERT(ret)
  return 1;
}

static int _handle_post_multipart(struct iwn_wf_req *req, void *user_data) {
  atomic_int af = iwn_assertions_failed;
  struct iwn_pair *p = iwn_pair_find(&req->form_params, "foo", -1);
  IWN_ASSERT(p);
  if (p) {
    IWN_ASSERT(strncmp(p->val, "bar", p->val_len) == 0);
  }
  p = iwn_pair_find(&req->form_params, "baz", -1);
  IWN_ASSERT(p);
  if (p) {
    IWN_ASSERT(strncmp(p->val, "a%40z", p->val_len) == 0);
  }
  p = iwn_pair_find(&req->form_params, "bigparam", -1);
  IWN_ASSERT(p);
  if (p) {
    IWN_ASSERT(p->val_len == 15165824);
  }
  if (af == iwn_assertions_failed) {
    return 200;
  } else {
    return 500;
  }
}

static int _handle_session_put(struct iwn_wf_req *req, void *user_data) {
  IWN_ASSERT(iwn_wf_session_put(req, "mykey", "70b2a86f-025b-4805-b267-871f3e1bc170") == 0);
  return 200;
}

static int _handle_session_get(struct iwn_wf_req *req, void *user_data) {
  const char *val = iwn_wf_session_get(req, "mykey");
  if (val) {
    bool ret = iwn_http_response_write(req->http, 200, "text/plan", val, strlen(val));
    IWN_ASSERT(ret);
    return 1;
  } else {
    return 500;
  }
}

static int _handle_user_get(struct iwn_wf_req*, void*);
static int _handle_user_get(struct iwn_wf_req *req, void *user_data) {
    
  const char *val = "I'm a long string that is returned from the user_get handler";
  printf("Line: %d\n", __LINE__);
  if (val) {
    printf("Line: %d\n", __LINE__);
    bool ret = iwn_http_response_write(req->http, 200, "text/plain", val, strlen(val));
    // bool ret = iwn_http_response_write(req->http, 200, "text/plain", "jroll", strlen(val));
    printf("Line: %d; Retval: %d\n", __LINE__, ret);
    printf("Line: %d\n", __LINE__);
    return 0;
  } else {
    return 500;
  }
}

static int _handle_user_post(struct iwn_wf_req*, void*);
static int _handle_user_post(struct iwn_wf_req *req, void *user_data) {
  struct iwn_val bigparam = iwn_pair_find_val(&req->form_params, "bigparam", -1);
  IWN_ASSERT(bigparam.len && bigparam.buf);
  bool ret = iwn_http_response_write(req->http, 200, "text/plain", bigparam.buf, bigparam.len);
  IWN_ASSERT(ret)
  return 1;
}

static int _handle_file_get(struct iwn_wf_req *req, void *user_data) {
  const char *path = req->path_unmatched;
  while (*path == '/') ++path;
  return iwn_wf_file_serve(req, 0, path);
}

static void _handle_file_get2_completed(void *d) {
  FILE *f = d;
  IWN_ASSERT_FATAL(f);
  fclose(f);
}

static int _handle_file_get2(struct iwn_wf_req *req, void *user_data) {
  const char *path = req->path_unmatched;
  while (*path == '/') ++path;
  FILE *f = fopen(path, "r");
  IWN_ASSERT_FATAL(f);
  return iwn_wf_fileobj_serve(req, 0, f, _handle_file_get2_completed, f);
}

static int _handle_regex1_get(struct iwn_wf_req *req, void *user_data) {
  return 0;
}

int main(int argc, char *argv[]) {
  iwrc rc = 0;
  iwlog_init();

  signal(SIGPIPE, SIG_IGN);
  signal(SIGHUP, SIG_IGN);
  signal(SIGALRM, SIG_IGN);
  signal(SIGUSR1, SIG_IGN);
  signal(SIGUSR2, SIG_IGN);
  if (signal(SIGTERM, _on_signal) == SIG_ERR) {
    return EXIT_FAILURE;
  }
  if (signal(SIGINT, _on_signal) == SIG_ERR) {
    return EXIT_FAILURE;
  }

  bool ssl = false;
  int port = 9229;
  char *host = "0.0.0.0";
  int nthreads = 1;
  int oneshot = 1;

  for (int i = 0; i < argc; ++i) {
    if (strcmp(argv[i], "--ssl") == 0) {
      ssl = true;
    } else if (strcmp(argv[i], "--port") == 0 && i + 1 < argc) {
      port = iwatoi(argv[i + 1]);
    } else if (strcmp(argv[i], "--poll-threads") == 0 && i + 1 < argc) {
      nthreads = iwatoi(argv[i + 1]);
    } else if (strcmp(argv[i], "--poll-oneshot-events") == 0 && i + 1 < argc) {
      oneshot = iwatoi(argv[i + 1]);
    }
  }

  // Create WF context

  RCC(rc, finish, iwn_wf_create(&(struct iwn_wf_route) {
    .handler = _handle_root,
    .handler_dispose = _on_root_dispose,
    .tag = "root"
  }, &ctx));

  // Configure routes

  struct iwn_wf_route *r;

  RCC(rc, finish, iwn_wf_route(&(struct iwn_wf_route) {
    .ctx = ctx,
    .pattern = "/echo",
    .handler = _handle_echo,
  }, &r));

  RCC(rc, finish, iwn_wf_route(&(struct iwn_wf_route) {
    .ctx = ctx,
    .pattern = "/get",
    .handler = _handle_get,
  }, &r));

  RCC(rc, finish, iwn_wf_route(&(struct iwn_wf_route) {
    .parent = r,
    .pattern = "/empty",
    .handler = _handle_get_empty,
    .user_data = (void*) 1
  }, 0));

  RCC(rc, finish, iwn_wf_route(&(struct iwn_wf_route) {
    .parent = r,
    .pattern = "/query",
    .handler = _handle_get_query
  }, 0));

  RCC(rc, finish, iwn_wf_route(&(struct iwn_wf_route) {
    .ctx = ctx,
    .pattern = "^/fa.l",
    .handler = _handle_fail,
  }, 0));

  RCC(rc, finish, iwn_wf_route(&(struct iwn_wf_route) {
    .ctx = ctx,
    .pattern = "/post",
    .flags = IWN_WF_POST | IWN_WF_PUT
  }, &r));

  RCC(rc, finish, iwn_wf_route(&(struct iwn_wf_route) {
    .parent = r,
    .pattern = "/urlencoded",
    .handler = _handle_post_urlencoded,
    .flags = IWN_WF_POST
  }, 0));


  RCC(rc, finish, iwn_wf_route(&(struct iwn_wf_route) {
    .parent = r,
    .pattern = "/putdata",
    .handler = _handle_put_data,
    .flags = IWN_WF_PUT
  }, 0));

  RCC(rc, finish, iwn_wf_route(&(struct iwn_wf_route) {
    .parent = r,
    .pattern = "/bigparam",
    .handler = _handle_post_bigparam,
    .flags = IWN_WF_POST
  }, 0));

  RCC(rc, finish, iwn_wf_route(&(struct iwn_wf_route) {
    .parent = r,
    .pattern = "/multipart",
    .handler = _handle_post_multipart,
    .flags = IWN_WF_POST
  }, 0));

  RCC(rc, finish, iwn_wf_route(&(struct iwn_wf_route) {
    .ctx = ctx,
    .pattern = "/session/put",
    .handler = _handle_session_put,
  }, 0));

  RCC(rc, finish, iwn_wf_route(&(struct iwn_wf_route) {
    .ctx = ctx,
    .pattern = "/session/get",
    .handler = _handle_session_get,
  }, 0));

  /* user_get route */
  printf("Line: %d\n", __LINE__);
  
  RCC(rc, finish, iwn_wf_route(&(struct iwn_wf_route) {
    // .parent = r,
    .ctx = ctx,
    .pattern = "/user",
    .handler = _handle_user_get,
    .flags = IWN_WF_GET,
    .tag = "user",
  }, 0));
  printf("Line: %d\n", __LINE__);


  RCC(rc, finish, iwn_wf_route(&(struct iwn_wf_route) {
    .ctx = ctx,
    .pattern = "/file",
    .handler = _handle_file_get,
    .flags = IWN_WF_MATCH_PREFIX | IWN_WF_GET | IWN_WF_HEAD,
  }, 0));

  RCC(rc, finish, iwn_wf_route(&(struct iwn_wf_route) {
    .ctx = ctx,
    .pattern = "/file2",
    .handler = _handle_file_get2,
    .flags = IWN_WF_MATCH_PREFIX | IWN_WF_GET | IWN_WF_HEAD,
  }, 0));

  RCC(rc, finish, iwn_wf_route(iwn_wf_route_dir_attach(&(struct iwn_wf_route) {
    .ctx = ctx,
    .pattern = "/dir",
    .flags = IWN_WF_MATCH_PREFIX | IWN_WF_HEAD | IWN_WF_GET
  }, "./foo"), 0));


  // Start the server:
  RCC(rc, finish, iwn_poller_create(nthreads, oneshot, &poller));

  struct iwn_wf_server_spec spec = {
    // .listen = "localhost",
    .listen = host,
    .port = port,
    .poller = poller,
    .request_timeout_sec = -1,
    .request_timeout_keepalive_sec = -1,
  };

  if (ssl) {
    spec.ssl.private_key = "./server-eckey.pem";
    spec.ssl.private_key_len = -1;
    spec.ssl.certs = "./server-ecdsacert.pem";
    spec.ssl.certs_len = -1;
  }

  iwn_wf_route_print(ctx->root, stderr);

  RCC(rc, finish, iwn_wf_server(&spec, ctx));

  fprintf(stderr, "a4913a63-2330-47ae-9329-b59910f05052\n");
  iwn_poller_poll(poller);

finish:
  iwn_poller_destroy(&poller);
  printf("Line: %d\n", __LINE__);
  IWN_ASSERT(rc == 0);
  printf("Line: %d\n", __LINE__);
  IWN_ASSERT(state & S_ROOT_DISPOSED);
  printf("Line: %d\n", __LINE__);
  return iwn_assertions_failed > 0 ? 1 : 0;
}
