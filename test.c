#include <stdio.h>
#include "reader_information/readers.h"

void testReaders(){
    ReadersTable table = initReadersTable();
    table = readReadersTableFromFile(table, "../data/readers.csv");
    // 测试添加读者信息
    table = addReader(table, "001", "John", "123456789", "Gold", "2024-12-31", "2022-03-24", "2022-03-25");
    table = addReader(table, "002", "Mary", "987654321", "Silver", "2023-06-30", "2022-03-25", "2022-03-25");
    table = addReader(table, "003", "Tom", "234567890", "Bronze", "2022-12-31", "2022-03-23", "2022-03-25");

    // 测试读取和保存读者信息到文件
    table = saveReadersTableToFile(table, "../data/new-readers.csv");

    // 测试更新读者信息
    table = updateReader(table, "001", "John Smith", "987654321", "Platinum", "2025-12-31", "2022-03-24", "2022-03-25");

    // 测试查找读者信息
    table = searchReader(table, "001");

    // 测试删除读者信息
    table = deleteReader(table, "002");

    // 测试按照读者ID排序
    table = sortReader(table);

    // 打印最终的读者表格
    printf("Readers table:\n");
    for (int i = 0; i < table.readersCount; i++) {
        printf("%s, %s, %s, %s, %s, %s, %s\n",
               table.readersTable[i].userid,
               table.readersTable[i].username,
               table.readersTable[i].contact,
               table.readersTable[i].membership_type,
               table.readersTable[i].membership_expiration_date,
               table.readersTable[i].date_created,
               table.readersTable[i].last_updated);
    }
}

int main(){
    testReaders();
    return 0;
}
