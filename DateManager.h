#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <time.h>

#include "AuxiliaryMethods.h"

using namespace std;

class DateManager {

    int startDate;
    int endDate;
    int enterYear();
    int enterMonth();
    int enterDay();
    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();
    bool isYearCorrect ( int );
    bool isMonthCorrect( int );
    bool isDayCorrect( int );
    string replaceYearByString( int );
    string replaceMonthByString( int );
    string replaceDayByString( int );
    string replaceDateByString( int, int, int  );
    int calculateNumberOfDaysInMonth( int month, int year );
    bool whetherLeapYear( int year );

public:
    string replaceDateWithStringSeparatedByDashes( int  );
    int getCurrentDateIntegerType();
    int typeDateAndChangeToInteger();
    int getDateForFirstDayOfCurrentMonth();
    int getDateForFirstDayOfPreviousMonth();
    int getDateForLastDayOfPreviousMonth();
    void setStartDate( int newStartDate );
    void setEndDate( int newEndDate );
    int getStartDate();
    int getEndDate();
};

#endif
