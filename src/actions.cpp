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

int add(std::vector<std::string> args) {
    std::cout << "you typed add" << std::endl;
    return 1;
}

int service(std::vector<std::string> args) {
    std::cout << "you typed service" << std::endl;
    return 1;
}