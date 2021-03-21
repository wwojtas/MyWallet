#include "MyWallet.h"

void MyWallet::registrationUser() {

    userManager.registrationUser();
}

int MyWallet::getLoggedInUserID() {

    userManager.getLoggedInUserID();
}
void MyWallet::loggingUser() {

    userManager.loggingUser();

    if(userManager.getLoggedInUserID() > 0) {
        expensesManager = new ExpensesManager(NAME_OF_FILE_WITH_EXPENSES, userManager.getLoggedInUserID());
        incomeManager = new IncomeManager(NAME_OF_FILE_WITH_INCOME, userManager.getLoggedInUserID());
    }
}

void MyWallet::changingPasswordOfLoggedInUser() {

    userManager.changingPasswordOfLoggedInUser();
}

void MyWallet::logoutUser() {

    userManager.logoutUser();

    delete incomeManager;
    incomeManager = NULL;
    delete expensesManager;
    expensesManager = NULL;
}

char MyWallet::selectOptionsFromMainMenu() {

    Menu::selectOptionsFromMainMenu();
}

char MyWallet::selectOptionsFromUserMenu() {

    Menu::selectOptionsFromUserMenu();
}

void MyWallet::addIncome() {

    if(userManager.getLoggedInUserID() > 0) {
        incomeManager -> addIncome();
    }
}

void MyWallet::addExpense() {

    if(userManager.getLoggedInUserID() > 0) {
        expensesManager -> addExpense();
    }
}

void MyWallet::displayBalanceOfCurrentMonth() {

    if(userManager.getLoggedInUserID() > 0) {
        setStartDate( getDateForFirstDayOfCurrentMonth() );
        setEndDate( getCurrentDateIntegerType() );

        displayBalance( );
    }
}

void MyWallet::displayBalancePreviousMonth() {

    if(userManager.getLoggedInUserID() > 0) {
        setStartDate( getDateForFirstDayOfPreviousMonth() );
        setEndDate( getDateForLastDayOfPreviousMonth() );

        displayBalance( );
    }
}

void MyWallet::displayBalanceOfSelectedPeriod() {

    if(userManager.getLoggedInUserID() > 0) {
        do {
            Menu::clearScreen();
            cout << "Balance sheet for the selected period. " << endl;
            cout << "Type the start date of the period: " << endl;
            setStartDate( typeDateAndChangeToInteger() );
            cout << "Type the end date of the period: " << endl;
            setEndDate( typeDateAndChangeToInteger() );
            if ( getStartDate() > getEndDate() ) cout << "Incorrectly stated date periods. Please enter again !" << endl;
        } while ( getStartDate() > getEndDate()  );
        displayBalance( );
    }
}

void MyWallet::displayBalance( ) {

    Menu::clearScreen();
    cout << "\n";
    cout << "Balance sheet for the period from: " << replaceDateWithStringSeparatedByDashes( getStartDate() ) << " to: " << replaceDateWithStringSeparatedByDashes( getEndDate() ) << endl;
    cout << "\n";
    cout << " ================== " << endl;
    cout << " ===  INCOME === " << endl;
    cout << " ================== " << endl;
    incomeManager->displayIncomeFromSelectedPeriod(  getStartDate(), getEndDate() );
    cout << "The sum of income = " << incomeManager->sumOfIncomeFromSelectedPeriod(  getStartDate(),  getEndDate() ) << endl;
    cout << "\n";
    cout << " ================== " << endl;
    cout << " ==== EXPENSES ===== " << endl;
    cout << " ================== " << endl;
    expensesManager->displayExpensesFromSelectedPeriod(  getStartDate(), getEndDate() );
    cout << "The sum of expenses = " << expensesManager->sumOfExpensesFromSelectedPeriod(  getStartDate(),  getEndDate() ) << endl;
    cout << "\n\n";
    cout << "The balance of income and expenses is determined by the difference (INCOME - EXPENSES)" << endl;
    cout << "The balance sheet is: " << ( incomeManager->sumOfIncomeFromSelectedPeriod(  getStartDate(),  getEndDate() )) - ( expensesManager->sumOfExpensesFromSelectedPeriod(  getStartDate(),  getEndDate() ) ) << endl;
    cout << "\n\n";
    system("pause");
}
