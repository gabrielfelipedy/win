/* Win it's a program that is designed to be a pratical and 
 * quickly method to save, change and delete data of clients
 * of a determinated service
 *
 * Author: Gabriel Felipe
 * Github: https://github.com/gabrielfelipeassuncaodesouza
 * Email: gabrielfelipeassuncaodesouza@gmail.com
 */
#include "actions.h"
#include "client_class.h"
#include "client_list.h"
#include "globconst.h"

#include <cstdbool>
#include <cstring>
#include <sstream>
#include <iostream>
#include <vector>

config_t application;
ClientList l;

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
	l.head = NULL;
	l.tail = NULL;
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
	if(args.size() == 0) return 1;

	for(int i = 0; i < num_bultins(); i++) {
		if(args.front().compare(bultin_str[i]) == 0) {
			return (*bultin_func[i])(args);
		}
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
