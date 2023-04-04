//
// Created by izumi on 2023/3/28.
//

#ifndef LIBRARY_MANAGEMENT_ENTER_H
#define LIBRARY_MANAGEMENT_ENTER_H

#include <stdbool.h>
#include "../user_information/user.h"

// 登录，返回是否成功
bool login(UserTable table);
// 注册，返回是否成功
bool logon(UserTable table, char *userid, char *password);

//

#endif //LIBRARY_MANAGEMENT_ENTER_H
