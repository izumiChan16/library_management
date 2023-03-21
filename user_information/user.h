#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

/**
 * @CreateTime 2023/3/21 18:55
 * @Author izumi
 * DONE: 定义结构体User
 */
typedef struct User {
    char userid[12];
    char password[13];
    char username[20];
    char contact[12];
    char is_admin[10];
} User;

/**
 * @CreateTime 2023/3/21 18:55
 * @Author izumi
 * DONE: 定义`存储结构体信息`的结构体
 */
typedef struct UserTable {
    User userTable[100];
    int userCount;
} UserTable;


UserTable initUserTable();

UserTable readFile(UserTable table, const char *filename);

UserTable addUser(UserTable table, const char *userid, const char *password, const char *username, const char *contact, const char *is_admin);

int findUserById(UserTable table, const char *userid);

int findUserByUsername(UserTable table, const char *username);

UserTable deleteUserById(UserTable table, const char *userid);

UserTable deleteUserByUsername(UserTable table, const char *username);

UserTable modifyUserById(UserTable table, const char *userid, const char *newPassword, const char *newUsername, const char *newContact, const char *newIsAdmin) ;

UserTable modifyUserByUsername(UserTable table, const char *username, const char *newPassword, const char *newUserId, const char *newContact, const char *newIsAdmin);

void saveFile(UserTable table, const char *filename) ;

#endif
