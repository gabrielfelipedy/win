#ifndef _H_ACTIONS
#define _H_ACTIONS

#include <iostream>
#include <vector>

int list(std::vector<std::string>);
int exit(std::vector<std::string>);
int add(std::vector<std::string>);
int service(std::vector<std::string>);
int clear(std::vector<std::string> args);

#define QTDE_BUTILS 4

std::string bultin_str[] = {
    "list",
    "exit",
    "add",
    "service",
    "clear"
};

int num_bultins(void) { return sizeof(bultin_str) / sizeof(std::string); }

int (*bultin_func[]) (std::vector<std::string>) = {
    &list,
    &exit,
    &add,
    &service,
    &clear
};

#endif