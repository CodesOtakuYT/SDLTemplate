cmake_minimum_required(VERSION 3.24)
project(SDLTemplate LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

add_subdirectory(vendor)
add_subdirectory(src)
