cmake_minimum_required(VERSION 2.6)

project(tinyxml)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

file(
    GLOB_RECURSE
    src_files
    src/*.c include/*.h
)

add_library(tinyxml STATIC ${src_files})
