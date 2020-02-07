#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashTable.h"


void clients_fm_write(HashTable *hash, char *clientsFile) {
	FILE *clientFile_out;
	if ((clientFile_out = fopen(clientsFile, "wb")) == NULL) {
		printf("Error opening the CLIENT file\n");
		exit(1);
	};

	printf("Writing Clients ... \n");
	for (int i = 0; i < hash->size; i++ ) {
		LinkedList *list = hash->table[i]; 
		Node *node = list->head;

		for (int j = 0; j < list->size; j++ ) {
			client_fm_write(node->client, clientFile_out);
			node = node->next;
		};		
	};

	fclose(clientFile_out);
	printf("\n");
};


void hashTable_fm_write(HashTable *hash, char *hashFile, char *clientsFile) {
	clients_fm_write(hash, clientsFile);

	FILE *hashTableFile_out;
	if ((hashTableFile_out = fopen(hashFile, "wb")) == NULL) {
		printf("Error opening the HASH file\n");
		exit(1);
	};

	printf("Writing Hash Table ... \n");

	fwrite(&hash->size, sizeof(int), 1, hashTableFile_out);
	printf("hash size -> %d\n", hash->size);

	for (int i = 0; i < hash->size; i++ ) {
		LinkedList *list = hash->table[i]; 
		fwrite(&list->size, sizeof(int), 1, hashTableFile_out);
		printf("\tlist size %d\n", list->size);
	
		Node *node = list->head;

		for (int j = 0; j < list->size; j++ ) {
			printf("\t\tClient name: %s, codClient: %d\n",
				 node->client->name, node->client->codClient);
			fwrite(&node->client->codClient, sizeof(int), 1, hashTableFile_out);
			node = node->next;
		};		
	};

	fclose(hashTableFile_out);

};

Client *readClientByCod(char *clientsFile, int codClient) {
	FILE *in;

	if ((in = fopen(clientsFile, "rb")) == NULL) {
		printf("Error opening the file\n");
		exit(1);
	};

	char *name = malloc(sizeof(char) * 100);  ;
	int codClient_file;
	
	fread(&codClient_file, sizeof(int), 1, in);
	fread(name, sizeof(char), sizeof(name), in);

	if(codClient_file == codClient) {
		return Client_new(name, codClient);
	};


	while(codClient_file != NULL) {
		fread(&codClient_file, sizeof(int), 1, in);
		fread(name, sizeof(char), sizeof(name), in);

		if(codClient_file == codClient) {
			return Client_new(name, codClient);
		};		
	};

	return NULL;
};

HashTable *hashTable_fm_read(char *hashFile, char *clientsFile) {
	FILE *hashTableFile_out;

	if ((hashTableFile_out = fopen(hashFile, "rb")) == NULL) {
		printf("Error opening the HASH file\n");
		exit(1);
	};

	printf("Reading Hash Table ... \n");
	int hashSize;
	fread(&hashSize, sizeof(int), 1, hashTableFile_out);
	printf("hash size -> %d\n", hashSize);

	HashTable *hash = HashTable_new(hashSize);

	for (int i = 0; i < hash->size; i++ ) {
		int listSize;
		fread(&listSize, sizeof(int), 1, hashTableFile_out);
		printf("\tlist size %d\n", listSize);

		for (int j = 0; j < listSize; j++ ) {
			int codClient;
			fread(&codClient, sizeof(int), 1, hashTableFile_out);

			Client *client = readClientByCod(clientsFile, codClient);
			hashTable_insert(hash, codClient, client->name);
			printf("\t\tClient name: %s, codClient: %d \n",
				 client->name,codClient);
		};
	};

	return hash;
};

void client_fm_write(Client *client, FILE *out) {
	printf("Name: %s \tCodClient: %d\n", client->name, client->codClient);
	fwrite(&client->codClient, sizeof(int), 1, out);
	fwrite(client->name,  sizeof(char), sizeof(client->name), out);
};


Client *client_fm_read(FILE *in) {
	char *name = malloc(sizeof(char) * 100);  ;
	int codClient;
	fread(&codClient, sizeof(int), 1, in);
	fread(name, sizeof(char), sizeof(name), in);

	return Client_new(name, codClient);
};