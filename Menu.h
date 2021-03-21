#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <windows.h>

#include "AuxiliaryMethods.h"

using namespace std;

class Menu {

public:

    static char selectOptionsFromMainMenu();
    static char selectOptionsFromUserMenu();
    static void clearScreen();
};

#endif
