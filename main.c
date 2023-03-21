#include "user.h"
#include "stdio.h"

int main() {
    loadUsers();

    printf("%d", findUser("Jane"));
    return 0;
}

