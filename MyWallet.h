#ifndef MYWALLET_H
#define MYWALLET_H

#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpensesManager.h"
#include "Menu.h"

using namespace std;

class MyWallet :protected DateManager {

    UserManager userManager;
    IncomeManager* incomeManager;
    ExpensesManager* expensesManager;

    const string NAME_OF_FILE_WITH_INCOME;
    const string NAME_OF_FILE_WITH_EXPENSES;

public:
    MyWallet( string nameOfFileWithUsers, string nameOfFileWithIncome, string nameOfFileWithExpenses )
        : userManager( nameOfFileWithUsers )
        , NAME_OF_FILE_WITH_INCOME( nameOfFileWithIncome )
        , NAME_OF_FILE_WITH_EXPENSES ( nameOfFileWithExpenses ) {
        incomeManager = NULL;
        expensesManager = NULL;
    }
    ~MyWallet() {
        delete incomeManager;
        incomeManager = NULL;
        delete expensesManager;
        expensesManager = NULL;
    }
    int getLoggedInUserID();
    void registrationUser();
    void loggingUser();
    void changingPasswordOfLoggedInUser();
    void logoutUser();
    char selectOptionsFromMainMenu();
    char selectOptionsFromUserMenu();
    void addIncome();
    void addExpense();
    void displayBalanceOfCurrentMonth();
    void displayBalancePreviousMonth();
    void displayBalanceOfSelectedPeriod();
    void displayBalance();
};

#endif
