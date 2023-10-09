#ifndef _H_ACTIONS
#define _H_ACTIONS

#include <iostream>

int list(void);
int exit(void);

#define QTDE_BUTILS 2

std::string bultin_str[] = {
    "list",
    "exit"
};

int (*bultin_func[]) (void) = {
    &list,
    &exit
};

#endif