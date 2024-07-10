
include_directories("include")
include_directories("../dependencies/zlib")
file(GLOB_RECURSE DECOMPRESSOR_SOURCES "source/*.cpp")
add_library(Decompressor ${DECOMPRESSOR_SOURCES}
"../dependencies/zlib/adler32.c"
"../dependencies/zlib/compress.c"
"../dependencies/zlib/crc32.c"
"../dependencies/zlib/deflate.c"
"../dependencies/zlib/gzclose.c"
"../dependencies/zlib/gzlib.c"
"../dependencies/zlib/gzread.c"
"../dependencies/zlib/gzwrite.c"
"../dependencies/zlib/inflate.c"
"../dependencies/zlib/infback.c"
"../dependencies/zlib/inftrees.c"
"../dependencies/zlib/inffast.c"
"../dependencies/zlib/trees.c"
"../dependencies/zlib/uncompr.c"
"../dependencies/zlib/zutil.c")