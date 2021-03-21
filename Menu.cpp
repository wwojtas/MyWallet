#include "Menu.h"

char Menu::selectOptionsFromMainMenu() {

    char choice;

    clearScreen();
    cout << " ===== MAIN MENU ===== " << endl;
    cout << " --------------------------- " << endl;
    cout << "\t 1. Registration" << endl;
    cout << "\t 2. Login" << endl;
    cout << "\t 9. End of program" << endl;
    cout << " --------------------------- " << endl;
    cout << "\n ==== Your choice: ";

    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

char Menu::selectOptionsFromUserMenu() {

    char choice;

    clearScreen();
    cout << " ===== USER MENU ===== " << endl;
    cout << " --------------------------- " << endl;
    cout << "1. Add Income" << endl;
    cout << "2. Add Expense" << endl;
    cout << "3. Balance sheet from curent month" << endl;
    cout << "4. Balance sheet from last month" << endl;
    cout << "5. Balance sheet for the selected period" << endl;
    cout << " --------------------------- " << endl;
    cout << "6. Change password" << endl;
    cout << "0. Log out" << endl;
    cout << " --------------------------- " << endl;
    cout << "\n ==== Your choice: ";

    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

void Menu::clearScreen() {

    HANDLE console = GetStdHandle( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo( console, & csbi );
    DWORD tmp;
    COORD start = { 0, 0 };
    FillConsoleOutputCharacterA( console, ' ', csbi.dwSize.X * csbi.dwSize.Y, start, & tmp );
    FillConsoleOutputAttribute( console, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, start, & tmp );
    SetConsoleCursorPosition( console, start );
}
