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
    char Isbn[12];
    char Price[12];
//    价格
    char
}books_info;

typedef struct BookTable{
    struct BooksInfo BooksInfo[100];
    int bookCount;
}BookTable;

BookTable initBookTable();
//初始化图书表

BookTable readFile(BookTable table, const char *filename);
//打开由“文件名”指定的文件fscanf.文件的每一行应包含格式为“ISBN，书籍名称，作者，出版商，价格，份数，可用数量”的书籍数据

BookTable addBook(BookTable table, const char *isbn, const char *bookname, const char *writer, const char *publisher, const char *price, const char *num_copies, const char *num_available);
//

int findisbn(BookTable table, const char *isbn);
//循环遍历对象数组中的每本书，并使用 将每本书的 ISBN 与给定字符串进行比较。如果找到匹配的书籍，该函数将返回其在数组中的索引

