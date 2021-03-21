#ifndef FILEWITHINCOME_H
#define FILEWITHINCOME_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "Income.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncome {

    vector<Income> incomes;
    const string NAME_OF_FILE_WITH_INCOME;
    int lastIncomeId;
    string getNameOfIncomeFile();

public:
    FileWithIncome( string nameOfFileWithIncome )
        : NAME_OF_FILE_WITH_INCOME( nameOfFileWithIncome ) {
        lastIncomeId = 0;
    };
    vector <Income> loadIncomeFromFile( int loggedInUserId );
    void addIncomeToFileWithIncome( Income newIncome );
    int getIdOfLastIncome();
};

#endif
