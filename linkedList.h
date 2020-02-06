#ifndef LINKEDLIST_H_  
#define LINKEDLIST_H_
#include "client.h"

typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node {
	Client *client;
	Node *next;
};

Node *Node_new(Client *client, Node *next);

Node *createClientNode(int codClient, char *name);

struct LinkedList {
	Node *head;
};

LinkedList *LinkedList_new();

Node *list_getLastNode(LinkedList *list);

Client *list_findClientByCod(LinkedList *list, int codClient); 

void list_insertNode(LinkedList *list, Node *node);

void list_delete(LinkedList *list, int codClient);


#endif // LINKEDLIST_H_