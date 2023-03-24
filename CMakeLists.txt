cmake_minimum_required(VERSION 3.24)
project(library_management C)

set(CMAKE_C_STANDARD 11)

add_executable(library_management main.c user_information/user.c user_information/user.h book_information/books.c book_information/books.h borrowing_information/borrowing.c borrowing_information/borrowing.h reader_information/readers_borrowing.c reader_information/readers_borrowing.h reader_information/readers_borrowing.h)
