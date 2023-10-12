#include "client_list.h"
#include "globconst.h"

void addClient(std::string name) {

	Client client;
	client.setName(name);
	ClientNode* novo = new ClientNode();
	novo->client = client;

	if(l.head == NULL) {
		novo->next = NULL;
		l.head = novo;
		l.tail = novo;
	}
	else
	{
		l.tail->next = novo;
		l.tail = novo;
		l.tail->next = NULL;
	}

	application.isProcessing = true;
	std::cout << "[*] Client " << name << " added!" << std::endl;
	application.addMode = OFF;
	application.isProcessing = false;

	if(!client.isFull()) {
		application.finishedEdit = false;
		return;
	}

	application.finishedEdit = true;
}

void addService(std::string service) {
	if(isEmpty()) return;

	l.tail->client.setService(service);
	std::string name = l.tail->client.getName();
	std::cout << "[*] Service of " << name << " updated to " << service << std::endl;

	application.sMode = OFF;
	application.isProcessing = false;
	if(!l.tail->client.isFull()) {
		application.finishedEdit = false;
		return;
	}
	application.finishedEdit = true;

}

void printClients(void) {
	if(isEmpty()) return;

	ClientNode* aux = l.head;
	while(aux != NULL) {
		std::cout << "\nName: " << aux->client.getName() << std::endl;
		std::cout << "Service: " << aux->client.getService() << std::endl;

		aux = aux->next;
	}
	application.isProcessing = false;
}

bool isEmpty(void) {
	if(l.head == NULL) {
		std::cout << "[!] No clients" << std::endl;
		application.isProcessing = false;
		return true;
	}
	return false;
}

bool isValid(std::string arg) {
	//std::cout << "Comand analized: " << arg << std::endl;
	//std::cout << "Size: " << arg.size() << std::endl;

	if((arg != "add" && arg != "service" &&
	arg != "list") && (application.sMode == OFF &&
		application.addMode == OFF)) {
		std::cout << "[!] Invalid command\n";
		application.isProcessing = false;
		return false;
	}
	return true;
}
