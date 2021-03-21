#include "ExpensesManager.h"

void ExpensesManager::addExpense() {

    Menu::clearScreen();
    cout << "Add Expense \n";
    Expense expense = enterNewExpense();
    expenses.push_back( expense );
    fileWithExpenses.addExpenseToFileWithExpense( expense );

    cout << " Expense entered " << endl << endl;
    system("pause");
}

Expense ExpensesManager::enterNewExpense() {

    Expense expense;
    string newItem = "";
    string numberString = "";
    float newAmount = 0;
    float number  = 0;
    char choice;

    expense.setUserId( LOGGED_IN_USER_ID );
    expense.setExpenseId( fileWithExpenses.getIdOfLastExpense()+1 );

    cout << endl << "Subject of expense: ";
    newItem = AuxiliaryMethods::replaceFirstLetterToUppercaseAndAllOthersToLowercase( AuxiliaryMethods::loadLines() );
    expense.setItem( newItem );

    cout << endl << "Value of expense: ";
    do {
        numberString = AuxiliaryMethods::loadLines();
        numberString = AuxiliaryMethods::replaceCommaWithDotInStringNumber( numberString );
    } while( !AuxiliaryMethods::checkAmountIsCorrect( numberString ));
    number  = atof( numberString.c_str() );
    newAmount = roundf( number *100)/100;
    expense.setAmount( newAmount );

    cout << "\n ==== Date of expense ==== " << endl;
    cout << "\ ==== t : if today" << endl;
    cout << "\ ==== another key: enter date" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadCharacter();

    if ( choice == 't' )
        expense.setDate( dateManager.getCurrentDateIntegerType() );
    else {
        expense.setDate( dateManager.typeDateAndChangeToInteger() );
    }
    return expense;
}

float ExpensesManager::sumOfExpensesFromSelectedPeriod( int startDate, int endDate ) {

    float sumOfExpense = 0;

    for (int i = 0; i < expenses.size(); i++) {
        if ( expenses[i].getUserId() == LOGGED_IN_USER_ID ) {
            if ( (expenses[i].getDate()>= startDate ) &&  ( expenses[i].getDate() <= endDate ) ) {
                sumOfExpense += expenses[i].getAmount();
            }
        }
    }
    return sumOfExpense;
}

void ExpensesManager::displayExpensesFromSelectedPeriod( int startDate, int endDate ) {

    for (int i = 0; i < expenses.size(); i++) {
        if ( expenses[i].getUserId() == LOGGED_IN_USER_ID ) {
            if ( (expenses[i].getDate()>= startDate ) &&  ( expenses[i].getDate() <= endDate ) ) {
                selectedExpenses.push_back(expenses[i]);
            }
        }
    }
    sort( selectedExpenses.begin(), selectedExpenses.end() );
    int counter = 0;
    for (int i = 0; i < selectedExpenses.size(); i++ ) {
        counter++;
        cout << "Position: " << counter << endl;
        cout << "Date: " << dateManager.replaceDateWithStringSeparatedByDashes(selectedExpenses[i].getDate()) << endl;
        cout << "Applies to: " << selectedExpenses[i].getItem() << endl;
        cout << "Value: " << selectedExpenses[i].getAmount() << endl;
        cout << " ----------------- " << endl;
    }
    selectedExpenses.clear();
}
