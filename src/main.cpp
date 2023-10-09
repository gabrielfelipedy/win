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

#include <cstdbool>
#include <sstream>
#include <iostream>
#include <vector>

config_t application;
ClientList list;

/* This functions are responsable to control de flux of the
 * program and switch to the different ways of the application
 */

std::string readCommand(void) {
	std::string ret;
	if(!application.isProcessing)
		std::cout << "\033[32mwin@user#> \033[m";
	

	std::getline(std::cin, ret);

	return ret;
}


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

void splitLine(std::string line, std::vector<std::string>* list) {

	std::string token;
	std::istringstream f(line);

	while(std::getline(f, token, ' '))
		(*list).push_back(token);
}

int execute(std::vector<std::string> args) {
	if(args.front() == "exit") return 0;

	for(auto str : args) {
		std::cout << "str: " << str << std::endl;
		std::cout << "head: " << args.front() << std::endl;
	}

	return 1;
}

int main(int argc, char** argv) {
	//std::cout << "argc: " << argc << "argv: "<< argv[1];
	init();
	printWelcomeMessage();

	std::string line;
	std::vector<std::string> args;
	
	int status;

	do {
		args.clear();
		line = readCommand();
		splitLine(line, &args);
		status = execute(args);

	} while(status);

	return EXIT_SUCCESS;
}