#include "books.h"
#include <stdio.h>
#include <string.h>

BookTable initBookTable(){
    BookTable table;
    table.bookCount = 0;
    return table;
}

BookTable readFile(BookTable table, const char *books) {
    FILE *file = fopen(books, "r");
//    打开books，并返回一个指向books的指针
    if (!file) {
        printf("Error opening file.\n");
        return table;
    }
//    判断file是否为NULL。如果file为NULL，表示文件打开失败，这时会执行if代码块中的语句，打印一个错误消息并返回table。
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                  table.BooksInfo[table.bookCount].ISBN,
                  table.BooksInfo[table.bookCount].Bookname,
                  table.BooksInfo[table.bookCount].Writter,
                  table.BooksInfo[table.bookCount].Publisher,
                  table.BooksInfo[table.bookCount].Price,
                  table.BooksInfo[table.bookCount].Total,
                  table.BooksInfo[table.bookCount].Available) != EOF) {
        table.bookCount++;
    }
//    从文件中读取一行数据并解析为书籍信息，直到文件结束。同时，每读取一行数据就会递增table.bookCount，用于记录当前已经读取了多少本书。
    fclose(file);
    return table;
}

BookTable addBook(BookTable table, const char *isbn, const char *Bookname, const char *writer, const char *publisher, const char *price, const char *Total, const char *Available) {
    if (table.bookCount >= 100) {
        printf("Book table is full.\n");
        return table;
    }
    strcpy(table.BooksInfo[table.bookCount].ISBN, isbn);
    strcpy(table.BooksInfo[table.bookCount].Bookname, Bookname);
    strcpy(table.BooksInfo[table.bookCount].Writter, writer);
    strcpy(table.BooksInfo[table.bookCount].Publisher, publisher);
    strcpy(table.BooksInfo[table.bookCount].Price, price);
    strcpy(table.BooksInfo[table.bookCount].Total, Total);
    strcpy(table.BooksInfo[table.bookCount].Available, Available);
    table.bookCount++;
    return table;
}

int findISBN(BookTable table, const char *isbn) {
    //循环浏览bookTable数组
    for (int i = 0; i < table.bookCount; i++) {
        //将当前书籍的ISBN字段与给定的ISBN进行比较
        if (strcmp(table.BooksInfo[i].ISBN, isbn) == 0) {
            //如果它们匹配，返回当前书籍的索引
            return i;
        }
    }
    // 如果没有找到具有给定ISBN的书，返回-1
    return -1;
}

int findBookByBookname(BookTable table, const char *Bookname) {
    for (int i = 0; i < table.BooksInfo[i].Total; i++) {
        if (strcmp(table.BooksInfo[i].Bookname, Bookname) == 0) {
            return i;
        }
    }
    return -1;
}

BookTable deleteBookByBookname(BookTable table, const char *Bookname) {
    int index = findBookByBookname(table, Bookname);
    if (index == -1) {
        printf("Book not found.\n");
        return table;
    }
    for (int i = index; i < table.bookCount - 1; i++) {
        table.BooksInfo[i] = table.BooksInfo[i + 1];
    }
    table.bookCount--;
    return table;
}

BookTable modifyBookByISBN(BookTable table, const char *ISBN, const char *newPrice, const char *newTotal, const char *newAvailable) {
    int index = findISBN(table, ISBN);
    if (index == -1) {
        printf("Book not found.\n");
        return table;
    }
//    strcpy(table.BooksInfo[index].Publisher, newPublisher);
//    出版社与ISBN码绑定，所以不能通过ISBN码修改
    strcpy(table.BooksInfo[index].Price, newPrice);
    strcpy(table.BooksInfo[index].Total, newTotal);
    strcpy(table.BooksInfo[index].Available, newAvailable);
    return table;
};

BookTable modifyBookByBookname(BookTable table, const char *Bookname, const char *newPrice, const char *newTotal, const char *newAvailable) {
    int index = findBookByBookname(table, Bookname);
    if (index == -1) {
        printf("Book not found.\n");
        return table;
    }
    strcpy(table.BooksInfo[index].Price, newPrice);
    strcpy(table.BooksInfo[index].Total, newTotal);
    strcpy(table.BooksInfo[index].Available, newAvailable);
    return table;
}

void saveFile(BookTable table, const char *books) {
    FILE *file = fopen(books, "w");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < table.bookCount; i++) {
        fprintf(file, "%s,%s,%s,%s,%s\n",
                table.BooksInfo[i].Bookname,
                table.BooksInfo[i].Writter,
                table.BooksInfo[i].Publisher,
                table.BooksInfo[i].ISBN,
                table.BooksInfo[i].Price,
                table.BooksInfo[i].Total,
                table.BooksInfo[i].Available);
    }

    fclose(file);
}