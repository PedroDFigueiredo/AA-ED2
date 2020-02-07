#ifndef FILEMANAGER_H_   /* Include guard */
#define FILEMANAGER_H_

#include "hashTable.h"

void hashTable_fm_write(HashTable *hash, char *hashFile, char *clientsFile);

HashTable *hashTable_fm_read(char *hashFile, char *clientsFile);


#endif // FILEMANAGER_H_
