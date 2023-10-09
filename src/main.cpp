/* Win it's a program that is designed to be a pratical and 
 * quickly method to save, change and delete data of clients
 * of a determinated service
 *
 * Author: Gabriel Felipe
 * Github: https://github.com/gabrielfelipeassuncaodesouza
 * Email: gabrielfelipeassuncaodesouza@gmail.com
 */

#include "client_class.h"
#include "client_list.h"
#include "globconst.h"

#include <iostream>
#include <stdbool.h>

config_t application;
ClientList list;

/* This functions are responsable to control de flux of the
 * program and switch to the different ways of the application
 */

std::string readCommand(void) {
	std::string ret;
	if(!application.isProcessing)
		std::cout << "\033[32mwin@user#> \033[m";
	std::cin >> ret;

	return ret;
}

void handle(std::string arg) {
	application.isProcessing = true;

	if(!isValid(arg)) return;

	if(application.addMode == ON) {
		addClient(arg);
	}

	if(application.sMode == ON)
		addService(arg);

	if(arg == "add")
		application.addMode = ON;

	if(arg == "list") 
		printClients();

	if(arg == "service")
		application.sMode = ON;
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
	application.sMode = OFF;
	application.isProcessing = false;
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
		arg = readCommand();
		handle(arg);
	} while(arg != "exit");
	return 0;
}