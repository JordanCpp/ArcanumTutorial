
if (MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_CRT_NONSTDC_NO_DEPRECATE)  
endif()

if (WIN32)
    cmake_minimum_required(VERSION 2.9)

    set(SDL2_INCLUDE_DIRS "dependencies/SDL2-2.30.3/include")
    set(SDL2_LIBRARIES SDL2main SDL2)

    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        link_directories("dependencies/SDL2-2.30.3/lib/x64")
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
        link_directories("dependencies/SDL2-2.30.3/lib/x86")
    endif()
else()
    find_package(SDL2 REQUIRED)
endif()

include_directories(${SDL2_INCLUDE_DIRS})

include_directories("dependencies/zlib")

file(GLOB ZLIB_SOURCES 
"dependencies/zlib/adler32.c"
"dependencies/zlib/compress.c"
"dependencies/zlib/crc32.c"
"dependencies/zlib/deflate.c"
"dependencies/zlib/gzclose.c"
"dependencies/zlib/gzlib.c"
"dependencies/zlib/gzread.c"
"dependencies/zlib/gzwrite.c"
"dependencies/zlib/inflate.c"
"dependencies/zlib/infback.c"
"dependencies/zlib/inftrees.c"
"dependencies/zlib/inffast.c"
"dependencies/zlib/trees.c"
"dependencies/zlib/uncompr.c"
"dependencies/zlib/zutil.c")

include_directories("Backends/SDL2")
file(GLOB_RECURSE BACKEND_SOURCES "Backends/SDL2/Pollux/*.cpp")

include_directories("Backends/Shared")
file(GLOB_RECURSE SHARED_SOURCES "Backends/Shared/Pollux/*.cpp")

include_directories("Arcanum/source")
file(GLOB_RECURSE ARCANUM_SOURCES "Arcanum/*.cpp")

add_executable(Game "main.cpp" ${BACKEND_SOURCES} ${SHARED_SOURCES} ${ARCANUM_SOURCES} ${ZLIB_SOURCES})
target_link_libraries(Game ${SDL2_LIBRARIES})
