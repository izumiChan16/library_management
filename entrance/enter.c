//
// Created by izumi on 2023/3/28.
//

#include <stdio.h>
#include <string.h>
#include "enter.h"

bool login(UserTable table) {

    char userid[12] , password[20];
    // set login status
    bool loginStatus = false;
    // if login failed, user could try again for 3 times
    for (int times = 0; times < 3; times++){
        printf("请输入用户名:");
        scanf("%s", userid);
        printf("请输入密码：");
        scanf("%s", password);


        // 检查输入规范
        if (strlen(userid) > 12 || strlen(password) > 12) {
            printf("输入过长\n");
            loginStatus = false;
            continue;
        }
        // userid only use number
        for (int i = 0; i < strlen(userid); i++) {
            if (userid[i] < '0' || userid[i] > '9') {
                printf("用户名只能使用数字\n");
                loginStatus = false;
                break;
            }
        }
        // pwd cannot be empty
        if (strlen(password) == 0) {
            printf("密码不能为空\n");
            loginStatus = false;
            continue;
        }

        // pwd cannot over 20 characters
        if (strlen(password) > 20) {
            printf("密码过长\n");
            loginStatus = false;
            continue;
        }

        // pwd only use number and letter
        for (int i = 0; i < strlen(password); i++) {
            if ((password[i] < '0' || password[i] > '9') && (password[i] < 'a' || password[i] > 'z') && (password[i] < 'A' || password[i] > 'Z')) {
                printf("密码只能使用数字和字母\n");
                loginStatus = false;
                break;
            }
        }


        // 检查用户是否存在
        int status = findUserById(table, userid);

        if (status == -1) {
            printf("用户不存在\n");
            loginStatus = false;
            continue;
        }

        if (strcmp(table.userTable[status].password, password) == 0) {
            printf("登录成功\n");
            loginStatus = true;
            break;
        } else {
            printf("密码错误\n");
            loginStatus = false;
            continue;
        }
    }

    // check user if admin
    if (loginStatus) {
        int status = findUserById(table, userid);
        if (strcmp(table.userTable[status].is_admin, "1") == 0) {
            printf("欢迎管理员登录\n");
            loginStatus = true;
        } else {
            printf("欢迎用户登录\n");
            loginStatus = true;
        }
    }

    return loginStatus;

}

bool logon(UserTable table, char *userid, char *password) {
    // check for userid
    int status = findUserById(table, userid);
    if (status != -1) {
        printf("用户已存在\n");
        return false;
    }

    table = addUser(table, userid, password, "NULL", "NULL", "0");
    printf("注册成功\n");
    return true;
}

