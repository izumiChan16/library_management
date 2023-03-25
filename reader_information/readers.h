//
// Created by izumi on 2023/3/24.
//

#ifndef LIBRARY_MANAGEMENT_READERS_H
#define LIBRARY_MANAGEMENT_READERS_H
#define MAXSIZE 100

/**
 * @Name ReadersInfo
 * @CreateTime 2023/3/24 8:49
 * @Author izumi
 * @Status DONE
 * 生成存储信息的结构体
 */
typedef struct ReadersInfo{
    char userid[20];
    char username[20];
    char contact[20];
    char membership_type[20];
    char membership_expiration_date[20];
    char date_created[20];
    char last_updated[20];

} ReadersInfo;

/**
 * @FunctionName ReadersTable
 * @CreateTime 2023/3/24 8:50
 * @Author izumi
 * DONE: 存储 ReadersInfo 的结构体
 */

typedef struct ReadersTable{
    ReadersInfo readersTable[MAXSIZE];
    int readersCount;
} ReadersTable;

// 初始化读者表
ReadersTable initReadersTable();

// 读取读者表
ReadersTable readReadersTableFromFile(ReadersTable table, const char *filename);

// 添加读者基础信息，允许部分信息留空
ReadersTable addReader(
        ReadersTable table,
        const char *userid, const char *username,
        const char *contact, const char *membership_type,
        const char  *membership_expiration_date, const char *date_created,
        const char  *last_updated
        );

ReadersTable  deleteReader(ReadersTable table, const char *userid);

ReadersTable updateReader(ReadersTable table, const char *userid, const char *username,
                          const char *contact, const char *membership_type,
                          const char  *membership_expiration_date, const char *date_created,
                          const char  *last_updated);

ReadersTable searchReader(ReadersTable table, const char *userid);

ReadersTable sortReader(ReadersTable table);

ReadersTable saveReadersTableToFile(ReadersTable table, const char *filename);



#endif //LIBRARY_MANAGEMENT_READERS_H