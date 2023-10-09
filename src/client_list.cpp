#include "client_list.h"
#include "globconst.h"

void addClient(std::string name) {
	if(!application.finishedEdit) {
		std::cout << "[!] First you need to complete this client" << std::endl;
		application.addMode = OFF;
		application.isProcessing = false;
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

	list.tail->client.setService(service);
	std::string name = list.tail->client.getName();
	std::cout << "[*] Service of " << name << "updated to " << service << std::endl;

	application.sMode = OFF;
	application.isProcessing = false;
	if(!list.tail->client.isFull()) {
		application.finishedEdit = false;
		return;
	}
	application.finishedEdit = true;

}

void printClients(void) {
	if(isEmpty()) return;

	ClientNode* aux = list.head;
	while(aux != NULL) {
		std::cout << "\nName: " << aux->client.getName() << std::endl;
		std::cout << "Service: " << aux->client.getService() << std::endl;

		aux = aux->next;
	}
	application.isProcessing = false;
}

bool isEmpty(void) {
	if(list.head == NULL) {
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