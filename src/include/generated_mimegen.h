#include <string.h>
#include <stdint.h>

static inline uint32_t _hash(const char *str) {
  unsigned char c;
  uint32_t hash = 5381;
  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c;
  }
  return hash;
}
static const char* _mimetype_find(const char *ext) {
  uint32_t b = _hash(ext) % 1024;
  switch(b) {
    case 5:
      if (strcmp(ext, "kil") == 0) return "application/x-killustrator";
      break;
    case 6:
      if (strcmp(ext, "gz") == 0) return "application/gzip";
      break;
    case 7:
      if (strcmp(ext, "sxw") == 0) return "application/vnd.sun.xml.writer";
      if (strcmp(ext, "kin") == 0) return "chemical/x-kinemage";
      break;
    case 9:
      if (strcmp(ext, "pcap") == 0) return "application/vnd.tcpdump.pcap";
      break;
    case 11:
      if (strcmp(ext, "wmlsc") == 0) return "application/vnd.wap.wmlscriptc";
      break;
    case 18:
      if (strcmp(ext, "vsd") == 0) return "application/vnd.visio";
      break;
    case 21:
      if (strcmp(ext, "hh") == 0) return "text/x-c++hdr";
      break;
    case 26:
      if (strcmp(ext, "lha") == 0) return "application/x-lha";
      break;
    case 28:
      if (strcmp(ext, "silo") == 0) return "model/mesh";
      break;
    case 32:
      if (strcmp(ext, "hs") == 0) return "text/x-haskell";
      break;
    case 33:
      if (strcmp(ext, "vss") == 0) return "application/vnd.visio";
      break;
    case 34:
      if (strcmp(ext, "vst") == 0) return "application/vnd.visio";
      break;
    case 37:
      if (strcmp(ext, "vsw") == 0) return "application/vnd.visio";
      break;
    case 44:
      if (strcmp(ext, "inp") == 0) return "chemical/x-gamess-input";
      if (strcmp(ext, "lhs") == 0) return "text/x-literate-haskell";
      break;
    case 45:
      if (strcmp(ext, "hpp") == 0) return "text/x-c++hdr";
      break;
    case 47:
      if (strcmp(ext, "ins") == 0) return "application/x-internet-signup";
      break;
    case 51:
      if (strcmp(ext, "dxr") == 0) return "application/x-director";
      break;
    case 52:
      if (strcmp(ext, "ddeb") == 0) return "application/vnd.debian.binary-package";
      break;
    case 54:
      if (strcmp(ext, "xpi") == 0) return "application/x-xpinstall";
      break;
    case 56:
      if (strcmp(ext, "onetmp") == 0) return "application/onenote";
      break;
    case 57:
      if (strcmp(ext, "pac") == 0) return "application/x-ns-proxy-autoconfig";
      break;
    case 58:
      if (strcmp(ext, "xpm") == 0) return "image/x-xpixmap";
      if (strcmp(ext, "wrl") == 0) return "model/vrml";
      break;
    case 62:
      if (strcmp(ext, "nef") == 0) return "image/x-nikon-nef";
      break;
    case 69:
      if (strcmp(ext, "gsf") == 0) return "application/x-font";
      if (strcmp(ext, "txt") == 0) return "text/plain";
      break;
    case 72:
      if (strcmp(ext, "lin") == 0) return "application/bbolin";
      break;
    case 73:
      if (strcmp(ext, "pas") == 0) return "text/x-pascal";
      break;
    case 74:
      if (strcmp(ext, "pat") == 0) return "image/x-coreldrawpattern";
      break;
    case 76:
      if (strcmp(ext, "gsm") == 0) return "audio/x-gsm";
      break;
    case 82:
      if (strcmp(ext, "wsc") == 0) return "text/scriptlet";
      break;
    case 84:
      if (strcmp(ext, "x3d") == 0) return "model/x3d+xml";
      break;
    case 86:
      if (strcmp(ext, "hqx") == 0) return "application/mac-binhex40";
      if (strcmp(ext, "jmz") == 0) return "application/x-jmol";
      break;
    case 89:
      if (strcmp(ext, "oda") == 0) return "application/oda";
      break;
    case 90:
      if (strcmp(ext, "odb") == 0) return "application/vnd.oasis.opendocument.database";
      break;
    case 91:
      if (strcmp(ext, "odc") == 0) return "application/vnd.oasis.opendocument.chart";
      break;
    case 94:
      if (strcmp(ext, "odf") == 0) return "application/vnd.oasis.opendocument.formula";
      break;
    case 95:
      if (strcmp(ext, "odg") == 0) return "application/vnd.oasis.opendocument.graphics";
      break;
    case 96:
      if (strcmp(ext, "zmt") == 0) return "chemical/x-mopac-input";
      break;
    case 97:
      if (strcmp(ext, "odi") == 0) return "application/vnd.oasis.opendocument.image";
      break;
    case 98:
      if (strcmp(ext, "js") == 0) return "application/javascript";
      break;
    case 100:
      if (strcmp(ext, "jng") == 0) return "image/x-jng";
      if (strcmp(ext, "pbm") == 0) return "image/x-portable-bitmap";
      break;
    case 101:
      if (strcmp(ext, "odm") == 0) return "application/vnd.oasis.opendocument.text-master";
      break;
    case 102:
      if (strcmp(ext, "thmx") == 0) return "application/vnd.ms-officetheme";
      break;
    case 103:
      if (strcmp(ext, "exe") == 0) return "application/x-msdos-program";
      break;
    case 104:
      if (strcmp(ext, "odp") == 0) return "application/vnd.oasis.opendocument.presentation";
      break;
    case 107:
      if (strcmp(ext, "ods") == 0) return "application/vnd.oasis.opendocument.spreadsheet";
      break;
    case 108:
      if (strcmp(ext, "odt") == 0) return "application/vnd.oasis.opendocument.text";
      break;
    case 109:
      if (strcmp(ext, "sv4cpio") == 0) return "application/x-sv4cpio";
      break;
    case 113:
      if (strcmp(ext, "jp2") == 0) return "image/jp2";
      break;
    case 114:
      if (strcmp(ext, "roff") == 0) return "application/x-troff";
      break;
    case 117:
      if (strcmp(ext, "maker") == 0) return "application/x-maker";
      break;
    case 118:
      if (strcmp(ext, "atom") == 0) return "application/atom+xml";
      break;
    case 120:
      if (strcmp(ext, "aifc") == 0) return "audio/x-aiff";
      break;
    case 122:
      if (strcmp(ext, "sv4crc") == 0) return "application/x-sv4crc";
      break;
    case 123:
      if (strcmp(ext, "mbox") == 0) return "application/mbox";
      if (strcmp(ext, "aiff") == 0) return "audio/x-aiff";
      break;
    case 125:
      if (strcmp(ext, "wasm") == 0) return "application/wasm";
      break;
    case 126:
      if (strcmp(ext, "pcf") == 0) return "application/x-font-pcf";
      break;
    case 127:
      if (strcmp(ext, "mid") == 0) return "audio/midi";
      break;
    case 129:
      if (strcmp(ext, "mif") == 0) return "application/x-mif";
      break;
    case 137:
      if (strcmp(ext, "kml") == 0) return "application/vnd.google-earth.kml+xml";
      break;
    case 144:
      if (strcmp(ext, "xslt") == 0) return "application/xslt+xml";
      if (strcmp(ext, "pcx") == 0) return "image/pcx";
      break;
    case 148:
      if (strcmp(ext, "xsd") == 0) return "application/xml";
      break;
    case 151:
      if (strcmp(ext, "kmz") == 0) return "application/vnd.google-earth.kmz";
      break;
    case 155:
      if (strcmp(ext, "pdb") == 0) return "chemical/x-pdb";
      break;
    case 156:
      if (strcmp(ext, "xsl") == 0) return "application/xslt+xml";
      if (strcmp(ext, "manifest") == 0) return "application/x-ms-manifest";
      break;
    case 159:
      if (strcmp(ext, "pdf") == 0) return "application/pdf";
      if (strcmp(ext, "abw") == 0) return "application/x-abiword";
      break;
    case 162:
      if (strcmp(ext, "hta") == 0) return "application/hta";
      break;
    case 164:
      if (strcmp(ext, "jpe") == 0) return "image/jpeg";
      if (strcmp(ext, "htc") == 0) return "text/x-component";
      break;
    case 165:
      if (strcmp(ext, "jpf") == 0) return "image/jpx";
      break;
    case 166:
      if (strcmp(ext, "jpg") == 0) return "image/jpeg";
      break;
    case 170:
      if (strcmp(ext, "ly") == 0) return "text/x-lilypond";
      break;
    case 172:
      if (strcmp(ext, "jpm") == 0) return "image/jpm";
      break;
    case 174:
      if (strcmp(ext, "htm") == 0) return "text/html";
      break;
    case 175:
      if (strcmp(ext, "mjs") == 0) return "application/javascript";
      break;
    case 179:
      if (strcmp(ext, "bak") == 0) return "application/x-trash";
      break;
    case 180:
      if (strcmp(ext, "csml") == 0) return "chemical/x-csml";
      break;
    case 182:
      if (strcmp(ext, "md") == 0) return "text/markdown";
      break;
    case 183:
      if (strcmp(ext, "me") == 0) return "application/x-troff-me";
      if (strcmp(ext, "jpx") == 0) return "image/jpx";
      break;
    case 186:
      if (strcmp(ext, "smil") == 0) return "application/smil+xml";
      break;
    case 188:
      if (strcmp(ext, "bat") == 0) return "application/x-msdos-program";
      if (strcmp(ext, "oga") == 0) return "audio/ogg";
      break;
    case 191:
      if (strcmp(ext, "mm") == 0) return "application/x-freemind";
      break;
    case 194:
      if (strcmp(ext, "ogg") == 0) return "audio/ogg";
      break;
    case 195:
      if (strcmp(ext, "fbdoc") == 0) return "application/x-maker";
      break;
    case 197:
      if (strcmp(ext, "ms") == 0) return "application/x-troff-ms";
      if (strcmp(ext, "ram") == 0) return "audio/x-pn-realaudio";
      break;
    case 200:
      if (strcmp(ext, "midi") == 0) return "audio/midi";
      break;
    case 202:
      if (strcmp(ext, "rar") == 0) return "application/rar";
      if (strcmp(ext, "wvx") == 0) return "video/x-ms-wvx";
      break;
    case 203:
      if (strcmp(ext, "ras") == 0) return "image/x-cmu-raster";
      break;
    case 207:
      if (strcmp(ext, "mpega") == 0) return "audio/mpeg";
      break;
    case 208:
      if (strcmp(ext, "iso") == 0) return "application/x-iso9660-image";
      break;
    case 209:
      if (strcmp(ext, "info") == 0) return "application/x-info";
      if (strcmp(ext, "isp") == 0) return "application/x-internet-signup";
      if (strcmp(ext, "ogv") == 0) return "video/ogg";
      break;
    case 211:
      if (strcmp(ext, "ogx") == 0) return "application/ogg";
      if (strcmp(ext, "mkv") == 0) return "video/x-matroska";
      break;
    case 213:
      if (strcmp(ext, "nb") == 0) return "application/mathematica";
      if (strcmp(ext, "ist") == 0) return "chemical/x-isostar";
      if (strcmp(ext, "vcard") == 0) return "text/vcard";
      break;
    case 214:
      if (strcmp(ext, "nc") == 0) return "application/x-netcdf";
      break;
    case 220:
      if (strcmp(ext, "pfa") == 0) return "application/x-font";
      break;
    case 221:
      if (strcmp(ext, "pfb") == 0) return "application/x-font";
      break;
    case 222:
      if (strcmp(ext, "xul") == 0) return "application/vnd.mozilla.xul+xml";
      break;
    case 226:
      if (strcmp(ext, "xcos") == 0) return "application/x-scilab-xcos";
      break;
    case 235:
      if (strcmp(ext, "cab") == 0) return "application/x-cab";
      break;
    case 236:
      if (strcmp(ext, "cac") == 0) return "chemical/x-cache";
      break;
    case 237:
      if (strcmp(ext, "pfr") == 0) return "application/font-tdpfr";
      break;
    case 242:
      if (strcmp(ext, "kpr") == 0) return "application/x-kpresenter";
      break;
    case 243:
      if (strcmp(ext, "gtar") == 0) return "application/x-gtar";
      break;
    case 244:
      if (strcmp(ext, "kpt") == 0) return "application/x-kpresenter";
      break;
    case 249:
      if (strcmp(ext, "dotm") == 0) return "application/vnd.ms-word.template.macroEnabled.12";
      if (strcmp(ext, "cap") == 0) return "application/vnd.tcpdump.pcap";
      break;
    case 253:
      if (strcmp(ext, "cat") == 0) return "application/vnd.ms-pki.seccat";
      break;
    case 255:
      if (strcmp(ext, "texi") == 0) return "application/x-texinfo";
      break;
    case 259:
      if (strcmp(ext, "mmd") == 0) return "chemical/x-macromodel-input";
      break;
    case 260:
      if (strcmp(ext, "dotx") == 0) return "application/vnd.openxmlformats-officedocument.wordprocessingml.template";
      break;
    case 261:
      if (strcmp(ext, "mmf") == 0) return "application/vnd.smaf";
      if (strcmp(ext, "movie") == 0) return "video/x-sgi-movie";
      break;
    case 262:
      if (strcmp(ext, "xspf") == 0) return "application/xspf+xml";
      break;
    case 265:
      if (strcmp(ext, "pgm") == 0) return "image/x-portable-graymap";
      break;
    case 266:
      if (strcmp(ext, "pgn") == 0) return "application/x-chess-pgn";
      if (strcmp(ext, "text") == 0) return "text/plain";
      break;
    case 267:
      if (strcmp(ext, "mml") == 0) return "text/mathml";
      break;
    case 268:
      if (strcmp(ext, "pgp") == 0) return "application/pgp-encrypted";
      if (strcmp(ext, "sisx") == 0) return "x-epoc/x-sisx-app";
      break;
    case 273:
      if (strcmp(ext, "atomsrv") == 0) return "application/atomserv+xml";
      break;
    case 274:
      if (strcmp(ext, "m3u8") == 0) return "application/x-mpegURL";
      break;
    case 276:
      if (strcmp(ext, "hwp") == 0) return "application/x-hwp";
      if (strcmp(ext, "ustar") == 0) return "application/x-ustar";
      break;
    case 280:
      if (strcmp(ext, "xwd") == 0) return "image/x-xwindowdump";
      break;
    case 284:
      if (strcmp(ext, "cbr") == 0) return "application/x-cbr";
      break;
    case 287:
      if (strcmp(ext, "gnumeric") == 0) return "application/x-gnumeric";
      break;
    case 288:
      if (strcmp(ext, "pk") == 0) return "application/x-tex-pk";
      break;
    case 289:
      if (strcmp(ext, "rdf") == 0) return "application/rdf+xml";
      if (strcmp(ext, "fchk") == 0) return "chemical/x-gaussian-checkpoint";
      if (strcmp(ext, "pl") == 0) return "text/x-perl";
      break;
    case 290:
      if (strcmp(ext, "pm") == 0) return "text/x-perl";
      break;
    case 292:
      if (strcmp(ext, "cbz") == 0) return "application/x-cbz";
      break;
    case 295:
      if (strcmp(ext, "mng") == 0) return "video/x-mng";
      break;
    case 296:
      if (strcmp(ext, "ps") == 0) return "application/postscript";
      break;
    case 299:
      if (strcmp(ext, "rdp") == 0) return "application/x-rdp";
      break;
    case 301:
      if (strcmp(ext, "sitx") == 0) return "application/x-stuffit";
      break;
    case 302:
      if (strcmp(ext, "sd2") == 0) return "audio/x-sd2";
      if (strcmp(ext, "py") == 0) return "text/x-python";
      break;
    case 308:
      if (strcmp(ext, "mp2") == 0) return "audio/mpeg";
      break;
    case 309:
      if (strcmp(ext, "mp3") == 0) return "audio/mpeg";
      break;
    case 310:
      if (strcmp(ext, "mp4") == 0) return "video/mp4";
      break;
    case 317:
      if (strcmp(ext, "hxx") == 0) return "text/x-c++hdr";
      break;
    case 319:
      if (strcmp(ext, "eps2") == 0) return "application/postscript";
      break;
    case 320:
      if (strcmp(ext, "eps3") == 0) return "application/postscript";
      if (strcmp(ext, "sce") == 0) return "application/x-scilab";
      break;
    case 324:
      if (strcmp(ext, "sci") == 0) return "application/x-scilab";
      if (strcmp(ext, "moc") == 0) return "text/x-moc";
      break;
    case 330:
      if (strcmp(ext, "sco") == 0) return "audio/csound";
      if (strcmp(ext, "qt") == 0) return "video/quicktime";
      break;
    case 332:
      if (strcmp(ext, "tar") == 0) return "application/x-tar";
      break;
    case 333:
      if (strcmp(ext, "cda") == 0) return "application/x-cdf";
      if (strcmp(ext, "scr") == 0) return "application/x-silverlight";
      if (strcmp(ext, "mol") == 0) return "chemical/x-mdl-molfile";
      break;
    case 335:
      if (strcmp(ext, "sct") == 0) return "text/scriptlet";
      break;
    case 336:
      if (strcmp(ext, "qgs") == 0) return "application/x-qgis";
      if (strcmp(ext, "moo") == 0) return "chemical/x-mopac-out";
      break;
    case 337:
      if (strcmp(ext, "mop") == 0) return "chemical/x-mopac-input";
      break;
    case 338:
      if (strcmp(ext, "cdf") == 0) return "application/x-cdf";
      break;
    case 339:
      if (strcmp(ext, "ksp") == 0) return "application/x-kspread";
      break;
    case 340:
      if (strcmp(ext, "taz") == 0) return "application/x-gtar-compressed";
      break;
    case 343:
      if (strcmp(ext, "xlam") == 0) return "application/vnd.ms-excel.addin.macroEnabled.12";
      if (strcmp(ext, "mov") == 0) return "video/quicktime";
      break;
    case 344:
      if (strcmp(ext, "ra") == 0) return "audio/x-pn-realaudio";
      break;
    case 345:
      if (strcmp(ext, "rb") == 0) return "application/x-ruby";
      break;
    case 347:
      if (strcmp(ext, "rd") == 0) return "chemical/x-mdl-rdfile";
      break;
    case 349:
      if (strcmp(ext, "sda") == 0) return "application/vnd.stardivision.draw";
      break;
    case 350:
      if (strcmp(ext, "cdr") == 0) return "image/x-coreldraw";
      break;
    case 351:
      if (strcmp(ext, "sdc") == 0) return "application/vnd.stardivision.calc";
      break;
    case 352:
      if (strcmp(ext, "sdd") == 0) return "application/vnd.stardivision.impress";
      if (strcmp(ext, "cdt") == 0) return "image/x-coreldrawtemplate";
      break;
    case 354:
      if (strcmp(ext, "sdf") == 0) return "application/vnd.stardivision.math";
      break;
    case 356:
      if (strcmp(ext, "old") == 0) return "application/x-trash";
      if (strcmp(ext, "rm") == 0) return "audio/x-pn-realaudio";
      if (strcmp(ext, "cdx") == 0) return "chemical/x-cdx";
      break;
    case 357:
      if (strcmp(ext, "cdy") == 0) return "application/vnd.cinderella";
      if (strcmp(ext, "mpc") == 0) return "chemical/x-mopac-input";
      break;
    case 359:
      if (strcmp(ext, "mpe") == 0) return "video/mpeg";
      break;
    case 361:
      if (strcmp(ext, "woff2") == 0) return "font/woff2";
      if (strcmp(ext, "mpg") == 0) return "video/mpeg";
      break;
    case 362:
      if (strcmp(ext, "mph") == 0) return "application/x-comsol";
      break;
    case 365:
      if (strcmp(ext, "shtml") == 0) return "text/html";
      break;
    case 367:
      if (strcmp(ext, "sds") == 0) return "application/vnd.stardivision.chart";
      break;
    case 368:
      if (strcmp(ext, "xyz") == 0) return "chemical/x-xyz";
      break;
    case 370:
      if (strcmp(ext, "bcpio") == 0) return "application/x-bcpio";
      break;
    case 371:
      if (strcmp(ext, "epsf") == 0) return "application/postscript";
      if (strcmp(ext, "sdw") == 0) return "application/vnd.stardivision.writer";
      if (strcmp(ext, "cef") == 0) return "chemical/x-cxf";
      break;
    case 373:
      if (strcmp(ext, "aif") == 0) return "audio/x-aiff";
      break;
    case 374:
      if (strcmp(ext, "epsi") == 0) return "application/postscript";
      break;
    case 376:
      if (strcmp(ext, "mpv") == 0) return "video/x-matroska";
      break;
    case 377:
      if (strcmp(ext, "dcm") == 0) return "application/dicom";
      break;
    case 380:
      if (strcmp(ext, "sd") == 0) return "chemical/x-mdl-sdfile";
      break;
    case 382:
      if (strcmp(ext, "dcr") == 0) return "application/x-director";
      break;
    case 383:
      if (strcmp(ext, "cer") == 0) return "chemical/x-cerius";
      break;
    case 384:
      if (strcmp(ext, "sh") == 0) return "application/x-sh";
      if (strcmp(ext, "rgb") == 0) return "image/x-rgb";
      break;
    case 389:
      if (strcmp(ext, "potm") == 0) return "application/vnd.ms-powerpoint.template.macroEnabled.12";
      break;
    case 392:
      if (strcmp(ext, "tcl") == 0) return "application/x-tcl";
      break;
    case 394:
      if (strcmp(ext, "lsf") == 0) return "video/x-la-asf";
      break;
    case 395:
      if (strcmp(ext, "jpeg") == 0) return "image/jpeg";
      break;
    case 396:
      if (strcmp(ext, "m3g") == 0) return "application/m3g";
      if (strcmp(ext, "opus") == 0) return "audio/ogg";
      break;
    case 399:
      if (strcmp(ext, "ser") == 0) return "application/java-serialized-object";
      if (strcmp(ext, "sw") == 0) return "chemical/x-swissprot";
      if (strcmp(ext, "3gp") == 0) return "video/3gpp";
      break;
    case 400:
      if (strcmp(ext, "potx") == 0) return "application/vnd.openxmlformats-officedocument.presentationml.template";
      break;
    case 408:
      if (strcmp(ext, "jpg2") == 0) return "image/jp2";
      break;
    case 410:
      if (strcmp(ext, "m3u") == 0) return "audio/mpegurl";
      break;
    case 412:
      if (strcmp(ext, "lsx") == 0) return "video/x-la-asf";
      break;
    case 414:
      if (strcmp(ext, "diff") == 0) return "text/x-diff";
      break;
    case 418:
      if (strcmp(ext, "sfd") == 0) return "application/vnd.font-fontforge-sfd";
      break;
    case 420:
      if (strcmp(ext, "tk") == 0) return "text/x-tcl";
      break;
    case 421:
      if (strcmp(ext, "ppsm") == 0) return "application/vnd.ms-powerpoint.slideshow.macroEnabled.12";
      break;
    case 422:
      if (strcmp(ext, "tm") == 0) return "text/texmacs";
      break;
    case 423:
      if (strcmp(ext, "one") == 0) return "application/onenote";
      if (strcmp(ext, "m4a") == 0) return "audio/mpeg";
      break;
    case 427:
      if (strcmp(ext, "tr") == 0) return "application/x-troff";
      break;
    case 428:
      if (strcmp(ext, "ts") == 0) return "video/MP2T";
      break;
    case 431:
      if (strcmp(ext, "jsonld") == 0) return "application/ld+json";
      break;
    case 432:
      if (strcmp(ext, "deb") == 0) return "application/vnd.debian.binary-package";
      if (strcmp(ext, "ppsx") == 0) return "application/vnd.openxmlformats-officedocument.presentationml.slideshow";
      break;
    case 433:
      if (strcmp(ext, "epub") == 0) return "application/epub+zip";
      break;
    case 434:
      if (strcmp(ext, "mesh") == 0) return "model/mesh";
      if (strcmp(ext, "bib") == 0) return "text/x-bibtex";
      break;
    case 436:
      if (strcmp(ext, "pls") == 0) return "audio/x-scpls";
      if (strcmp(ext, "sfv") == 0) return "text/x-sfv";
      break;
    case 441:
      if (strcmp(ext, "cache") == 0) return "chemical/x-cache";
      break;
    case 445:
      if (strcmp(ext, "ltx") == 0) return "text/x-tex";
      break;
    case 446:
      if (strcmp(ext, "bin") == 0) return "application/octet-stream";
      if (strcmp(ext, "c++") == 0) return "text/x-c++src";
      break;
    case 453:
      if (strcmp(ext, "sgf") == 0) return "application/x-go-sgf";
      break;
    case 454:
      if (strcmp(ext, "pptm") == 0) return "application/vnd.ms-powerpoint.presentation.macroEnabled.12";
      break;
    case 456:
      if (strcmp(ext, "val") == 0) return "chemical/x-ncbi-asn1-binary";
      break;
    case 458:
      if (strcmp(ext, "%") == 0) return "application/x-trash";
      break;
    case 459:
      if (strcmp(ext, "sgl") == 0) return "application/vnd.stardivision.writer-global";
      if (strcmp(ext, "kwd") == 0) return "application/x-kword";
      break;
    case 461:
      if (strcmp(ext, "msh") == 0) return "model/mesh";
      break;
    case 462:
      if (strcmp(ext, "msi") == 0) return "application/x-msi";
      break;
    case 464:
      if (strcmp(ext, "frame") == 0) return "application/x-maker";
      break;
    case 465:
      if (strcmp(ext, "pptx") == 0) return "application/vnd.openxmlformats-officedocument.presentationml.presentation";
      break;
    case 469:
      if (strcmp(ext, "msp") == 0) return "application/octet-stream";
      if (strcmp(ext, "alc") == 0) return "chemical/x-alchemy";
      break;
    case 470:
      if (strcmp(ext, "7z") == 0) return "application/x-7z-compressed";
      if (strcmp(ext, "tex") == 0) return "text/x-tex";
      break;
    case 474:
      if (strcmp(ext, "msu") == 0) return "application/octet-stream";
      break;
    case 475:
      if (strcmp(ext, "kwt") == 0) return "application/x-kword";
      break;
    case 477:
      if (strcmp(ext, "chm") == 0) return "chemical/x-chemdraw";
      break;
    case 490:
      if (strcmp(ext, "opf") == 0) return "application/oebps-package+xml";
      if (strcmp(ext, "png") == 0) return "image/png";
      break;
    case 496:
      if (strcmp(ext, "shp") == 0) return "application/x-qgis";
      if (strcmp(ext, "pnm") == 0) return "image/x-portable-anymap";
      break;
    case 502:
      if (strcmp(ext, "fch") == 0) return "chemical/x-gaussian-checkpoint";
      break;
    case 503:
      if (strcmp(ext, "cif") == 0) return "chemical/x-cif";
      break;
    case 504:
      if (strcmp(ext, "shx") == 0) return "application/x-qgis";
      break;
    case 505:
      if (strcmp(ext, "jnlp") == 0) return "application/x-java-jnlp-file";
      if (strcmp(ext, "gal") == 0) return "chemical/x-gaussian-log";
      break;
    case 506:
      if (strcmp(ext, "gam") == 0) return "chemical/x-gamess-input";
      break;
    case 507:
      if (strcmp(ext, "gan") == 0) return "application/x-ganttproject";
      break;
    case 511:
      if (strcmp(ext, "cmdf") == 0) return "chemical/x-cmdf";
      break;
    case 513:
      if (strcmp(ext, "wad") == 0) return "application/x-doom";
      break;
    case 514:
      if (strcmp(ext, "vcd") == 0) return "application/x-cdlink";
      if (strcmp(ext, "gau") == 0) return "chemical/x-gaussian-input";
      break;
    case 516:
      if (strcmp(ext, "vcf") == 0) return "text/vcard";
      break;
    case 517:
      if (strcmp(ext, "amr") == 0) return "audio/amr";
      if (strcmp(ext, "sid") == 0) return "audio/prs.sid";
      break;
    case 518:
      if (strcmp(ext, "tgf") == 0) return "chemical/x-mdl-tgf";
      break;
    case 519:
      if (strcmp(ext, "wk") == 0) return "application/x-123";
      if (strcmp(ext, "b") == 0) return "chemical/x-molconn-Z";
      break;
    case 520:
      if (strcmp(ext, "sig") == 0) return "application/pgp-signature";
      if (strcmp(ext, "c") == 0) return "text/x-csrc";
      break;
    case 521:
      if (strcmp(ext, "d") == 0) return "text/x-dsrc";
      if (strcmp(ext, "wm") == 0) return "video/x-ms-wm";
      break;
    case 524:
      if (strcmp(ext, "sik") == 0) return "application/x-trash";
      break;
    case 525:
      if (strcmp(ext, "h") == 0) return "text/x-chdr";
      break;
    case 529:
      if (strcmp(ext, "vcs") == 0) return "text/x-vcalendar";
      break;
    case 531:
      if (strcmp(ext, "wav") == 0) return "audio/x-wav";
      break;
    case 532:
      if (strcmp(ext, "sis") == 0) return "application/vnd.symbian.install";
      if (strcmp(ext, "o") == 0) return "application/x-object";
      break;
    case 533:
      if (strcmp(ext, "sit") == 0) return "application/x-stuffit";
      if (strcmp(ext, "wax") == 0) return "audio/x-ms-wax";
      if (strcmp(ext, "p") == 0) return "text/x-pascal";
      break;
    case 534:
      if (strcmp(ext, "wz") == 0) return "application/x-wingz";
      break;
    case 536:
      if (strcmp(ext, "pot") == 0) return "text/plain";
      break;
    case 537:
      if (strcmp(ext, "t") == 0) return "application/x-troff";
      break;
    case 538:
      if (strcmp(ext, "tgz") == 0) return "application/x-gtar-compressed";
      break;
    case 546:
      if (strcmp(ext, "texinfo") == 0) return "application/x-texinfo";
      break;
    case 547:
      if (strcmp(ext, "~") == 0) return "application/x-trash";
      break;
    case 553:
      if (strcmp(ext, "orc") == 0) return "audio/csound";
      break;
    case 554:
      if (strcmp(ext, "mvb") == 0) return "chemical/x-mopac-vib";
      break;
    case 556:
      if (strcmp(ext, "anx") == 0) return "application/annodex";
      if (strcmp(ext, "orf") == 0) return "image/x-olympus-orf";
      break;
    case 559:
      if (strcmp(ext, "wbxml") == 0) return "application/vnd.wap.wbxml";
      break;
    case 562:
      if (strcmp(ext, "ppm") == 0) return "image/x-portable-pixmap";
      break;
    case 563:
      if (strcmp(ext, "gcd") == 0) return "text/x-pcs-gcd";
      break;
    case 565:
      if (strcmp(ext, "gcf") == 0) return "application/x-graphing-calculator";
      break;
    case 566:
      if (strcmp(ext, "gcg") == 0) return "chemical/x-gcg8-sequence";
      break;
    case 567:
      if (strcmp(ext, "xz") == 0) return "application/x-xz";
      break;
    case 568:
      if (strcmp(ext, "pps") == 0) return "application/vnd.ms-powerpoint";
      if (strcmp(ext, "dif") == 0) return "video/dv";
      break;
    case 569:
      if (strcmp(ext, "ppt") == 0) return "application/vnd.ms-powerpoint";
      break;
    case 575:
      if (strcmp(ext, "onetoc2") == 0) return "application/onenote";
      break;
    case 579:
      if (strcmp(ext, "latex") == 0) return "application/x-latex";
      break;
    case 580:
      if (strcmp(ext, "dir") == 0) return "application/x-director";
      if (strcmp(ext, "bmp") == 0) return "image/x-ms-bmp";
      break;
    case 582:
      if (strcmp(ext, "pcf.Z") == 0) return "application/x-font-pcf";
      break;
    case 583:
      if (strcmp(ext, "skd") == 0) return "application/x-koan";
      break;
    case 584:
      if (strcmp(ext, "tif") == 0) return "image/tiff";
      break;
    case 592:
      if (strcmp(ext, "skm") == 0) return "application/x-koan";
      break;
    case 595:
      if (strcmp(ext, "skp") == 0) return "application/x-koan";
      break;
    case 599:
      if (strcmp(ext, "woff") == 0) return "application/font-woff";
      if (strcmp(ext, "skt") == 0) return "application/x-koan";
      break;
    case 609:
      if (strcmp(ext, "apk") == 0) return "application/vnd.android.package-archive";
      break;
    case 610:
      if (strcmp(ext, "lyx") == 0) return "application/x-lyx";
      break;
    case 615:
      if (strcmp(ext, "cls") == 0) return "text/x-tex";
      break;
    case 616:
      if (strcmp(ext, "markdown") == 0) return "text/markdown";
      break;
    case 617:
      if (strcmp(ext, "djv") == 0) return "image/vnd.djvu";
      break;
    case 620:
      if (strcmp(ext, "xbm") == 0) return "image/x-xbitmap";
      break;
    case 621:
      if (strcmp(ext, "prf") == 0) return "application/pics-rules";
      break;
    case 622:
      if (strcmp(ext, "otf") == 0) return "application/font-sfnt";
      break;
    case 623:
      if (strcmp(ext, "otg") == 0) return "application/vnd.oasis.opendocument.graphics-template";
      break;
    case 624:
      if (strcmp(ext, "mxf") == 0) return "application/mxf";
      if (strcmp(ext, "oth") == 0) return "application/vnd.oasis.opendocument.text-web";
      break;
    case 625:
      if (strcmp(ext, "gamin") == 0) return "chemical/x-gamess-input";
      break;
    case 627:
      if (strcmp(ext, "lzh") == 0) return "application/x-lzh";
      if (strcmp(ext, "shar") == 0) return "application/x-shar";
      break;
    case 632:
      if (strcmp(ext, "otp") == 0) return "application/vnd.oasis.opendocument.presentation-template";
      break;
    case 635:
      if (strcmp(ext, "ots") == 0) return "application/vnd.oasis.opendocument.spreadsheet-template";
      if (strcmp(ext, "flac") == 0) return "audio/flac";
      if (strcmp(ext, "prt") == 0) return "chemical/x-ncbi-asn1-ascii";
      break;
    case 636:
      if (strcmp(ext, "ott") == 0) return "application/vnd.oasis.opendocument.text-template";
      break;
    case 637:
      if (strcmp(ext, "323") == 0) return "text/h323";
      break;
    case 639:
      if (strcmp(ext, "gen") == 0) return "chemical/x-genbank";
      if (strcmp(ext, "mxu") == 0) return "video/vnd.mpegurl";
      break;
    case 641:
      if (strcmp(ext, "cml") == 0) return "chemical/x-cml";
      break;
    case 643:
      if (strcmp(ext, "lzx") == 0) return "application/x-lzx";
      break;
    case 645:
      if (strcmp(ext, "embl") == 0) return "chemical/x-embl-dl-nucleotide";
      if (strcmp(ext, "boo") == 0) return "text/x-boo";
      break;
    case 646:
      if (strcmp(ext, "xcf") == 0) return "application/x-xcf";
      break;
    case 649:
      if (strcmp(ext, "scala") == 0) return "text/x-scala";
      break;
    case 652:
      if (strcmp(ext, "psd") == 0) return "image/x-photoshop";
      break;
    case 653:
      if (strcmp(ext, "nwc") == 0) return "application/x-nwc";
      break;
    case 654:
      if (strcmp(ext, "smi") == 0) return "application/smil+xml";
      break;
    case 657:
      if (strcmp(ext, "cascii") == 0) return "chemical/x-cactvs-binary";
      break;
    case 659:
      if (strcmp(ext, "davmount") == 0) return "application/davmount+xml";
      break;
    case 662:
      if (strcmp(ext, "chrt") == 0) return "application/x-kchart";
      break;
    case 663:
      if (strcmp(ext, "hdf") == 0) return "application/x-hdf";
      break;
    case 664:
      if (strcmp(ext, "wmlc") == 0) return "application/vnd.wap.wmlc";
      break;
    case 665:
      if (strcmp(ext, "ros") == 0) return "chemical/x-rosdal";
      break;
    case 673:
      if (strcmp(ext, "dll") == 0) return "application/x-msdos-program";
      break;
    case 677:
      if (strcmp(ext, "udeb") == 0) return "application/vnd.debian.binary-package";
      break;
    case 680:
      if (strcmp(ext, "wmls") == 0) return "text/vnd.wap.wmlscript";
      break;
    case 682:
      if (strcmp(ext, "snd") == 0) return "audio/basic";
      break;
    case 684:
      if (strcmp(ext, "art") == 0) return "image/x-jg";
      break;
    case 686:
      if (strcmp(ext, "mpeg") == 0) return "video/mpeg";
      break;
    case 690:
      if (strcmp(ext, "ica") == 0) return "application/x-ica";
      break;
    case 692:
      if (strcmp(ext, "rpm") == 0) return "application/x-redhat-package-manager";
      if (strcmp(ext, "jad") == 0) return "text/vnd.sun.j2me.app-descriptor";
      break;
    case 694:
      if (strcmp(ext, "ice") == 0) return "x-conference/x-cooltalk";
      break;
    case 699:
      if (strcmp(ext, "cod") == 0) return "application/vnd.rim.cod";
      if (strcmp(ext, "fig") == 0) return "application/x-xfig";
      break;
    case 700:
      if (strcmp(ext, "asc") == 0) return "text/plain";
      break;
    case 701:
      if (strcmp(ext, "dmg") == 0) return "application/x-apple-diskimage";
      if (strcmp(ext, "jam") == 0) return "application/x-jam";
      break;
    case 703:
      if (strcmp(ext, "asf") == 0) return "video/x-ms-asf";
      break;
    case 704:
      if (strcmp(ext, "ico") == 0) return "image/vnd.microsoft.icon";
      break;
    case 706:
      if (strcmp(ext, "jar") == 0) return "application/java-archive";
      break;
    case 708:
      if (strcmp(ext, "com") == 0) return "application/x-msdos-program";
      if (strcmp(ext, "ics") == 0) return "text/calendar";
      break;
    case 711:
      if (strcmp(ext, "asn") == 0) return "chemical/x-ncbi-asn1";
      break;
    case 712:
      if (strcmp(ext, "docm") == 0) return "application/vnd.ms-word.document.macroEnabled.12";
      if (strcmp(ext, "aso") == 0) return "chemical/x-ncbi-asn1-binary";
      break;
    case 713:
      if (strcmp(ext, "dms") == 0) return "application/x-dms";
      break;
    case 715:
      if (strcmp(ext, "icz") == 0) return "text/calendar";
      break;
    case 718:
      if (strcmp(ext, "atomcat") == 0) return "application/atomcat+xml";
      break;
    case 719:
      if (strcmp(ext, "svgz") == 0) return "image/svg+xml";
      break;
    case 721:
      if (strcmp(ext, "asx") == 0) return "video/x-ms-asf";
      break;
    case 723:
      if (strcmp(ext, "docx") == 0) return "application/vnd.openxmlformats-officedocument.wordprocessingml.document";
      break;
    case 729:
      if (strcmp(ext, "cpa") == 0) return "chemical/x-compass";
      break;
    case 730:
      if (strcmp(ext, "html") == 0) return "text/html";
      break;
    case 731:
      if (strcmp(ext, "class") == 0) return "application/java-vm";
      break;
    case 734:
      if (strcmp(ext, "p7r") == 0) return "application/x-pkcs7-certreqresp";
      break;
    case 735:
      if (strcmp(ext, "brf") == 0) return "text/plain";
      break;
    case 737:
      if (strcmp(ext, "swfl") == 0) return "application/x-shockwave-flash";
      break;
    case 744:
      if (strcmp(ext, "cpp") == 0) return "text/x-c++src";
      break;
    case 745:
      if (strcmp(ext, "onepkg") == 0) return "application/onenote";
      break;
    case 746:
      if (strcmp(ext, "mpga") == 0) return "audio/mpeg";
      break;
    case 747:
      if (strcmp(ext, "spc") == 0) return "chemical/x-galactic-spc";
      break;
    case 748:
      if (strcmp(ext, "cpt") == 0) return "application/mac-compactpro";
      if (strcmp(ext, "cr2") == 0) return "image/x-canon-cr2";
      break;
    case 749:
      if (strcmp(ext, "iges") == 0) return "model/iges";
      break;
    case 756:
      if (strcmp(ext, "spl") == 0) return "application/futuresplash";
      break;
    case 758:
      if (strcmp(ext, "qtl") == 0) return "application/x-quicktimeplayer";
      break;
    case 761:
      if (strcmp(ext, "application") == 0) return "application/x-ms-application";
      if (strcmp(ext, "emb") == 0) return "chemical/x-embl-dl-nucleotide";
      if (strcmp(ext, "ief") == 0) return "image/ief";
      if (strcmp(ext, "uls") == 0) return "text/iuls";
      break;
    case 763:
      if (strcmp(ext, "doc") == 0) return "application/msword";
      if (strcmp(ext, "gif") == 0) return "image/gif";
      break;
    case 766:
      if (strcmp(ext, "bsd") == 0) return "chemical/x-crossfire";
      break;
    case 767:
      if (strcmp(ext, "c3d") == 0) return "chemical/x-chem3d";
      break;
    case 768:
      if (strcmp(ext, "spx") == 0) return "audio/ogg";
      break;
    case 771:
      if (strcmp(ext, "kar") == 0) return "audio/midi";
      if (strcmp(ext, "eml") == 0) return "message/rfc822";
      if (strcmp(ext, "h++") == 0) return "text/x-c++hdr";
      break;
    case 780:
      if (strcmp(ext, "dot") == 0) return "application/msword";
      break;
    case 789:
      if (strcmp(ext, "sql") == 0) return "application/x-sql";
      break;
    case 793:
      if (strcmp(ext, "gjc") == 0) return "chemical/x-gaussian-input";
      break;
    case 796:
      if (strcmp(ext, "gjf") == 0) return "chemical/x-gaussian-input";
      break;
    case 797:
      if (strcmp(ext, "rss") == 0) return "application/x-rss+xml";
      break;
    case 799:
      if (strcmp(ext, "mol2") == 0) return "chemical/x-mol2";
      break;
    case 800:
      if (strcmp(ext, "fli") == 0) return "video/fli";
      break;
    case 805:
      if (strcmp(ext, "avi") == 0) return "video/x-msvideo";
      break;
    case 806:
      if (strcmp(ext, "crl") == 0) return "application/x-pkcs7-crl";
      break;
    case 811:
      if (strcmp(ext, "jdx") == 0) return "chemical/x-jcamp-dx";
      break;
    case 812:
      if (strcmp(ext, "ent") == 0) return "chemical/x-ncbi-asn1-ascii";
      break;
    case 813:
      if (strcmp(ext, "src") == 0) return "application/x-wais-source";
      if (strcmp(ext, "flv") == 0) return "video/x-flv";
      break;
    case 814:
      if (strcmp(ext, "crt") == 0) return "application/x-x509-ca-cert";
      break;
    case 815:
      if (strcmp(ext, "ai") == 0) return "application/postscript";
      if (strcmp(ext, "oza") == 0) return "application/x-oz-application";
      break;
    case 817:
      if (strcmp(ext, "rtf") == 0) return "application/rtf";
      if (strcmp(ext, "crw") == 0) return "image/x-canon-crw";
      break;
    case 818:
      if (strcmp(ext, "deploy") == 0) return "application/octet-stream";
      if (strcmp(ext, "mmod") == 0) return "chemical/x-macromodel-input";
      break;
    case 822:
      if (strcmp(ext, "x3db") == 0) return "model/x3d+binary";
      break;
    case 825:
      if (strcmp(ext, "xht") == 0) return "application/xhtml+xml";
      break;
    case 827:
      if (strcmp(ext, "au") == 0) return "audio/basic";
      break;
    case 830:
      if (strcmp(ext, "srt") == 0) return "text/plain";
      break;
    case 831:
      if (strcmp(ext, "awb") == 0) return "audio/amr-wb";
      if (strcmp(ext, "csd") == 0) return "audio/csound";
      break;
    case 833:
      if (strcmp(ext, "csf") == 0) return "chemical/x-cache-csf";
      break;
    case 835:
      if (strcmp(ext, "csh") == 0) return "application/x-csh";
      if (strcmp(ext, "rtx") == 0) return "text/richtext";
      break;
    case 836:
      if (strcmp(ext, "hin") == 0) return "chemical/x-hin";
      break;
    case 840:
      if (strcmp(ext, "csm") == 0) return "chemical/x-csml";
      if (strcmp(ext, "igs") == 0) return "model/iges";
      break;
    case 842:
      if (strcmp(ext, "x3dv") == 0) return "model/x3d+vrml";
      break;
    case 844:
      if (strcmp(ext, "vmd") == 0) return "chemical/x-vmd";
      break;
    case 845:
      if (strcmp(ext, "eot") == 0) return "application/vnd.ms-fontobject";
      break;
    case 846:
      if (strcmp(ext, "css") == 0) return "text/css";
      break;
    case 848:
      if (strcmp(ext, "webm") == 0) return "video/webm";
      break;
    case 849:
      if (strcmp(ext, "pyc") == 0) return "application/x-python-code";
      if (strcmp(ext, "csv") == 0) return "text/csv";
      break;
    case 851:
      if (strcmp(ext, "ppam") == 0) return "application/vnd.ms-powerpoint.addin.macroEnabled.12";
      if (strcmp(ext, "webp") == 0) return "image/webp";
      break;
    case 859:
      if (strcmp(ext, "vms") == 0) return "chemical/x-vamas-iso14976";
      break;
    case 861:
      if (strcmp(ext, "pyo") == 0) return "application/x-python-code";
      break;
    case 863:
      if (strcmp(ext, "axa") == 0) return "audio/annodex";
      if (strcmp(ext, "ctab") == 0) return "chemical/x-cactvs-binary";
      break;
    case 875:
      if (strcmp(ext, "cc") == 0) return "text/x-c++src";
      break;
    case 877:
      if (strcmp(ext, "eps") == 0) return "application/postscript";
      break;
    case 879:
      if (strcmp(ext, "stc") == 0) return "application/vnd.sun.xml.calc.template";
      break;
    case 880:
      if (strcmp(ext, "std") == 0) return "application/vnd.sun.xml.draw.template";
      if (strcmp(ext, "cpio") == 0) return "application/x-cpio";
      break;
    case 884:
      if (strcmp(ext, "ctx") == 0) return "chemical/x-ctx";
      if (strcmp(ext, "axv") == 0) return "video/annodex";
      break;
    case 885:
      if (strcmp(ext, "sti") == 0) return "application/vnd.sun.xml.impress.template";
      break;
    case 888:
      if (strcmp(ext, "stl") == 0) return "application/sla";
      break;
    case 893:
      if (strcmp(ext, "cu") == 0) return "application/cu-seeme";
      break;
    case 895:
      if (strcmp(ext, "cub") == 0) return "chemical/x-gaussian-cube";
      break;
    case 896:
      if (strcmp(ext, "iii") == 0) return "application/x-iphone";
      break;
    case 897:
      if (strcmp(ext, "man") == 0) return "application/x-troff-man";
      break;
    case 899:
      if (strcmp(ext, "stw") == 0) return "application/vnd.sun.xml.writer.template";
      break;
    case 901:
      if (strcmp(ext, "sty") == 0) return "text/x-tex";
      break;
    case 906:
      if (strcmp(ext, "wma") == 0) return "audio/x-ms-wma";
      break;
    case 909:
      if (strcmp(ext, "wmd") == 0) return "application/x-ms-wmd";
      break;
    case 910:
      if (strcmp(ext, "key") == 0) return "application/pgp-keys";
      break;
    case 912:
      if (strcmp(ext, "book") == 0) return "application/x-maker";
      break;
    case 915:
      if (strcmp(ext, "torrent") == 0) return "application/x-bittorrent";
      break;
    case 917:
      if (strcmp(ext, "wml") == 0) return "text/vnd.wap.wml";
      if (strcmp(ext, "dl") == 0) return "video/dl";
      break;
    case 924:
      if (strcmp(ext, "tsp") == 0) return "application/dsptype";
      break;
    case 926:
      if (strcmp(ext, "xlsb") == 0) return "application/vnd.ms-excel.sheet.binary.macroEnabled.12";
      break;
    case 927:
      if (strcmp(ext, "json") == 0) return "application/json";
      if (strcmp(ext, "dv") == 0) return "video/dv";
      if (strcmp(ext, "wmv") == 0) return "video/x-ms-wmv";
      break;
    case 929:
      if (strcmp(ext, "dx") == 0) return "chemical/x-jcamp-dx";
      if (strcmp(ext, "wmx") == 0) return "video/x-ms-wmx";
      break;
    case 930:
      if (strcmp(ext, "erf") == 0) return "image/x-epson-erf";
      if (strcmp(ext, "tsv") == 0) return "text/tab-separated-values";
      break;
    case 931:
      if (strcmp(ext, "wmz") == 0) return "application/x-ms-wmz";
      break;
    case 934:
      if (strcmp(ext, "vrml") == 0) return "model/vrml";
      break;
    case 937:
      if (strcmp(ext, "xlsm") == 0) return "application/vnd.ms-excel.sheet.macroEnabled.12";
      break;
    case 939:
      if (strcmp(ext, "xlb") == 0) return "application/vnd.ms-excel";
      break;
    case 942:
      if (strcmp(ext, "tiff") == 0) return "image/tiff";
      break;
    case 944:
      if (strcmp(ext, "ttc") == 0) return "font/collection";
      break;
    case 947:
      if (strcmp(ext, "ttf") == 0) return "application/font-sfnt";
      break;
    case 948:
      if (strcmp(ext, "xlsx") == 0) return "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet";
      break;
    case 949:
      if (strcmp(ext, "svg") == 0) return "image/svg+xml";
      break;
    case 953:
      if (strcmp(ext, "ttl") == 0) return "text/turtle";
      break;
    case 954:
      if (strcmp(ext, "appcache") == 0) return "text/cache-manifest";
      break;
    case 956:
      if (strcmp(ext, "xls") == 0) return "application/vnd.ms-excel";
      break;
    case 957:
      if (strcmp(ext, "es") == 0) return "application/ecmascript";
      if (strcmp(ext, "xlt") == 0) return "application/vnd.ms-excel";
      if (strcmp(ext, "rxn") == 0) return "chemical/x-mdl-rxnfile";
      break;
    case 961:
      if (strcmp(ext, "wp5") == 0) return "application/vnd.wordperfect5.1";
      break;
    case 962:
      if (strcmp(ext, "mcm") == 0) return "chemical/x-macmolecule";
      break;
    case 964:
      if (strcmp(ext, "ez") == 0) return "application/andrew-inset";
      break;
    case 970:
      if (strcmp(ext, "xltm") == 0) return "application/vnd.ms-excel.template.macroEnabled.12";
      break;
    case 973:
      if (strcmp(ext, "fb") == 0) return "application/x-maker";
      break;
    case 981:
      if (strcmp(ext, "sldm") == 0) return "application/vnd.ms-powerpoint.slide.macroEnabled.12";
      if (strcmp(ext, "xltx") == 0) return "application/vnd.openxmlformats-officedocument.spreadsheetml.template";
      if (strcmp(ext, "swf") == 0) return "application/x-shockwave-flash";
      break;
    case 982:
      if (strcmp(ext, "xml") == 0) return "application/xml";
      break;
    case 984:
      if (strcmp(ext, "mdb") == 0) return "application/msaccess";
      if (strcmp(ext, "zip") == 0) return "application/zip";
      if (strcmp(ext, "fm") == 0) return "application/x-maker";
      break;
    case 992:
      if (strcmp(ext, "sldx") == 0) return "application/vnd.openxmlformats-officedocument.presentationml.slide";
      break;
    case 993:
      if (strcmp(ext, "cbin") == 0) return "chemical/x-cactvs-binary";
      break;
    case 994:
      if (strcmp(ext, "xtel") == 0) return "chemical/x-xtel";
      break;
    case 996:
      if (strcmp(ext, "mcif") == 0) return "chemical/x-mmcif";
      break;
    case 997:
      if (strcmp(ext, "nbp") == 0) return "application/mathematica";
      break;
    case 998:
      if (strcmp(ext, "cxf") == 0) return "chemical/x-cxf";
      break;
    case 999:
      if (strcmp(ext, "istr") == 0) return "chemical/x-isostar";
      if (strcmp(ext, "java") == 0) return "text/x-java";
      break;
    case 1000:
      if (strcmp(ext, "dvi") == 0) return "application/x-dvi";
      break;
    case 1002:
      if (strcmp(ext, "frm") == 0) return "application/x-maker";
      break;
    case 1008:
      if (strcmp(ext, "wpd") == 0) return "application/vnd.wordperfect";
      if (strcmp(ext, "gpt") == 0) return "chemical/x-mopac-graph";
      break;
    case 1010:
      if (strcmp(ext, "xhtml") == 0) return "application/xhtml+xml";
      if (strcmp(ext, "gf") == 0) return "application/x-tex-gf";
      break;
    case 1011:
      if (strcmp(ext, "sxc") == 0) return "application/vnd.sun.xml.calc";
      break;
    case 1012:
      if (strcmp(ext, "sxd") == 0) return "application/vnd.sun.xml.draw";
      break;
    case 1013:
      if (strcmp(ext, "patch") == 0) return "text/x-diff";
      break;
    case 1014:
      if (strcmp(ext, "etx") == 0) return "text/x-setext";
      break;
    case 1015:
      if (strcmp(ext, "sxg") == 0) return "application/vnd.sun.xml.writer.global";
      break;
    case 1016:
      if (strcmp(ext, "cxx") == 0) return "text/x-c++src";
      if (strcmp(ext, "gl") == 0) return "video/gl";
      break;
    case 1017:
      if (strcmp(ext, "sxi") == 0) return "application/vnd.sun.xml.impress";
      break;
    case 1018:
      if (strcmp(ext, "mopcrt") == 0) return "chemical/x-mopac-input";
      if (strcmp(ext, "vrm") == 0) return "x-world/x-vrml";
      break;
    case 1019:
      if (strcmp(ext, "wbmp") == 0) return "image/vnd.wap.wbmp";
      break;
    case 1021:
      if (strcmp(ext, "sxm") == 0) return "application/vnd.sun.xml.math";
      break;
    case 1022:
      if (strcmp(ext, "djvu") == 0) return "image/vnd.djvu";
      break;
  }
  return 0;
}

