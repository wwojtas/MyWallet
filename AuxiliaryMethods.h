#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

class AuxiliaryMethods {

public:
    static string convertIntegerToString( int number );
    static int convertStringToInteger( string number );
    static char loadCharacter();
    static string replaceFirstLetterToUppercaseAndAllOthersToLowercase( string  );
    static string loadLines();
    static int loadInteger();
    static string replaceCommaWithDotInStringNumber ( string numberString );
    static bool checkAmountIsCorrect( string numberString );
    static string convertFloatToString( float number );
};

#endif
