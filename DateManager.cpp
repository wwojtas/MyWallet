#include "DateManager.h"


int DateManager::getCurrentYear() {

    time_t timeline = time( & timeline );
    struct tm * date;
    date = localtime( & timeline );
    int currentYear = ( date->tm_year + 1900 );

    return currentYear;
}

int DateManager::getCurrentMonth() {

    time_t timeline = time( & timeline );
    struct tm * date;
    date = localtime( & timeline );
    int currentMonth = ( date->tm_mon + 1 );

    return currentMonth;
}

int DateManager::getCurrentDay() {

    time_t timeline = time( & timeline );
    struct tm * date;
    date = localtime( & timeline );
    int currentDay = date->tm_mday;

    return currentDay;
}

int DateManager::getCurrentDateIntegerType() {

    string dateString = "";
    int dateInt = 0;
    dateString = replaceDateByString( getCurrentYear(), getCurrentMonth(), getCurrentDay() );
    dateInt = atoi(dateString.c_str());

    return dateInt;
}

int DateManager::enterYear() {

    int year = 0;
    do {
        cout << "Enter year: ";
        year = AuxiliaryMethods::loadInteger();
    } while ( isYearCorrect ( year ) == false );

    return year;
}

int DateManager::enterMonth() {

    int month = 0;
    do {
        cout << "Enter month: ";
        month = AuxiliaryMethods::loadInteger();
    } while ( isMonthCorrect( month ) == false );

    return month;
}

int DateManager::enterDay() {

    int day = 0;
    do {
        cout << "Enter day: ";
        day = AuxiliaryMethods::loadInteger();
    } while ( isDayCorrect( day ) == false );

    return day;
}

int DateManager::typeDateAndChangeToInteger() {

    string dateString = "";
    int dateInt = 0;
    dateString = replaceDateByString( enterYear(), enterMonth(), enterDay() );
    dateInt = atoi(dateString.c_str());

    return dateInt;
}

string DateManager::replaceDateByString( int year, int month, int day ) {

    string yearToString = replaceYearByString( year );
    string monthToString = replaceMonthByString( month );
    string dayToString = replaceDayByString( day );

    string dateToString = yearToString + monthToString + dayToString;

    return dateToString;
}

bool DateManager::isYearCorrect( int year ) {

    time_t timeline = time( & timeline );
    struct tm * date;
    date = localtime( & timeline );
    if (( year >= 2000 ) && ( year <= date->tm_year + 1900 )) {
        return year;
    } else return 0;
}

bool DateManager::isMonthCorrect( int month ) {

    if ( ( month >= 1 ) && ( month <= 12 ) ) {
        return month;
    } else return 0;
}

bool DateManager::isDayCorrect( int day ) {

    if ( ( day >= 1 ) && ( day <= 31 )) {
        return day;
    } else return 0;
}

string DateManager::replaceYearByString(int year) {

    string yearToString = AuxiliaryMethods::convertIntegerToString( year );
    return yearToString;
}

string DateManager::replaceMonthByString(int month) {

    string monthToString = AuxiliaryMethods::convertIntegerToString( month );
    if( monthToString.size() < 2 )  monthToString.insert( 0,"0" );

    return monthToString;
}

string DateManager::replaceDayByString(int day) {

    string dayToString = AuxiliaryMethods::convertIntegerToString( day );
    if( dayToString.size() < 2 )  dayToString.insert( 0,"0" );

    return dayToString;
}

string DateManager::replaceDateWithStringSeparatedByDashes( int dateInt ) {
    string dateString= AuxiliaryMethods::convertIntegerToString( dateInt );
    dateString = dateString.insert(4,"-");
    dateString = dateString.insert(7,"-");

    return dateString;
}

int DateManager::getDateForFirstDayOfCurrentMonth() {

    string numberOne = "01";
    string dateFirstDayOfCurrentMonth = "";

    int dateForFirstDayCurrentMonth = 0;

    dateFirstDayOfCurrentMonth = replaceYearByString( getCurrentYear() ) + replaceMonthByString( getCurrentMonth() ) + numberOne;
    dateForFirstDayCurrentMonth = atoi( dateFirstDayOfCurrentMonth.c_str());

    return dateForFirstDayCurrentMonth;
}

int DateManager::getDateForFirstDayOfPreviousMonth() {

    string numberOne = "01";
    string dateFirstDayPreviousMonth = "";
    int quantityOfMonths = 12;
    int dateOfFirstDayPreviousMonth = 0;
    int currentMonthInt = getCurrentMonth();
    int currentYearInt = getCurrentYear();

    if ( currentMonthInt == 1 ) {
        currentMonthInt = quantityOfMonths;
        currentYearInt = currentYearInt - 1;
    } else {
        currentMonthInt--;
    }
    dateFirstDayPreviousMonth = replaceYearByString( currentYearInt ) + replaceMonthByString( currentMonthInt ) + numberOne;
    dateOfFirstDayPreviousMonth = atoi( dateFirstDayPreviousMonth.c_str());

    return dateOfFirstDayPreviousMonth;
}

bool DateManager::whetherLeapYear( int year ) {
    return(( year % 4 == 0 && year % 100 != 0 ) ||( year % 400 == 0 ) );
}

int DateManager::calculateNumberOfDaysInMonth( int month, int year ) {

    int quantityOfDaysMonth = 0;
    if( month == 2 ) {
        if( whetherLeapYear( year ) ) quantityOfDaysMonth = 29;
        else quantityOfDaysMonth = 28;
    } else if (( month == 4 ) || ( month == 6 ) || ( month == 9 ) || ( month == 11 ) )
        quantityOfDaysMonth = 30;
    else quantityOfDaysMonth = 31;

    return quantityOfDaysMonth;
}

int DateManager::getDateForLastDayOfPreviousMonth() {

    string dateLastDayPreviousMonth = "";
    int quantityOfDaysLastMonth = 0;
    int quantityOfMonths = 12;
    int dateOfLastDayPreviousMonth = 0;
    int currentMonthInt = getCurrentMonth();
    int currentYearInt = getCurrentYear();

    if ( currentMonthInt == 1 ) {
        currentMonthInt = quantityOfMonths;
        currentYearInt = currentYearInt - 1;
    } else {
        currentMonthInt--;
    }
    quantityOfDaysLastMonth = calculateNumberOfDaysInMonth( currentMonthInt, currentYearInt );
    dateLastDayPreviousMonth = replaceYearByString( currentYearInt ) + replaceMonthByString( currentMonthInt ) + replaceDayByString( quantityOfDaysLastMonth );
    dateOfLastDayPreviousMonth = atoi( dateLastDayPreviousMonth.c_str());

    return dateOfLastDayPreviousMonth;
}

void DateManager::setStartDate(int newStartDate) {
    startDate = newStartDate;
}

void DateManager::setEndDate(int newEndDate) {
    endDate = newEndDate;
}

int DateManager::getStartDate() {
    return startDate;
}

int DateManager::getEndDate() {
    return endDate;
}
