#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "client.h"


typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node {
	Client *client;
	Node *next;
};

Node *Node_new(Client *client, Node *next) {
	Node *node = malloc(sizeof(Node));
	node->client = client;
	node->next = next;
	return node;
};

Node *createClientNode(int codClient, char *name) {
	Client * client = Client_new(name, codClient);
	return Node_new(client, NULL);
};

struct LinkedList {
	Node *head;
};

LinkedList *LinkedList_new() {
	LinkedList *list = malloc(sizeof(LinkedList));
	return list;
};

Node *list_getLastNode(LinkedList *list) {
	Node *node = list->head;
	while (node != NULL && node->next != NULL) {
		node = node->next;
	}

	return node;
};

Node *list_findNodeByCodClient(LinkedList *list, int codClient) {
	Node *node = list->head;
	while (node != NULL && 
		   node->client->codClient != codClient) {
		node = node->next;
	};
	return node;
};

Client *list_findClientByCod(LinkedList *list, int codClient) {
	Node *node = list_findNodeByCodClient(list, codClient);
	if (node == NULL)
		return NULL;

	return node->client;
}; 

void list_insertNode(LinkedList *list, Node *node) {
	Node *lastNode = list_getLastNode(list);
	if (lastNode == NULL)
		list->head = node;
	else 
		lastNode->next = node;		
};

void list_delete(LinkedList *list, int codClient) { 
	Node *node = list->head;
	
	if (node->client->codClient == codClient) {
		list->head = node->next;
		free(node);
		return;
	};

	while (node != NULL && node->next != NULL ) {  
		if( node->next->client->codClient == codClient) {
			Node *nodeToDelete = node->next;
			node->next = nodeToDelete->next;
			free(nodeToDelete->client);
			free(nodeToDelete);
			return ;
		} else 
			node = node->next;
	};

};