#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <math.h>

#include "FileWithIncome.h"
#include "AuxiliaryMethods.h"
#include "DateManager.h"
#include "Income.h"
#include "Menu.h"

using namespace std;

class IncomeManager {

    DateManager dateManager;
    FileWithIncome fileWithIncome;
    vector<Income> incomes;
    vector<Income> selectedIncome;
    const int LOGGED_IN_USER_ID;

public:
    IncomeManager( string nameOfFileWithIncome, int loggedInUserId )
        : fileWithIncome( nameOfFileWithIncome )
        , LOGGED_IN_USER_ID( loggedInUserId ) {
        incomes = fileWithIncome.loadIncomeFromFile( LOGGED_IN_USER_ID);
    };

    Income enterNewIncome();
    void addIncome();
    float sumOfIncomeFromSelectedPeriod( int startDate, int endDate );
    void displayIncomeFromSelectedPeriod( int startDate, int endDate );
};

#endif
