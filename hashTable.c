#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedList.h"


typedef struct HashTable HashTable;

struct HashTable {
	int size;
	LinkedList **table;
};

HashTable *HashTable_new(int size) {
	HashTable *hash = malloc(sizeof(HashTable));
	hash->size = size;
	
	LinkedList **table = malloc(size * sizeof(LinkedList *));
	hash->table = table;
	return hash;
};

int hashFuncton(int size, int key) {
	return key % size;
};

LinkedList *getHashList(HashTable *hash, int codClient) {
	int tableIndex = hashFuncton(hash->size, codClient);
	return hash->table[tableIndex];
};

void hashTable_insert(HashTable *hash, int codClient, char *name) {;

	LinkedList *indexedList = getHashList(hash, codClient); 
	
	Node *nodeToBeInserted = createClientNode(codClient, name);

	if (indexedList == NULL) {
		int tableIndex = hashFuncton(hash->size, codClient);
		hash->table[tableIndex] = malloc(sizeof(LinkedList));
		indexedList = hash->table[tableIndex];
	};

	list_insertNode(indexedList, nodeToBeInserted); 
};

Client *hashTable_get(HashTable *hash, int codClient) {
	LinkedList *indexedList = getHashList(hash, codClient); 

	Client *client = list_findClientByCod(indexedList, codClient);
	
	if (client == NULL) {
		printf("Couldn't find client %d\n", codClient);
		return client;
	};

	return client;
};

void hashTable_delete(HashTable *hash, int codClient) {
	LinkedList *indexedList = getHashList(hash, codClient); 

	Client *client = list_findClientByCod(indexedList, codClient);

	list_delete(indexedList, codClient);
	
};
