#ifndef HASTABLE_H_   /* Include guard */
#define HASTABLE_H_
#include "linkedList.h"

typedef struct HashTable HashTable;

struct HashTable {
	int size;
	LinkedList **table;
};

HashTable *HashTable_new(int size);

void hashTable_insert(HashTable *hash, int codClient, char *name);

void hashTable_delete(HashTable *hash, int codClient);

Client *hashTable_get(HashTable *hash, int codClient);


#endif // HASTABLE_H_
