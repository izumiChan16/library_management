#include "books.h"
#include <stdio.h>
#include <string.h>

BooksTable initBooksTable(){
    BooksTable table;
    table.bookCount = 0;
    return table;
}

BooksTable readFile(BooksTable table, const char *books) {
    FILE *file = fopen(books, "r");
//    打开books，并返回一个指向books的指针
    if (!file) {
        printf("Error opening file.\n");
        return table;
    }
//    判断file是否为NULL。如果file为NULL，表示文件打开失败，这时会执行if代码块中的语句，打印一个错误消息并返回table。
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%d,%d,%d\n",
                  table.BooksInfo[table.bookCount].ISBN,
                  table.BooksInfo[table.bookCount].Bookname,
                  table.BooksInfo[table.bookCount].Writter,
                  table.BooksInfo[table.bookCount].Publisher,
                  table.BooksInfo[table.bookCount].Price,
                  &table.BooksInfo[table.bookCount].num_copies,
                  &table.BooksInfo[table.bookCount].num_available) != EOF) {
        table.bookCount++;
    }
//    从文件中读取一行数据并解析为书籍信息，直到文件结束。同时，每读取一行数据就会递增table.bookCount，用于记录当前已经读取了多少本书。
    fclose(file);
    return table;
}

BooksTable addBook(BooksTable table, const char *isbn, const char *bookname, const char *writer, const char *publisher, const char *price, const char *num_copies, const char *num_available) {
    if (table.bookCount >= num_copies) {
        printf("Book table is full.\n");
        return table;
    }
    strcpy(table.BooksInfo[table.bookCount].ISBN, isbn);
    strcpy(table.BooksInfo[table.bookCount].Bookname, bookname);
    strcpy(table.BooksInfo[table.bookCount].Writter, writer);
    strcpy(table.BooksInfo[table.bookCount].Publisher, publisher);
    strcpy(table.BooksInfo[table.bookCount].Price, price);
    strcpy(table.BooksInfo[table.bookCount].num_copies, num_copies);
    strcpy(table.BooksInfo[table.bookCount].num_available, num_available);
    table.bookCount++;
    return table;
}

int findISBN(BooksTable table, const char *isbn) {
    //循环浏览BooksTable数组
    for (int i = 0; i < table.bookCount; i++) {
        //将当前书籍的ISBN字段与给定的ISBN进行比较
        if (strcmp(table[i].BookInfo.isbn, isbn) == 0) {
            //如果它们匹配，返回当前书籍的索引
            return i;
        }
    }
    // 如果没有找到具有给定ISBN的书，返回-1
    return -1;
}

//按照书名查找
int findBookByBookName(BooksTable table, const char *bookname) {
    for (int i = 0; i < table.num_copies; i++) {
        if (strcmp(table.Bookname, bookname) == 0) {
            return i;
        }
    }
    return -1;
}

//ISBN删书
BooksTable deleteISBN(BooksTable table, const char *ISBN) {
    int index = findISBN(table, ISBN);
    if (index == -1) {
        printf("Book not found.\n");
        return table;
    }
    for (int i = index; i < table.bookCount - 1; i++) {
            table.BooksInfo[i] = table.BooksInfo[i+1];
    }
    table.bookCount--;
    return table;
}

BooksTable deleteBookByBookname(BooksTable table, const char *bookname) {
    int index = findBookByBookName(table, bookname);
    if (index == -1) {
        printf("Book not found.\n");
        return table;
    }
    for (int i = index; i < num_copies - 1; i++) {
        strcpy(table[i].ISBN, table[i+1].ISBN);
        strcpy(table[i].Bookname, table[i+1].Bookname);
        strcpy(table[i].Writter, table[i+1].Writter);
        strcpy(table[i].Publisher, table[i+1].Publisher);
        strcpy(table[i].Price, table[i+1].Price);
        strcpy(table[i].num_copies, table[i+1].num_copies);
        strcpy(table[i].num_available, table[i+1].num_available);
    }
    return table;
}

