#include <iostream>

#include "client_list.h"

#include <vector>

int list(std::vector<std::string> args) {
    std::cout << "you typed list" << std::endl;
    printClients();
    return 1;
}

int exit(std::vector<std::string> args) {
    std::cout << "you typed exit" << std::endl;
    return 0;
}

int clear(std::vector<std::string> args) {
    std::cout << "\x1b[2J\x1b[H";
    return 1;
}

int add(std::vector<std::string> args) {
    std::cout << "you typed add" << std::endl;

    std::string name;

    if(args.size() < 2) {
        std::cout << "Type the name of the client: ";
        std::cin >> name;
        while(getchar() != '\n');
    }
    else name = args.at(1);

    addClient(name);

    return 1;
}

int service(std::vector<std::string> args) {
    std::cout << "you typed service" << std::endl;
    return 1;
}