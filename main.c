#include "user_information/user.h"
#include "stdio.h"

int main() {
    loadUsers();

    printf("%d", findUser(""));
    return 0;
}

