cmake_minimum_required(VERSION 2.9)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (WIN32)
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

include_directories("Backends/SDL2")
file(GLOB_RECURSE BACKEND_SOURCES  "Backends/SDL2/*.cpp")
add_library(Backend ${BACKEND_SOURCES})
target_link_libraries(Backend ${SDL2_LIBRARIES})

include_directories("Arcanum/source")
file(GLOB_RECURSE ARCANUM_SOURCES  "Arcanum/*.cpp")
add_library(Arcanum ${ARCANUM_SOURCES})

add_executable(Game "main.cpp")
target_link_libraries(Game Backend Arcanum)