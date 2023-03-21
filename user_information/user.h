#ifndef USER_MANAGEMENT_H
#define USER_MANAGEMENT_H

#define MAX_NAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

// Function to load users from file
void readFile(const char *filename);

// Function to save users to file
int findUserById(const char *userid);
int findUserByUsername(const char *username);

// Function to add a new user
void addUser(const char *userid, const char *password, const char *username, const char *contact, int is_admin);

// Function to check if a password is correct


void deleteUserById(const char *userid);

void deleteUserByUsername(const char *username);

void modifyUserById(const char *userid, const char *newPassword, const char *newUsername, const char *newContact, int newIsAdmin);

void modifyUserByUsername(const char *username, const char *newPassword, const char *newUserId, const char *newContact, int newIsAdmin);

int is_admin(char *name);

#endif
