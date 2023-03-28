//
// Created by izumi on 2023/3/21.
//

#include "books.h"
#include <stdio.h>
#include <string.h>

BookTable initBookTable(){
    BookTable table;
    table.bookCount = 0;
    return table;
}

BookTable readFile(BookTable table, const char *filename) {
    FILE *file = fopen(books, "r");
//    打开books，并返回一个指向books的指针
    if (!file) {
        printf("Error opening file.\n");
        return table;
    }
//    判断file是否为NULL。如果file为NULL，表示文件打开失败，这时会执行if代码块中的语句，打印一个错误消息并返回table。
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%d,%d,%d\n",
                  table.bookTable[table.bookCount].isbn,
                  table.bookTable[table.bookCount].bookname,
                  table.bookTable[table.bookCount].writter,
                  table.bookTable[table.bookCount].publisher,
                  table.bookTable[table.bookCount].price,
                  &table.bookTable[table.bookCount].num_copies,
                  &table.bookTable[table.bookCount].num_available) != EOF) {
        table.bookCount++;
    }
//    从文件中读取一行数据并解析为书籍信息，直到文件结束。同时，每读取一行数据就会递增table.bookCount，用于记录当前已经读取了多少本书。
    fclose(file);
    return table;
}

BookTable addBook(BookTable table, const char *isbn, const char *bookname, const char *writer, const char *publisher, const char *price, const char *num_copies, const char *num_available) {
    if (table.bookCount >= MAX_BOOKS) {
        printf("Book table is full.\n");
        return table;
    }
    strcpy(table.bookTable[table.bookCount].isbn, isbn);
    strcpy(table.bookTable[table.bookCount].bookname, bookname);
    strcpy(table.bookTable[table.bookCount].writer, writer);
    strcpy(table.bookTable[table.bookCount].publisher, publisher);
    strcpy(table.bookTable[table.bookCount].price, price);
    strcpy(table.bookTable[table.bookCount].num_copies, num_copies);
    strcpy(table.bookTable[table.bookCount].num_available, num_available);
    table.bookCount++;
    return table;
}

int findISBN(BookTable table, const char *isbn) {
    //循环浏览bookTable数组
    for (int i = 0; i < table.bookCount; i++) {
        //将当前书籍的ISBN字段与给定的ISBN进行比较
        if (strcmp(table.bookTable[i].isbn, isbn) == 0) {
            //如果它们匹配，返回当前书籍的索引
            return i;
        }
    }
    // 如果没有找到具有给定ISBN的书，返回-1
    return -1;
}

//
