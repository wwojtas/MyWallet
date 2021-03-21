#include <iostream>
#include "MyWallet.h"

using namespace std;

int main() {

    MyWallet myWallet( "users.xml", "incomes.xml", "expenses.xml" );

    char choice;

    while (true) {
        if ( myWallet.getLoggedInUserID() == 0 ) {

            choice = myWallet.selectOptionsFromMainMenu();

            switch (choice) {
            case '1':
                myWallet.registrationUser();
                break;
            case '2':
                myWallet.loggingUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in the menu" << endl << endl;
                system("pause");
                break;
            }
        } else if (myWallet.getLoggedInUserID() > 0) {

            choice = myWallet.selectOptionsFromUserMenu();

            switch (choice) {
            case '1':
                myWallet.addIncome();
                break;
            case '2':
                myWallet.addExpense();
                break;
            case '3':
                myWallet.displayBalanceOfCurrentMonth();
                break;
            case '4':
                myWallet.displayBalancePreviousMonth();
                break;
            case '5':
                myWallet.displayBalanceOfSelectedPeriod();
                break;
            case '6':
                myWallet.changingPasswordOfLoggedInUser();
                break;
            case '0':
                myWallet.logoutUser();
                break;
            }
        }
    }
    return 0;
}
