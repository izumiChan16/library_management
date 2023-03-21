#include "user_information/user.h"
#include <stdio.h>


int main() {
    UserTable table = initUserTable();

    table = readFile(table, "data/users.csv");

    table = addUser(table, "20230321022", "20230321022", "新用户", "12345678901", "0");

    int index = findUserById(table, "20230321003");
    if (index != -1) {
        printf("User found: %s\n", table.userTable[index].username);
    }

    table = deleteUserByUsername(table, "文妙珍");

    table = modifyUserById(table, "20230321005", "20230321031", "赤笑雯", "18832221723", "0");

    saveFile(table, "user_updated.csv");

    return 0;
}

