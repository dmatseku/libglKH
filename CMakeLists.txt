cmake_minimum_required(VERSION 3.14)
project(glKH C)

include_directories(includes)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Ofast")

add_library(glKH STATIC
        callbacks/key_callback.c init/key_handler_init.c includes/libglKH_global_structs.h includes/libglKH.h add/key_handler_add.c handle/key_handle.c handle/handle_functions.c handle/handle.h)