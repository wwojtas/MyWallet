#include "IncomeManager.h"

void IncomeManager::addIncome() {

    Menu::clearScreen();
    cout << "ADD INCOME \n";
    Income income = enterNewIncome();
    incomes.push_back( income );
    fileWithIncome.addIncomeToFileWithIncome( income );

    cout << " Income entered " << endl << endl;
    system("pause");
}

Income IncomeManager::enterNewIncome() {

    Income income;
    string newItem = "";
    string numberString = "";
    float newAmount = 0;
    float number = 0;
    char choice;

    income.setUserId( LOGGED_IN_USER_ID );
    income.setIncomeId( fileWithIncome.getIdOfLastIncome()+1 );

    cout << endl << "Subject of income: ";
    newItem = AuxiliaryMethods::replaceFirstLetterToUppercaseAndAllOthersToLowercase( AuxiliaryMethods::loadLines() );
    income.setItem( newItem );

    cout << endl << "Value of income: ";
    do {
        numberString = AuxiliaryMethods::loadLines();
        numberString = AuxiliaryMethods::replaceCommaWithDotInStringNumber( numberString );
    } while( !AuxiliaryMethods::checkAmountIsCorrect( numberString ));
    number = atof( numberString.c_str() );
    newAmount = roundf( number*100)/100;
    income.setAmount( newAmount );

    cout << "\n ==== Date of income ==== " << endl;
    cout << "\ ==== t : if today" << endl;
    cout << "\ ==== another key: enter date" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadCharacter();

    if ( choice == 't' )
        income.setDate( dateManager.getCurrentDateIntegerType() );
    else {
        income.setDate( dateManager.typeDateAndChangeToInteger() );
    }
    return income;
}

float IncomeManager::sumOfIncomeFromSelectedPeriod( int startDate, int endDate ) {

    float sumOfIncome = 0;

    for (int i = 0; i < incomes.size(); i++) {
        if ( incomes[i].getUserId() == LOGGED_IN_USER_ID ) {
            if ( (incomes[i].getDate()>= startDate ) &&  ( incomes[i].getDate() <= endDate ) ) {
                sumOfIncome += incomes[i].getAmount();
            }
        }
    }
    return sumOfIncome;
}

void IncomeManager::displayIncomeFromSelectedPeriod( int startDate, int endDate ) {

    for (int i = 0; i < incomes.size(); i++) {
        if ( incomes[i].getUserId() == LOGGED_IN_USER_ID ) {
            if ( (incomes[i].getDate()>= startDate ) &&  ( incomes[i].getDate() <= endDate ) ) {
                selectedIncome.push_back(incomes[i]);
            }
        }
    }
    sort( selectedIncome.begin(), selectedIncome.end() );
    int counter = 0;
    for (int i = 0; i < selectedIncome.size(); i++ ) {
        counter++;
        cout << "Position: " << counter << endl;
        cout << "Date: " << dateManager.replaceDateWithStringSeparatedByDashes(selectedIncome[i].getDate()) << endl;
        cout << "Applies to: " << selectedIncome[i].getItem() << endl;
        cout << "Value: " << selectedIncome[i].getAmount() << endl;
        cout << " ----------------- " << endl;
    }
    selectedIncome.clear();
}
