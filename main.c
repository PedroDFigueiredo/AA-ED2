
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashTable.h"

// todo remove this
// #include <conio.h>


int main(int argc, char** argv) {
	int size = 28;
	char *str[28] = {"a", "b", "c", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o",
	"a2", "b2", "c2", "e2", "f2", "g2", "h2", "i2", "j2", "k2", "l2", "m2", "n2", "o2"};

	HashTable *hashTable = HashTable_new(7);
	for (int i = 0; i <= size; i++) {
		hashTable_insert(hashTable, i, str[i]);
	};
	// srand(time(NULL));

	Client *client = hashTable_get(hashTable, 15);
	printf("Name: %s \tCodClient: %d\n", client->name, client->codClient);
	client = hashTable_get(hashTable, 16);
	printf("Name: %s \tCodClient: %d\n", client->name, client->codClient);
	client = hashTable_get(hashTable, 17);
	printf("Name: %s \tCodClient: %d\n", client->name, client->codClient);
	
	hashTable_delete(hashTable, 0);
	hashTable_get(hashTable, 23);


	FILE *out;

	if ((out = fopen("clientes.dat", "wb")) == NULL) {
		printf("Error opening the file\n");
		exit(1);
	};

	client_write(client, out);
	fclose(out);


	FILE *in;

	if ((in = fopen("clientes.dat", "rb")) == NULL) {
		printf("Error opening the file\n");
		exit(1);
	};


	Client *readClient = client_read(in);
	fclose(in);

	return 0;
};


/*
insert 0 7 0  indexedTable -> 0x8b84e0  ->  0x8b84e0 0x8b84c0 (nil)
insert 1 7 1  indexedTable -> 0x8b8540  ->  0x8b8540 0x8b8520 (nil)
insert 2 7 2  indexedTable -> 0x8b85a0  ->  0x8b85a0 0x8b8580 (nil)
insert 3 7 3  indexedTable -> 0x8b8600  ->  0x8b8600 0x8b85e0 (nil)
insert 4 7 4  indexedTable -> 0x8b8660  ->  0x8b8660 0x8b8640 (nil)
insert 5 7 5  indexedTable -> 0x8b86c0  ->  0x8b86c0 0x8b86a0 (nil)
insert 6 7 6  indexedTable -> 0x8b8720  ->  0x8b8720 0x8b8700 (nil)
insert 7 7 0  indexedTable -> 0x8b8780  ->  0x8b8780 0x8b8760 (nil)
insert 8 7 1  indexedTable -> 0x8b87e0  ->  0x8b87e0 0x8b87c0 (nil)
insert 9 7 2  indexedTable -> 0x8b8840  ->  0x8b8840 0x8b8820 (nil)
insert 10 7 3  indexedTable -> 0x8b88a0  ->  0x8b88a0 0x8b8880 (nil)
insert 11 7 4  indexedTable -> 0x8b8900  ->  0x8b8900 0x8b88e0 (nil)
insert 12 7 5  indexedTable -> 0x8b8960  ->  0x8b8960 0x8b8940 (nil)
*/