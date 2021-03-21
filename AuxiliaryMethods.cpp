#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntegerToString( int number ) {

    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInteger( string number ) {

    int numberInt;
    istringstream iss( number );
    iss >> numberInt;
    return numberInt;
}

string AuxiliaryMethods::convertFloatToString( float number ) {

    stringstream floatPerString ;
    floatPerString  << number;
    string str = floatPerString .str();
    return str;
}

string AuxiliaryMethods::loadLines() {

    string enter = "";
    cin.sync();
    getline( cin, enter );
    return enter;
}

string AuxiliaryMethods::replaceCommaWithDotInStringNumber ( string numberString ) {

    for ( int i = 0; i < numberString.size(); i++ ) {
        if( numberString[i] == 44 ) numberString[i] = 46;
    }
    return numberString;
}

bool AuxiliaryMethods::checkAmountIsCorrect( string numberString ) {

    for( int i = 0; i < numberString.size(); i++ ) {
        if( ( numberString[i] < 48  || numberString[i] > 57 ) && ( numberString[i] != 46 ) && ( numberString[i] != 44 ) ) {
            cout << "An invalid value was entered. Please re-enter: ";
            return 0;
        } else return 1;
    }
}

string AuxiliaryMethods::replaceFirstLetterToUppercaseAndAllOthersToLowercase( string text ) {

    if ( !text.empty() ) {
        transform( text.begin(), text.end(), text.begin(), ::tolower );
        text[0] = toupper(text[0]);
    }
    return text;
}

char AuxiliaryMethods::loadCharacter() {

    string enter = "";
    char sign  = {0};
    while ( true ) {
        getline( cin, enter );
        if ( enter.length() == 1 ) {
            sign = enter[0];
            break;
        }
        cout << "This is not a single character. Type again." << endl;
    }
    return sign;
}

int AuxiliaryMethods::loadInteger() {

    string enter = "";
    int number = 0;
    while ( true ) {
        getline(cin, enter);
        stringstream myStream( enter );
        if ( myStream >> number )
            break;
        cout << "This is not a number. Type again. " << endl;
    }
    return number;
}
