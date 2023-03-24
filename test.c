//
// Created by izumi on 2023/3/24.
//

#include "reader_information/readers.h"
#include <stdio.h>

int main(){
    ReadersTable r_table = initReadersTable();
    r_table = readReadersTableFromFile(r_table, "../data/readers.csv");
    printf("%s \n", r_table.readersTable[1].contact);

    return 0;
}
