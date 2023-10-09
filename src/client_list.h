#ifndef _H_CLIENT_L
#define _H_CLIENT_L

#include "client_class.h"

typedef struct ClientNode {
	Client client;
	ClientNode* next;
} ClientNode;

typedef struct ClientList {
	ClientNode* head;
	ClientNode* tail;
} ClientList;

extern ClientList l;

void addService(std::string service);
void addClient(std::string name);
void printClients(void);
bool isValid(std::string arg);
bool isEmpty(void);

#endif