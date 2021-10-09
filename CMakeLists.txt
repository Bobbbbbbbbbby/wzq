cmake_minimum_required(VERSION 3.20)
project(wzq C)

set(CMAKE_C_STANDARD 11)

file(GLOB_RECURSE c_files ${PROJECT_SOURCE_DIR}/src/*.c)

add_executable(wzq
        main.c func.c)
