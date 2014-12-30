cmake_minimum_required(VERSION 2.8)

project(hints)

add_compile_options(-std=c++11)

include_directories(. /usr/local/include)
link_directories(/usr/local/lib)

add_subdirectory(hints)
