#include "FileWithIncome.h"

string FileWithIncome::getNameOfIncomeFile() {

    return NAME_OF_FILE_WITH_INCOME;
}

void FileWithIncome::addIncomeToFileWithIncome( Income income ) {
    CMarkup xml;

    bool fileExists = xml.Load( getNameOfIncomeFile() );

    if ( !fileExists ) {
        xml.SetDoc( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n" );
        xml.AddElem( "Incomes" );
    }
    xml.FindElem( "Incomes" );
    xml.IntoElem();
    xml.AddElem( "Income" );
    xml.IntoElem();
    xml.AddElem( "incomeId", income.getIncomeId() );
    xml.AddElem( "userId", income.getUserId() );
    xml.AddElem( "date", income.getDate() );
    xml.AddElem( "item", income.getItem() );
    xml.AddElem( "amount", AuxiliaryMethods::convertFloatToString( income.getAmount()) );

    if ( xml.Save( getNameOfIncomeFile() )) {
        cout << "The income has been added to the file" << endl;
    } else {
        cout << "Error. Income not entered in file" << endl;
    }
    lastIncomeId++;
}

vector <Income> FileWithIncome::loadIncomeFromFile( int loggedInUserId ) {

    CMarkup xml;
    Income income;
    vector <Income> incomes;
    int userIdInFile = 0;
    bool fileExists = xml.Load( getNameOfIncomeFile() );

    if ( fileExists ) {
        xml.FindElem( "Incomes" );
        xml.IntoElem();
        while( xml.FindElem( "Income" )) {
            xml.IntoElem();
            xml.FindElem( "userId" );
            userIdInFile = atoi(xml.GetData().c_str());
            if( userIdInFile == loggedInUserId ) {
                xml.FindElem( "incomeId" );
                income.setIncomeId( atoi( xml.GetData().c_str() ) );
                xml.FindElem( "userId" );
                income.setUserId( userIdInFile );
                xml.FindElem( "date" );
                income.setDate( atoi( xml.GetData().c_str() ) );
                xml.FindElem( "item" );
                income.setItem( xml.GetData());
                xml.FindElem( "amount" );
                income.setAmount( atof( xml.GetData().c_str() ) );

                incomes.push_back( income );
            }
            xml.OutOfElem();
            lastIncomeId++;
        }
    }
    return incomes;
}

int FileWithIncome::getIdOfLastIncome() {
    return lastIncomeId;
}
