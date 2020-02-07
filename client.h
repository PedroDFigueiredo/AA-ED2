#ifndef CLIENT_H_   /* Include guard */
#define CLIENT_H_

typedef struct Client Client;

struct Client {
	char *name;
	int codClient;
};

Client *Client_new(char *name, int codClient);

void client_fm_write(Client *client, FILE *out);

Client *client_fm_read(FILE *in);

#endif // CLIENT_H_