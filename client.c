#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Client Client;

struct Client {
	char *name;
	int codClient;
};


Client *Client_new(char *name, int codClient) {
	Client *client = malloc(sizeof(Client));
	client->name = name;
	client->codClient = codClient;
	return client;
};


void client_write(Client *client, FILE *out) {
	fwrite(&client->codClient, sizeof(int), 1, out);
	fwrite(client->name,  sizeof(char), sizeof(client->name), out);
};

Client *client_read(FILE *in) {
	char *name = malloc(sizeof(char) * 100);  ;
	int codClient;
	fread(&codClient, sizeof(int), 1, in);
	fread(name, sizeof(char), sizeof(name), in);
	printf("Name: %s \tCodClient: %d\n", name, codClient);

	return Client_new(name, codClient);
};