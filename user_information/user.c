#include "user.h"
#include <stdio.h>
#include <string.h>

UserTable initUserTable() {
    UserTable table;
    table.userCount = 0;
    return table;
}

UserTable readFile(UserTable table, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return table;
    }



    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%s\n",
                  table.userTable[table.userCount].userid,
                  table.userTable[table.userCount].password,
                  table.userTable[table.userCount].username,
                  table.userTable[table.userCount].contact,
                  table.userTable[table.userCount].is_admin) != EOF) {
        table.userCount++;
    }

    fclose(file);
    return table;
}

UserTable addUser(UserTable table, const char *userid, const char *password, const char *username, const char *contact, const char *is_admin) {
    strcpy(table.userTable[table.userCount].userid, userid);
    strcpy(table.userTable[table.userCount].password, password);
    strcpy(table.userTable[table.userCount].username, username);
    strcpy(table.userTable[table.userCount].contact, contact);
    strcpy(table.userTable[table.userCount].is_admin, is_admin);
    table.userCount++;
    return table;
}

int findUserById(UserTable table, const char *userid) {
    for (int i = 0; i < table.userCount; i++) {
        if (strcmp(table.userTable[i].userid, userid) == 0) {
            return i;
        }
    }
    return -1;
}

int findUserByUsername(UserTable table, const char *username) {
    for (int i = 0; i < table.userCount; i++) {
        if (strcmp(table.userTable[i].username, username) == 0) {
            return i;
        }
    }
    return -1;
}

UserTable deleteUserById(UserTable table, const char *userid) {
    int index = findUserById(table, userid);
    if (index != -1) {
        for (int i = index; i < table.userCount - 1; i++) {
            table.userTable[i] = table.userTable[i + 1];
        }
        table.userCount--;
    }
    return table;
}

UserTable deleteUserByUsername(UserTable table, const char *username) {
    int index = findUserByUsername(table, username);
    if (index != -1) {
        for (int i = index; i < table.userCount - 1; i++) {
            table.userTable[i] = table.userTable[i + 1];
        }
        table.userCount--;
    }
    return table;
}

UserTable modifyUserById(UserTable table, const char *userid, const char *newPassword, const char *newUsername, const char *newContact, const char *newIsAdmin) {
    int index = findUserById(table, userid);
    if (index != -1) {
        printf("hello");
        strcpy(table.userTable[index].password, newPassword);
        strcpy(table.userTable[index].username, newUsername);
        strcpy(table.userTable[index].contact, newContact);
        strcpy(table.userTable[index].is_admin, newIsAdmin);
    }
    return table;
}

UserTable modifyUserByUsername(UserTable table, const char *username, const char *newPassword, const char *newUserId, const char *newContact, const char *newIsAdmin) {
    int index = findUserByUsername(table, username);
    if (index != -1) {
        strcpy(table.userTable[index].password, newPassword);
        strcpy(table.userTable[index].userid, newUserId);
        strcpy(table.userTable[index].contact, newContact);
        strcpy(table.userTable[index].is_admin, newIsAdmin);
    }
    return table;
}

void saveFile(UserTable table, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = 0; i < table.userCount; i++) {
        fprintf(file, "%s,%s,%s,%s,%s\n",
                table.userTable[i].userid,
                table.userTable[i].password,
                table.userTable[i].username,
                table.userTable[i].contact,
                table.userTable[i].is_admin);
    }

    fclose(file);
}

