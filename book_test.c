//
// Created by izumi on 2023/4/4.
//

#include "book_information/books.h"
#include <assert.h>
#include "stdio.h"

void testBookTable() {
    // 初始化一个空的BookTable
    BookTable table = initBookTable();

    // 读取books.csv文件
    table = readBooksFile(table, "../data/books.csv");
    printf("read\n");
    // 添加一本书
    // table = addBook(table, "1234567890", "The Hitchhiker's Guide to the Galaxy", "Douglas Adams", "Pan Books", "9.99", "10", "10");
    printf("add\n");
    // 根据ISBN修改一本书的信息
    // table = modifyBookByISBN(table, "1234567890", "12.99", "20", "20");
    printf("modify\n");
    // 根据书名修改一本书的信息
    // table = modifyBookByBookname(table, "红楼梦", "14.99", "30", "30");
    printf("modifyBy\n");
    // 根据书名删除一本书
    // table = deleteBookByBookname(table, "红楼梦");

    // 保存修改后的书籍信息到books.csv文件
    saveBooksFile(table, "books.csv");

    // 检查是否成功添加、修改、删除了书籍信息，并保存到文件中
    // assert(findISBN(table, "1234567890") != -1);
    // assert(findBookByBookname(table, "The Hitchhiker's Guide to the Galaxy") == -1);
}

int main(){

    testBookTable();
    return 0;
}
