//
// Created by izumi on 2023/3/24.
//
#include "readers.h"
#include <stdio.h>
#include <string.h>

ReadersTable initReadersTable(){
    ReadersTable table;
    table.readersCount = 0;
    return table;
}

// 从文件中读取读者表并返回
ReadersTable readReadersTableFromFile(ReadersTable table, const char *filename){
    FILE *file = fopen(filename, "r"); // 打开文件
    if (!file) { // 如果文件打开失败
        printf("Error opening file.\n"); // 打印错误信息
        return table; // 返回原始表格
    }
    // 从文件中读取每一行读者信息，并将其存储在表格中
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",
                  table.readersTable[table.readersCount].userid,
                  table.readersTable[table.readersCount].username,
                  table.readersTable[table.readersCount].contact,
                  table.readersTable[table.readersCount].membership_type,
                  table.readersTable[table.readersCount].membership_expiration_date,
                  table.readersTable[table.readersCount].date_created,
                  table.readersTable[table.readersCount].last_updated) != EOF) {
        table.readersCount++; // 读者数量加1
    }
    fclose(file); // 关闭文件
    return table; // 返回读者表格
}

// 向读者表格中添加一个读者，并返回更新后的表格
ReadersTable addReader(
        ReadersTable table,
        const char *userid, const char *username,
        const char *contact, const char *membership_type,
        const char  *membership_expiration_date, const char *date_created,
        const char  *last_updated
){
    ReadersInfo reader; // 创建一个新的读者
    // 将读者信息复制到新的读者结构体中
    strcpy(reader.userid, userid);
    strcpy(reader.username, username);
    strcpy(reader.contact, contact);
    strcpy(reader.membership_type, membership_type);
    strcpy(reader.membership_expiration_date, membership_expiration_date);
    strcpy(reader.date_created, date_created);
    strcpy(reader.last_updated, last_updated);
    table.readersTable[table.readersCount] = reader; // 将新的读者添加到表格中
    table.readersCount++; // 读者数量加1
    return table; // 返回更新后的表格
}

// 从读者表格中删除一个读者，并返回更新后的表格
ReadersTable deleteReader(ReadersTable table, const char *userid){
    int i;
    // 查找要删除的读者的位置
    for (i = 0; i < table.readersCount; i++) {
        if (strcmp(table.readersTable[i].userid, userid) == 0) {
            break;
        }
    }
    if (i == table.readersCount) { // 如果未找到读者
        printf("No such reader.\n"); // 打印错误信息
        return table; // 返回原始表格
    }
    // 将表格中的读者依次向前移动一位
    for (int j = i; j < table.readersCount - 1; j++) {
        table.readersTable[j] = table.readersTable[j + 1];
    }
    table.readersCount--; // 读者数量减1
    return table; // 返回更新后的表格
}


// 更新指定读者的信息，并返回更新后的表格
ReadersTable updateReader(ReadersTable table, const char *userid, const char *username,
                          const char *contact, const char *membership_type,
                          const char  *membership_expiration_date, const char *date_created,
                          const char  *last_updated){
    int i;
    // 查找指定读者的位置
    for (i = 0; i < table.readersCount; i++) {
        if (strcmp(table.readersTable[i].userid, userid) == 0) {
            break;
        }
    }
    if (i == table.readersCount) { // 如果未找到指定读者
        printf("No such reader.\n"); // 打印错误信息
        return table; // 返回原始表格
    }
    // 更新读者信息
    strcpy(table.readersTable[i].username, username);
    strcpy(table.readersTable[i].contact, contact);
    strcpy(table.readersTable[i].membership_type, membership_type);
    strcpy(table.readersTable[i].membership_expiration_date, membership_expiration_date);
    strcpy(table.readersTable[i].date_created, date_created);
    strcpy(table.readersTable[i].last_updated, last_updated);
    return table; // 返回更新后的表格
}

// 查找指定读者并显示其信息
ReadersTable searchReader(ReadersTable table, const char *userid){
    int i;
    // 查找指定读者的位置
    for (i = 0; i < table.readersCount; i++) {
        if (strcmp(table.readersTable[i].userid, userid) == 0) {
            break;
        }
    }
    if (i == table.readersCount) { // 如果未找到指定读者
        printf("No such reader.\n"); // 打印错误信息
        return table; // 返回原始表格
    }
    // 显示指定读者的信息
    printf("userid: %s\n", table.readersTable[i].userid);
    printf("username: %s\n", table.readersTable[i].username);
    printf("contact: %s\n", table.readersTable[i].contact);
    printf("membership_type: %s\n", table.readersTable[i].membership_type);
    printf("membership_expiration_date: %s\n", table.readersTable[i].membership_expiration_date);
    printf("date_created: %s\n", table.readersTable[i].date_created);
    printf("last_updated: %s\n", table.readersTable[i].last_updated);
    return table; // 返回原始表格
}

// 对读者表格按照读者ID进行排序，并返回更新后的表格
ReadersTable sortReader(ReadersTable table) {
    for (int i = 0; i < table.readersCount; i++) {
        for (int j = 0; j < table.readersCount - i - 1; j++) {
            if (strcmp(table.readersTable[j].userid, table.readersTable[j + 1].userid) > 0) {
                // 交换两个读者的位置
                ReadersInfo temp = table.readersTable[j];
                table.readersTable[j] = table.readersTable[j + 1];
                table.readersTable[j + 1] = temp;
            }
        }
    }
    return table; // 返回更新后的表格
}

ReadersTable saveReadersTableToFile(ReadersTable table, const char *filename){
    FILE *file = fopen(filename, "w"); // 打开文件
    if (file == NULL) { // 如果文件打开失败
        printf("Failed to open the file.\n"); // 打印错误信息
        return table; // 返回原始表格
    }
    // 将表格中的读者信息写入文件
    for (int i = 0; i < table.readersCount; i++) {
        fprintf(file, "%s,%s,%s,%s,%s,%s,%s\n",
                table.readersTable[i].userid,
                table.readersTable[i].username,
                table.readersTable[i].contact,
                table.readersTable[i].membership_type,
                table.readersTable[i].membership_expiration_date,
                table.readersTable[i].date_created,
                table.readersTable[i].last_updated);
    }
    fclose(file); // 关闭文件
    return table; // 返回原始表格
}
