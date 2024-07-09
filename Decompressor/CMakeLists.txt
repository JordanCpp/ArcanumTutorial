
include_directories("include")
include_directories("zlib")
file(GLOB_RECURSE DECOMPRESSOR_SOURCES "source/*.cpp")
add_library(Decompressor ${DECOMPRESSOR_SOURCES}
"zlib/adler32.c"
"zlib/compress.c"
"zlib/crc32.c"
"zlib/deflate.c"
"zlib/gzclose.c"
"zlib/gzlib.c"
"zlib/gzread.c"
"zlib/gzwrite.c"
"zlib/inflate.c"
"zlib/infback.c"
"zlib/inftrees.c"
"zlib/inffast.c"
"zlib/trees.c"
"zlib/uncompr.c"
"zlib/zutil.c")