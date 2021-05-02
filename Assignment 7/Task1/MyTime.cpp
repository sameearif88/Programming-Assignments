#include <iostream>
#include <iomanip>
#include "MyTime.h"

std::istream &operator>>(std::istream &Input, MyTime &Time)
{
    //Input hours
    std::cout << "Enter hours: ";
    Input >> Time.hour;
    //Validate hours
    while(Input.fail() || Time.hour > 12 || Time.hour < 0)
    {
        Input.ignore(1000, '\n');
        Input.clear();
        std::cout << "Wrong entry. Enter hours: ";
        Input >> Time.hour;
    }

    //Enter minutes
    std::cout << "Enter minutes: ";
    Input >> Time.minute;
    //Validate minutes
    while(Input.fail() || Time.minute > 59 || Time.hour < 0)
    {
        Input.ignore(1000, '\n');
        Input.clear();
        std::cout << "Wrong entry. Enter hours: ";
        Input >> Time.minute;
    }

    //Input seconds
    std::cout << "Enter seconds: ";
    Input >> Time.second;
    //Validate seconds
    while(Input.fail() || Time.second > 59 || Time.second < 0)
    {
        Input.ignore(1000, '\n');
        Input.clear();
        std::cout << "Wrong entry. Enter hours: ";
        Input >> Time.second;
    }

    //Enter AM or PM
    std::cout << "Enter 0 for AM and 1 for PM: ";
    Input >> Time.pm;
    //Validate AM, PM
    while(Input.fail() || Time.pm > 1 || Time.pm < 0)
    {
        Input.ignore(1000, '\n');
        Input.clear();
        std::cout << "Wrong entry. Enter hours: ";
        Input >> Time.pm;
    }
    return Input;
}

MyTime &MyTime::operator=(MyTime &Time)
{
    //To avoid self self assignment
    if(this != &Time)
    {
        this->hour = Time.hour;
        this->minute = Time.minute;
        this->second = Time.second;
        this->pm = Time.pm;
    }
    //We have to return reference
    return *this;
}

std::ostream &operator<<(std::ostream &Output, MyTime &Time)
{
    //Output the time
    Output << std::setw(2) << std::setfill('0') << Time.hour << ":";
    Output << std::setw(2) << std::setfill('0') << Time.minute << ":";
    Output << std::setw(2) << std::setfill('0') << Time.second;
    //Ouput AM or PM
    if(Time.pm == 1)
    {
        Output << " PM" << std::endl;
    }
    else
    {
        Output << " AM" << std::endl;
    }
    return Output;
}

MyTime &operator+(MyTime &Time, int const &Sec)
{
    //Add the seconds to the time
    Time.second += Sec;
    //Check if the updated seconds are greater than 59
    if(Time.second >= 60)
    {
        //Update the minutes and re-assign the seconds
        Time.minute += Time.second/60;
        Time.second = Time.second%60;
        //Check if the upated minutes are greater than 59
        if(Time.minute >= 60)
        {
            //Update the hours and re-assign the minutes
            Time.hour += Time.minute/60;
            Time.minute = Time.minute%60;
            //Check if the updated hours are greater than 11
            if(Time.hour >= 12)
            {
                //CheckPM will switch AM to PM and vice versa if it is odd
                int CheckPM = Time.hour/12;
                if(CheckPM%2 == 1)
                {
                    Time.pm = !Time.pm;
                }
                //Re-assign the hours
                Time.hour = Time.hour%12;
                //Re-assign 12 to hours if it gets 0
                if(Time.hour == 0)
                {
                    Time.hour = 12;
                }
            }
        }
    }
    return Time;
}

MyTime &operator+(int const &Sec, MyTime &Time)
{
    //Call the other overloaded + operator
    Time + Sec;
    return Time;
}

MyTime &operator-(MyTime &Time, int const &Sec)
{
    //Convert seconds into hours, minutes and seconds
    int minutes = Sec/60;
    int seconds = Sec%60;
    int hours = minutes/60;
    minutes = minutes%60;
    //Subtract the seconds from the time
    Time.second -= seconds;
    //If seconds get negative use a carry from minutes
    if(Time.second < 0)
    {
        Time.second += 60;
        Time.minute--;
    }
    //Subtract the minutes from the time
    Time.minute -= minutes;
    //If minutes get negative use a carry from hours
    if(Time.minute < 0)
    {
        Time.minute += 60;
        Time.hour--;
    }
    //Subtract the hours from the time
    Time.hour -= hours;
    //Add 12 to hours until the hours are negative and each time reverse pm
    while(Time.hour < 0)
    {
        Time.hour += 12;
        Time.pm = !Time.pm;
    }
    //If the hours get 0 set it to 12
    if(Time.hour == 0)
    {
        Time.hour = 12;
    }
    return Time;
}

MyTime &operator-(int const &Sec, MyTime &Time)
{
    //Call the other overloaded - operator
    Time - Sec;
    return Time;
}

MyTime &operator++(MyTime &Time)
{
    //Increment seconds and return the updated time
    Time + 1;
    return Time;
}

MyTime &operator++(MyTime &Time, int)
{
    //Increment seconds but return the time without increment
    static MyTime OldTime = Time;
    ++Time;
    return OldTime;
}

MyTime &operator--(MyTime &Time)
{
    //Decrement seconds and return the updated time
    Time - 1;
    return Time;
}

MyTime &operator--(MyTime &Time, int)
{
    //Decrement seconds but return the time without increment
    static MyTime OldTime;
    OldTime = Time;
    Time - 1;
    return OldTime;
}

bool operator==(MyTime &Time1, MyTime &Time2)
{
    //Check if both are either AM or PM
    if(Time1.pm == Time2.pm)
    {
        //Check if seconds are equal
        if(Time1.second == Time2.second)
        {
            //Check if minutes are equal
            if(Time1.minute == Time2.minute)
            {
                //Check if hours are equal
                if(Time1.hour == Time2.hour)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool operator!=(MyTime &Time1, MyTime &Time2)
{
    //Just the opposite answer of ==
    return !(Time1 == Time2);
}

bool operator>(MyTime &Time1, MyTime &Time2)
{
    //Compare pm
    if(Time1.pm > Time2.pm)
    {
        return true;
    }
    else if(Time1.pm == Time2.pm)
    {
        //Compare hours
        if(Time1.hour > Time2.hour)
        {
            return true;
        }
        else if(Time2.hour == Time2.hour)
        {
            //Compare minutes
            if(Time1.minute > Time2.minute)
            {
                return true;
            }
            else if(Time1.minute == Time2.minute)
            {
                //Compare seconds
                if(Time1.second > Time2.second)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool operator>=(MyTime &Time1, MyTime &Time2)
{
    //> OR ==
    return (Time1 > Time2) || (Time1 == Time2);
}

bool operator<(MyTime &Time1, MyTime &Time2)
{
    //Compare pm
    if(Time1.pm < Time2.pm)
    {
        return true;
    }
    else if(Time1.pm == Time2.pm)
    {
        //Compare hours
        if(Time1.hour < Time2.hour)
        {
            return true;
        }
        else if(Time2.hour == Time2.hour)
        {
            //Compare minutes
            if(Time1.minute < Time2.minute)
            {
                return true;
            }
            else if(Time1.minute == Time2.minute)
            {
                //Compare seconds
                if(Time1.second < Time2.second)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool operator<=(MyTime &Time1, MyTime &Time2)
{
    //< OR ==
    return (Time1 < Time2) || (Time1 == Time2);
}

MyTime &operator!(MyTime &Time)
{
    Time.hour = 13;
    Time.minute = 59;
    Time.second = 59;
    if(Time.pm == true)
    {
        Time.pm = false;
    }
    else
    {
        Time.pm = false;
    }
    return Time;
}

MyTime &operator-(MyTime &Time)
{
    Time.pm = !Time.pm;
    return Time;
}

