#include <iostream>

struct Time
{
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;
};

Time initalizeStructure(int &day, int &month, int &year, int &hour, int &minute, int &second);
void validateInteger(int &var);
void increment(Time &time, int num_of_seconds);
void incrementMinutes(Time &time, int num_of_minutes);
void incrementHours(Time &time, int num_if_hours);
void incrementDays(Time &time, int num_of_days);
bool checkLeap(int year);
int maxDaysInMonth(int month, bool leap);
int compareTimes(Time &time1, Time &time2);
int difference(Time &timeOne, Time &timeTwoe);
void outputTime(Time time);

int main()
{
    int day, month, year, hour, minute, second;
    int incrementVal, comparisonResult, differenceResult;
    Time timeOne, timeTwo;

    //For time one
    //Input and validate hour
    system("cls");
    std::cout << "ENTER TIME ONE:" << std::endl;
    std::cout << "Enter hour: ";
    std::cin >> hour;
    validateInteger(hour);
    //Input and validate minute
    std::cout << "Enter minute: ";
    std::cin >> minute;
    validateInteger(minute);
    //Input and validate second
    std::cout << "Enter second: ";
    std::cin >> second;
    validateInteger(second);
    //Input and validate year
    std::cout << "Enter year: ";
    std::cin >> year;
    validateInteger(year);
    //Input and validate month
    std::cout << "Enter month: ";
    std::cin >> month;
    validateInteger(month);
    //Input and validate day
    std::cout << "Enter day: ";
    std::cin >> day;
    validateInteger(day);
    //Initilize the structure
    system("cls");
    std::cout << "ENTER TIME ONE:" << std::endl;
    timeOne = initalizeStructure(day, month, year, hour, minute, second);

    //For time Two
    //Input and validate hour
    system("cls");
    std::cout << "ENTER TIME TWO" << std::endl;
    std::cout << "Enter hour: ";
    std::cin >> hour;
    validateInteger(hour);
    //Input and validate minute
    std::cout << "Enter minute: ";
    std::cin >> minute;
    validateInteger(minute);
    //Input and validate second
    std::cout << "Enter second: ";
    std::cin >> second;
    validateInteger(second);
    //Input and validate year
    std::cout << "Enter year: ";
    std::cin >> year;
    validateInteger(year);
    //Input and validate month
    std::cout << "Enter month: ";
    std::cin >> month;
    validateInteger(month);
    //Input and validate day
    std::cout << "Enter day: ";
    std::cin >> day;
    validateInteger(day);
    //Initilize the structure
    system("cls");
    std::cout << "ENTER TIME TWO" << std::endl;
    timeTwo = initalizeStructure(day, month, year, hour, minute, second);

    //Output the time
    system("cls");
    std::cout << "TIME ONE:" << std::endl;
    outputTime(timeOne);
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "TIME TWO:" << std::endl;
    outputTime(timeTwo);

    //Compare the times
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "COMPARISON:" << std::endl;
    comparisonResult = compareTimes(timeOne, timeTwo);
    if(comparisonResult == 0)
    {
        std::cout << "The two times are equal" << std::endl;
        std::cout << "TIMEONE - TIMETWO = 0" << std::endl;
    }
    else if(comparisonResult == 1)
    {
        std::cout << "Time one is larger" << std::endl;
        differenceResult = difference(timeOne, timeTwo);
        std::cout << "TIMEONE - TIMETWO = " << differenceResult << std::endl;
    }
    else
    {
        std::cout << "Time two is larger" << std::endl;
        differenceResult = difference(timeTwo, timeOne);
        std::cout << "TIMETWO - TIMEONE = " << differenceResult << std::endl;
    }
    

    //Enter number to seconds to increment by
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "Enter number of seconds you want to increment the time by: ";
    std::cin >> incrementVal;
    validateInteger(incrementVal);
    //Increment
    increment(timeOne, incrementVal);
    //Output after seconds increment
    outputTime(timeOne);

    //Enter number of minutes to increment
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "Enter number of minutes you want to increment the time by: ";
    std::cin >> incrementVal;
    validateInteger(incrementVal);
    //Increment
    incrementMinutes(timeOne, incrementVal);
    //Output after minutes increment
    outputTime(timeOne);

    //Enter number of hours to increment
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "Enter number of hours you want to increment the time by: ";
    std::cin >> incrementVal;
    validateInteger(incrementVal);
    //Increment
    incrementHours(timeOne, incrementVal);
    //Output after hours increment
    outputTime(timeOne);

    //Enter number of days to increment
    std::cout << "-----------------------------------------------------------------" << std::endl;
    std::cout << "Enter number of days you want to increment the time by: ";
    std::cin >> incrementVal;
    validateInteger(incrementVal);
    //Increment
    incrementDays(timeOne, incrementVal);
    //Output after days increment
    outputTime(timeOne);

    return 0;
}

Time initalizeStructure(int &day, int &month, int &year, int &hour, int &minute, int &second)
{
    //Validate hours
    while(hour < 0 || hour > 23)
    {
        std::cout << "The valid values for the hours are 0 to 23! Enter hour again: ";
        std::cin >> hour;
        validateInteger(hour);
    }

    //Validate minutes
    while(minute < 0 || minute > 59)
    {
        std::cout << "The valid values for the minutes are 0 to 59! Enter minute again: ";
        std::cin >> minute;
        validateInteger(minute);
    }

    //Validate seconds
    while(second < 0 || second > 59)
    {
        std::cout << "The valid values for the seconds are 0 to 59! Enter second again: ";
        std::cin >> second;
        validateInteger(second);
    }


    //Validate years
    bool isLeapYear = false;
    while(year < 1)
    {
        std::cout << "Year must be greater than 0! Enter year again: ";
        std::cin >> year;
        validateInteger(year);
    }
    //Check if it is a leap year
    isLeapYear = checkLeap(year);

    //Validate month
    while(month < 1 || month > 12)
    {
        std::cout << "The valid values for month are 1 to 12! Enter month again: ";
        std::cin >> month;
        validateInteger(month);
    }

    //Validate day
    int validateDay = 0;
    validateDay = maxDaysInMonth(month, isLeapYear);
    while(day < 1 || day > validateDay)
    {
        if(isLeapYear == true)
        {
            std::cout << "Its a leap year! ";
        }
        std::cout << "The valid values for dates are 1 to "  <<  validateDay << "! Enter day again: ";
        std::cin >> day;
        validateInteger(day);
    }

    //Initalize
    Time temp;
    temp.day = day;
    temp.month = month;
    temp.year = year;
    temp.hour = hour;
    temp. minute = minute;
    temp.second = second;
    return temp;
}

void validateInteger(int &var)
{
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry! Enter integer: ";
        std::cin >> var;
    }
}

void increment(Time &time, int num_of_seconds)
{
    bool isLeapYear = false;
    int validateDay = 0;
    time.second += num_of_seconds;
    //If seconds are positive after increment
    if(time.second > 59)
    {
        //Increment minutes
        time.minute += time.second/60;
        time.second = time.second%60;
        if(time.minute > 59)
        {
            //Increment hours
            time.hour += time.minute/60;
            time.minute = time.minute%60;
            if(time.hour > 23)
            {
                //Increment Days
                time.day += time.hour/24;
                time.hour = time.hour%24;
                //Check the maximun days in the month
                int thisMonth;
                thisMonth = maxDaysInMonth(time.month, isLeapYear);
                if(time.day > thisMonth)
                {
                    //Check if it's a leap year
                    isLeapYear = checkLeap(time.year);
                    //Increment month and year
                    while(time.day > thisMonth)
                    {
                        validateDay = maxDaysInMonth(time.month, isLeapYear);
                        time.day -= validateDay;
                        time.month++;
                        if(time.month == 13)
                        {
                            time.month = 1;
                            time.year++;
                        }
                        thisMonth = maxDaysInMonth(time.month, isLeapYear);
                    }
                }
            }
        }
    }
    //If seconds are negative after increment
    else if(time.second < 0)
    {
        time.minute += (time.second - 60)/60;
        while(time.second < 0)
        {
            time.second += 60;
        }
        if(time.minute < 0)
        {
            //Increment hours
            time.hour += (time.minute - 60)/60;
            while(time.minute < 0)
            {
                time.minute += 60;
            }
            if(time.hour < 0)
            {
                //Increment Days, years and month
                int tempDay = time.day;
                time.day += (time.hour - 24)/24;
                while(time.hour < 0)
                {
                    time.hour += 24;
                }
                if(time.day <= 0)
                {
                    int previousMonth = time.month;
                    int incrementYear = 0;
                    while(time.day <= 0)
                    {
                        if(previousMonth - 1 <= 0)
                        {
                            time.year--;
                            previousMonth = 12;
                            isLeapYear = checkLeap(time.year);
                        }
                        else
                        {
                            previousMonth--;
                        }
                        int thisMonth = maxDaysInMonth(previousMonth, isLeapYear);
                        time.day += thisMonth;
                    }
                    time.month = previousMonth;
                }
            }
        }
    }
}

bool checkLeap(int year)
{
    if((year%4 == 0 && year%100 != 0) || year%400 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int maxDaysInMonth(int month, bool leap)
{
    if(month < 8)
    {
        if(month%2 == 0)
        {
            if(leap == true && month == 2)
            {
                return 29;
            }
            else if(month == 2)
            {
                return 28;
            }
            else
            {
                return 30;
            }
            
        }
        else
        {
            return 31;
        }
    }
    else
    {
        if(month%2 == 0)
        {
            return 31;
        }
        else
        {
            return 30;
        }
    }   
}

void incrementMinutes(Time &time, int num_of_minutes)
{
    num_of_minutes *= 60;
    increment(time, num_of_minutes);
}

void incrementHours(Time &time, int num_of_hours)
{
    num_of_hours *= 60 * 60;
    increment(time, num_of_hours);
}

void incrementDays(Time &time, int num_of_days)
{
    num_of_days *= 60 * 60 * 24;
    increment(time, num_of_days);
}

void outputTime(Time time)
{
    std::cout << "Time: (H:M:S) ";
    std::cout << time.hour << ":" << time.minute << ":" << time.second << std::endl;
    std::cout << "Date: (DD-MM-YY) ";
    std::cout << time.day << "-" << time.month << "-" << time.year << std::endl;
}

int compareTimes(Time &time1, Time &time2)
{
    if(time1.year > time2.year)
    {
        return 1;
    }
    else if(time1.year == time2.year)
    {
        if(time1.month > time2.month)
        {
            return 1;
        }
        else if(time1.month == time2.month)
        {
            if(time1.day > time2.day)
            {
                return 1;
            }
            else if(time1.day == time2.day)
            {
                if(time1.hour > time2.hour)
                {
                    return 1;
                }
                else if(time1.hour == time2.hour)
                {
                    if(time1.minute > time2.minute)
                    {
                        return 1;
                    }
                    else if(time1.minute == time2.minute)
                    {
                        if(time1.second > time2.second)
                        {
                            return 1;
                        }   
                        else if(time1.second == time2.second)
                        {
                            return 0;
                        }
                        else
                        {
                            return -1;
                        }
                    }
                    else
                    {
                        return -1;
                    }
                }
                else
                {
                    return -1;
                }                
            }
            else
            {
                return -1;
            }   
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }   
}

int difference(Time &timeOne, Time &timeTwo)
{
    Time temp1 = timeOne;
    Time temp2 = timeTwo;
    int compResult = 0;
    int difference = 0;
    int dayInMonth = 0;

    //Find difference between seconds
    if(temp1.second >= temp2.second)
    {
        compResult += temp1.second - temp2.second;
    }
    else
    {
        compResult += (temp1.second + 60) - temp2.second;
        temp1.minute--;
    }

    //Find difference between minutess
    if(temp1.minute >= temp2.minute)
    {
        compResult += (temp1.minute - temp2.minute) * 60;
    }
    else
    {
        compResult += ((temp1.minute + 60) - temp2.minute) * 60;
        temp1.hour--;
    }

    //Find difference between hours
    if(temp1.hour >= temp2.hour)
    {
        compResult += (temp1.hour - temp2.hour) * 60 * 60;
    }
    else
    {
        compResult += ((temp1.hour + 24) - temp2.hour) * 60 * 60;
        temp1.day--;
    }
    
    //Find difference between days
    if(temp1.day >= temp2.day)
    {
        compResult += (temp1.day - temp2.day) * 24 * 60 * 60;
    }
    else
    {
        int isLeapYear = checkLeap(temp1.year);
        int thisMonth = maxDaysInMonth(temp1.month, isLeapYear);
        compResult += ((temp1.day + thisMonth) - temp2.day) * 24 * 60 * 60;
        temp1.month--;
    }

    //Find difference between months and years
    bool isLeapYear = checkLeap(temp2.year);
    int resultInDays = 0;
    isLeapYear = checkLeap(temp1.year);
    resultInDays += maxDaysInMonth(temp1.month, isLeapYear);
    while(temp1.year != temp2.year || temp1.month != temp2.month)
    {
        if(temp1.month - 1 <= 0)
        {
            temp1.year--;
            temp1.month = 12;
            isLeapYear = checkLeap(temp1.year);
        }
        else
        {
            temp1.month--;
        }
        resultInDays = maxDaysInMonth(temp1.month, isLeapYear); 
        compResult += resultInDays * 24 * 60 * 60;
        resultInDays = 0;
    }
    return compResult;
}

