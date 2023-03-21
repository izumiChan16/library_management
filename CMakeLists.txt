cmake_minimum_required(VERSION 3.24)
project(library_management C)

set(CMAKE_C_STANDARD 11)

add_executable(library_management main.c user_information/user.c user_information/user.h book_information/book.c)
