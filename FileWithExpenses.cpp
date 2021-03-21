#include "FileWithExpenses.h"

string FileWithExpenses::getNameOfFileWithExpenses() {

    return NAME_OF_FILE_WITH_EXPENSES;
}

void FileWithExpenses::addExpenseToFileWithExpense( Expense expense ) {
    CMarkup xml;

    bool fileExists = xml.Load( getNameOfFileWithExpenses() );

    if ( !fileExists ) {
        xml.SetDoc( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n" );
        xml.AddElem( "Expenses" );
    }
    xml.FindElem( "Expenses" );
    xml.IntoElem();
    xml.AddElem( "Expense" );
    xml.IntoElem();
    xml.AddElem( "expenseId", expense.getExpenseId() );
    xml.AddElem( "userId", expense.getUserId() );
    xml.AddElem( "date", expense.getDate() );
    xml.AddElem( "item", expense.getItem() );
    xml.AddElem( "amount", AuxiliaryMethods::convertFloatToString(expense.getAmount()) );

    if ( xml.Save( getNameOfFileWithExpenses() )) {
        cout << "The income has been added to the file" << endl;
    } else {
        cout << "Error. Expense not entered in file" << endl;
    }
    lastExpenseId++;
}

vector <Expense> FileWithExpenses::loadExpensesFromFile( int loggedInUserId ) {

    CMarkup xml;
    Expense expense;
    vector <Expense> expenses;
    int userIdInFile = 0;
    bool fileExists = xml.Load( getNameOfFileWithExpenses() );

    if ( fileExists ) {

        xml.FindElem( "Expenses" );
        xml.IntoElem();
        while( xml.FindElem( "Expense" )) {

            xml.IntoElem();
            xml.FindElem( "userId" );
            userIdInFile = atoi(xml.GetData().c_str());

            if( userIdInFile == loggedInUserId ) {
                xml.FindElem( "expenseId" );
                expense.setExpenseId( atoi( xml.GetData().c_str() ) );
                xml.FindElem( "userId" );
                expense.setUserId( userIdInFile );
                xml.FindElem( "date" );
                expense.setDate( atoi( xml.GetData().c_str() ) );
                xml.FindElem( "item" );
                expense.setItem( xml.GetData());
                xml.FindElem( "amount" );
                expense.setAmount( atof( xml.GetData().c_str() ) );

                expenses.push_back( expense );
            }
            xml.OutOfElem();
            lastExpenseId++;
        }
    }
    return expenses;
}

int FileWithExpenses::getIdOfLastExpense() {
    return lastExpenseId;
}
