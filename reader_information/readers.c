//
// Created by izumi on 2023/3/24.
//
#include "readers.h"
#include <stdio.h>
#include <string.h>

ReadersTable initReadersTable(){
    ReadersTable table;
    table.readersCount = 0;
    return table;
}

ReadersTable readReadersTableFromFile(ReadersTable table, const char *filename){
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        return table;
    }
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%s\n",
                  table.readersTable[table.readersCount].userid,
                  table.readersTable[table.readersCount].username,
                  table.readersTable[table.readersCount].contact,
                  table.readersTable[table.readersCount].membership_type,
                  table.readersTable[table.readersCount].membership_expiration_date,
                  table.readersTable[table.readersCount].date_created,
                  table.readersTable[table.readersCount].last_updated) != EOF) {
        table.readersCount++;
    }

    fclose(file);
    return table;
}

ReadersTable addReader(
        ReadersTable table,
        const char *userid, const char *username,
        const char *contact, const char *membership_type,
        const char  *membership_expiration_date, const char *date_created,
        const char  *last_updated
){
    ReadersInfo reader;
    strcpy(reader.userid, userid);
    strcpy(reader.username, username);
    strcpy(reader.contact, contact);
    strcpy(reader.membership_type, membership_type);
    strcpy(reader.membership_expiration_date, membership_expiration_date);
    strcpy(reader.date_created, date_created);
    strcpy(reader.last_updated, last_updated);

    table.readersTable[table.readersCount] = reader;
    table.readersCount++;
    return table;
}