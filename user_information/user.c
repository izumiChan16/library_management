#include "user.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define USERS_FILE "users.csv"

typedef struct {
    char name[MAX_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int is_admin;
} User;

User users[MAX_USERS];
int num_nums = 0;

// Function to load users from file
void loadUsers() {
    FILE *fp = fopen(USERS_FILE, "r");
    if (fp != NULL) {
        char line[100];
        while (fgets(line, sizeof(line), fp) != NULL) {
            char *token;
            token = strtok(line, ",");
            strcpy(users[num_nums].name, token);
            token = strtok(NULL, ",");
            strcpy(users[num_nums].password, token);
            token = strtok(NULL, ",");
            users[num_nums].is_admin = atoi(token);
            num_nums++;
        }
        fclose(fp);
    }
}

// Function to save users to file
void saveUsers() {
    FILE *fp = fopen(USERS_FILE, "w");
    if (fp != NULL) {
        for (int i = 0; i < num_nums; i++) {
            fprintf(fp, "%s,%s,%d\n", users[i].name, users[i].password, users[i].is_admin);
        }
        fclose(fp);
    }
}

// Function to add a new user
void addUser(char *name, char *password, int is_admin) {
    User new_user;
    strcpy(new_user.name, name);
    strcpy(new_user.password, password);
    new_user.is_admin = is_admin;
    users[num_nums++] = new_user;
    saveUsers();
}

// Function to find a user by name and return their index
int findUser(char *name) {
    for (int i = 0; i < num_nums; i++) {
        if (strcmp(users[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to check if a password is correct
int checkPassword(char *name, char *password) {
    int user_index = findUser(name);
    if (user_index >= 0 && strcmp(users[user_index].password, password) == 0) {
        return 1;
    }
    return 0;
}

// Function to check if a user is an admin
int is_admin(char *name) {
    int user_index = findUser(name);
    if (user_index >= 0 && users[user_index].is_admin == 1) {
        return 1;
    }
    return 0;
}
