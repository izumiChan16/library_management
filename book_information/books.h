//
// Created by izumi on 2023/3/21.
//

#ifndef LIBRARY_MANAGEMENT_BOOKS_H
#define LIBRARY_MANAGEMENT_BOOKS_H

#endif //LIBRARY_MANAGEMENT_BOOKS_H

typedef struct BooksInfo{
    char Bookname[12];
    char Writter[12];
//    作家
    char Publisher[12];
//    出版社
    char Booksid[12];
    char Price[12];
//    价格
    char ExistentialState[12];
//存在状态
    char Name[12];
//    学生姓名
    char student_number[12];
//    学号
}books_info;

typedef struct BookTable{
    struct BooksInfo BooksInfo[100];
    int bookCount;
}BookTable;