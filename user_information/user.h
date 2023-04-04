#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

/**
 * @CreateTime 2023/3/21 18:55
 * @Author izumi
 * DONE: 定义结构体User
 */
typedef struct User {
    char userid[12];
    char password[20];
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


// 初始化用户表
UserTable initUserTable();

//读取文件，参数传入整个用户表和文件名（用来打开文件）
UserTable readFile(UserTable table, const char *filename);

// 添加用户，往用户表里添加用户，参数传入各种信息
UserTable addUser(UserTable table, const char *userid, const char *password, const char *username, const char *contact, const char *is_admin);

// 通过ID查找用户
int findUserById(UserTable table, const char *userid);

// 通过用户名查找用户
int findUserByUsername(UserTable table, const char *username);

// 通过ID删除用户
UserTable deleteUserById(UserTable table, const char *userid);

// 通过用户名删除用户
UserTable deleteUserByUsername(UserTable table, const char *username);

// 通过ID修改用户
UserTable modifyUserById(UserTable table, const char *userid, const char *newPassword, const char *newUsername, const char *newContact, const char *newIsAdmin) ;

// 通过用户名修改用户
UserTable modifyUserByUsername(UserTable table, const char *username, const char *newPassword, const char *newUserId, const char *newContact, const char *newIsAdmin);

// 最后保存文件
void saveFile(UserTable table, const char *filename) ;

#endif
