cmake_minimum_required(VERSION 3.24)
project(library_management C)

set(CMAKE_C_STANDARD 11)

add_executable(library_management main.c user_information/user.c user_information/user.h book_information/books.c book_information/books.h borrowing_information/borrowing.c borrowing_information/borrowing.h reader_information/readers.c reader_information/readers.h reader_information/readers.h test.c reader_information/readers.c entrance/enter.c entrance/enter.h entrance/enter.h book_test.c)
