//
// Created by izumi on 2023/3/21.
//

#ifndef LIBRARY_MANAGEMENT_BOOKS_H
#define LIBRARY_MANAGEMENT_BOOKS_H


typedef struct BooksInfo{
    char Bookname[50];
    char Writter[20];
//    作家
    char Publisher[50];
//    出版社
    char ISBN[20];
    char Price[20];
//    价格
    char Total[20];
//    该编号图书总数
    char Available[20];
}BooksInfo;

typedef struct BookTable{
    struct BooksInfo BooksInfo[100];
    int bookCount;
//    书种类的个数
}BookTable;

BookTable initBookTable();
//初始化图书表

BookTable readBooksFile(BookTable table, const char *filename);
//打开由“文件名”指定的文件fscanf.文件的每一行应包含格式为“ISBN，书籍名称，作者，出版商，价格，份数，可用数量”的书籍数据

BookTable addBook(BookTable table, const char *isbn, const char *Bookname, const char *writer, const char *publisher, const char *price, const char *Total, const char *Available);
//

int findISBN(BookTable table, const char *isbn);
//循环遍历对象数组中的每本书，并使用 将每本书的 ISBN 与给定字符串进行比较。如果找到匹配的书籍，该函数将返回其在数组中的索引

int findBookByBookname(BookTable table, const char *Bookname);
//通过书名查找书籍

BookTable deleteBookByBookname(BookTable table, const char *Bookname);
//通过书名删除书籍

BookTable modifyBookByISBN(BookTable table, const char *ISBN, const char *newPrice, const char *newTotal, const char *newAvailable) ;
//通过ISBN码修改，因为ISBN码与书名，作者,出版社高度绑定所以只能改 总数，可用数，价格

BookTable modifyBookByBookname(BookTable table, const char *Bookname, const char *newPrice, const char *newTotal, const char *newAvailable) ;
//

void saveBooksFile(BookTable table, const char *books) ;
//保存文件

#endif
//写了两行注释