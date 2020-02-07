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

