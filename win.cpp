/* 
 * Win it's a program that is designed to be a pratical and 
 * quickly method to save, change and delete data of clients
 * of a determinated service
 *
 * Author: Gabriel Felipe
 * Github: https://github.com/gabrielfelipeassuncaodesouza
 * Email: gabrielfelipeassuncaodesouza@gmail.com
 *
 */

#include <iostream>
#include <stdbool.h>

/*
 * Here it's a configuration of the system
 */

enum modes {
	OFF = 0,
	ON
};

typedef struct Config {
	int addMode;
	bool finishedEdit;
} Config;

Config application;

/* Here it's defined the class Client who contains all
 * informations about the client. So, all operations with
 * dates and more else will be done here
 */

class Client {
	public:
		std::string getName();
		std::string getService();
		void setName(std::string name);
		void setService(std::string service);
		int isFull();
	private:
		std::string name;
		std::string service;
		std::string dateOfPayment;
};

std::string Client::getName() {
	return this->name;
}
	
std::string Client::getService() {
	return this->service;
}

void Client::setName(std::string name) {
	this->name = name;
}

void Client::setService(std::string service) {
	this->service = service;
}

bool Client::isFull() {
	return this->service.size() != 0 && this->name.size() != 0;
}

typedef struct ClientNode {
	Client client;
	ClientNode* next;
} ClientNode;

typedef struct ClientList {
	ClientNode* head;
	ClientNode* tail;
} ClientList;

ClientList list;

void addClient(std::string name) {
	if(!application.finishedEdit) {
		std::cout << "[!] First you need to complete this client" << std::endl;
		return;
	}

	Client client;
	client.setName(name);
	ClientNode* novo = new ClientNode();
	novo->client = client;

	if(list.head == NULL) {
		novo->next = NULL;
		list.head = novo;
		list.tail = novo;
	}

	else
	{
		list.tail->next = novo;
		list.tail = novo;
		list.tail->next = NULL;
	}

	std::cout << "\n[*] Client " << name << " added!" << std::endl;
	application.addMode = OFF;
}

void printClients() {

	if(list.head == NULL) {
		std::cout << "[!] No clients in the list" << std::endl;
		return;
	}

	ClientNode* aux = list.head;
	while(aux != NULL) {
		std::cout << "\nName: " << aux->client.getName() << std::endl;
		std::cout << "Service: " << aux->client.getService() << std::endl;
		std::cout << "Length: " << aux->client.isFull() << std::endl;

		aux = aux->next;
	}
}


/* These are auxiliar functions created to do the tasks in a 
 * quickly way
 *

bool stringContains(std::string text, std::string word) {
	bool achou = false;
	int i, j;
	for(i = 0; i < text.size(); i++) {
		std::cout << i << std::endl;
	}
	return achou;
}

 * This functions are responsable to control de flux of the
 * program and switch to the different ways of the application
 */

void readCommand(std::string *arg) {
	std::cout << "\033[32mwin@user#> \033[m";
	std::cin >> *arg;
}

void handle(std::string arg) {
	if(application.addMode == ON) {
		addClient(arg);
	}
	std::cout << arg << std::endl;
	//stringContains(arg, "oi");
	if(arg == "add") {
		std::cout << "\nSay to me who you want to add\n";
		application.addMode = ON;
	}

	if(arg == "list") 
		printClients();

	if(arg == "service")
		std::cout << "\nI'll fix it\n";
}

/* This functions below do the initialization of the program
 *
 * The function init sets the pointers head and tail of the
 * list to NULL value
 *
 * The function printWelcomeMessage shows to the user a manual about how to use them
 *
 */

void init() {
	list.head = NULL;
	list.tail = NULL;
	application.addMode = OFF;
	application.finishedEdit = true;
}

void printWelcomeMessage() {
	std::cout << "Welcome to Win!" << std::endl;
	std::cout << "\nOfficial repository:       https://github.com/gabrielfelipeassuncaodesouza/win/" << std::endl;
	std::cout << "\nHow it works? " << std::endl;
	std::cout << "\n - Add a new client:	win -a -n <Name> -s <Service>" << std::endl;
	std::cout << " - List all clients:	win -l" << std::endl;
	std::cout << " - Deletes a client: win -b <client>" << std::endl;
	std::cout << "\nFor more information, type win --help:" << std::endl;
}

int main(int argc, char** argv) {
	//std::cout << "argc: " << argc << "argv: "<< argv[1];
	init();
	printWelcomeMessage();
	std::string arg;
	do {
		readCommand(&arg);
		handle(arg);
	} while(arg != "exit");
	return 0;
}
