#include <iostream>

#include "client_list.h"
#include "globconst.h"

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

    if(args.size() >= 3) {
      std::vector<std::string> sub = { args.begin() + 2, args.end() };
      execute(sub);
    }

    return 1;
}

int service(std::vector<std::string> args) {
    std::cout << "you typed service" << std::endl;

    std::string service;

    if(args.size() < 2) {
        std::cout << "Type the name of the service: ";
        std::cin >> service;
        while(getchar() != '\n');
    }
    else service = args.at(1);

    addService(service);

    return 1;
}
