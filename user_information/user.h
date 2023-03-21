#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

// Function to load users from file
void loadUsers();

// Function to save users to file
void saveUsers();

// Function to add a new user
void addUser(char *name, char *password, int isAdmin);

// Function to check if a password is correct
int checkPassword(char *name, char *password);

// Function to check if a user is an admin
int isAdmin(char *name);

// Function to find a user by name and return their index
int findUser(char *name);

#endif
