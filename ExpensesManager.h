#ifndef EXPENSESMANAGER_H
#define EXPENSESMANAGER_H

#include <iostream>
#include <vector>
#include <math.h>

#include "FileWithExpenses.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"
#include "Expense.h"
#include "Menu.h"

using namespace std;

class ExpensesManager {

    DateManager dateManager;
    FileWithExpenses fileWithExpenses;
    vector<Expense> expenses;
    vector<Expense> selectedExpenses;
    const int LOGGED_IN_USER_ID;

public:
    ExpensesManager( string nameOfFileWithExpenses, int loggedInUserId )
        : fileWithExpenses( nameOfFileWithExpenses )
        , LOGGED_IN_USER_ID( loggedInUserId ) {
        expenses = fileWithExpenses.loadExpensesFromFile( loggedInUserId);
    };
    void addExpense();
    Expense enterNewExpense();
    float sumOfExpensesFromSelectedPeriod( int startDate, int endDate );
    void displayExpensesFromSelectedPeriod( int startDate, int endDate );
};

#endif
