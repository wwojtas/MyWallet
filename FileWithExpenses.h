#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithExpenses {

    vector<Expense> expenses;
    const string NAME_OF_FILE_WITH_EXPENSES;
    int lastExpenseId;
    string getNameOfFileWithExpenses();

public:
    FileWithExpenses(string nameOfFileWithExpenses)
        : NAME_OF_FILE_WITH_EXPENSES( nameOfFileWithExpenses ) {
        lastExpenseId = 0;
    };
    vector <Expense> loadExpensesFromFile( int loggedInUserId );
    void addExpenseToFileWithExpense( Expense newExpense );
    int getIdOfLastExpense();
};

#endif

