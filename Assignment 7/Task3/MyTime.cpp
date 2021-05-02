#include <iostream>
#include <iomanip>
#include "MyTime.h"

MyTime::MyTime()
{
    hour = 0;
    minute = 0;
    second = 0;
    pm = false;
}

MyTime::MyTime(int hour, int minute, int second, bool pm)
{
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    this->pm = pm;
}

MyTime::MyTime(MyTime &CopyTime)
{
    hour = CopyTime.hour;
    minute = CopyTime.minute;
    second = CopyTime.second;
    pm = CopyTime.pm;
}

void MyTime::SetHour(int hour)
{
    this->hour = hour;
}

void MyTime::SetMinute(int minute)
{
    this->minute = minute;
}

void MyTime::SetSecond(int second)
{
    this->second = second;
}

void MyTime::SetPM(bool pm)
{
    this->pm = pm;
}

void MyTime::SetHour(std::istream &Input)
{
    //Input hours
    std::cout << "Enter hours: ";
    Input >> hour;
    //Validate hours
    while(Input.fail() || hour > 12 || hour < 0)
    {
        Input.ignore(1000, '\n');
        Input.clear();
        std::cout << "Wrong entry. Enter hours: ";
        Input >> hour;
    }
}

void MyTime::SetMinute(std::istream &Input)
{
    //Input minutes
    std::cout << "Enter minutes: ";
    Input >> minute;
    //Validate hours
    while(Input.fail() || minute > 12 || minute < 0)
    {
        Input.ignore(1000, '\n');
        Input.clear();
        std::cout << "Wrong entry. Enter hours: ";
        Input >> minute;
    }
}

void MyTime::SetSecond(std::istream &Input)
{
    //Input seconds
    std::cout << "Enter seconds: ";
    Input >> second;
    //Validate hours
    while(Input.fail() || second > 12 || second < 0)
    {
        Input.ignore(1000, '\n');
        Input.clear();
        std::cout << "Wrong entry. Enter hours: ";
        Input >> second;
    }
}

void MyTime::SetPM(std::istream &Input)
{
    //Enter AM or PM
    std::cout << "Enter 0 for AM and 1 for PM: ";
    Input >> pm;
    //Validate AM, PM
    while(Input.fail() || pm > 1 || pm < 0)
    {
        Input.ignore(1000, '\n');
        Input.clear();
        std::cout << "Wrong entry. Enter hours: ";
        Input >> pm;
    }
}

int MyTime::GetHour()
{
    return hour;
}

int MyTime::GetMinute()
{
    return minute;
}

int MyTime::GetSecond()
{
    return second;
}

bool MyTime::GetPM()
{
    return pm;
}

std::istream &operator>>(std::istream &Input, MyTime &Time)
{
    Time.SetHour(Input);
    Time.SetMinute(Input);
    Time.SetSecond(Input);
    Time.SetPM(Input);
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
    Output << std::setw(2) << std::setfill('0') << Time.GetHour() << ":";
    Output << std::setw(2) << std::setfill('0') << Time.GetMinute() << ":";
    Output << std::setw(2) << std::setfill('0') << Time.GetSecond();
    //Ouput AM or PM
    if(Time.GetPM() == 1)
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
    int second = Time.GetSecond();
    int minute = Time.GetMinute();
    int hour = Time.GetHour();
    int pm = Time.GetPM();
    //Add the seconds to the time
    second += Sec;
    //Check if the updated seconds are greater than 59
    if(second >= 60)
    {
        //Update the minutes and re-assign the seconds
        minute += second/60;
        second = second%60;
        //Check if the upated minutes are greater than 59
        if(minute >= 60)
        {
            //Update the hours and re-assign the minutes
            hour += minute/60;
            minute = minute%60;
            //Check if the updated hours are greater than 11
            if(hour >= 12)
            {
                //CheckPM will switch AM to PM and vice versa if it is odd
                int CheckPM = hour/12;
                if(CheckPM%2 == 1)
                {
                    pm = !pm;
                }
                //Re-assign the hours
                hour = hour%12;
                //Re-assign 12 to hours if it gets 0
                if(hour == 0)
                {
                    hour = 12;
                }
            }
        }
    }
    Time.SetSecond(second);
    Time.SetMinute(minute);
    Time.SetHour(hour);
    Time.SetPM(pm);
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
    int thisSecond = Time.GetSecond();
    int thisMinute = Time.GetMinute();
    int thisHour = Time.GetHour();
    int thisPM = Time.GetPM();
    //Convert seconds into hours, minutes and seconds
    int minutes = Sec/60;
    int seconds = Sec%60;
    int hours = minutes/60;
    minutes = minutes%60;
    //Subtract the seconds from the time
    thisSecond -= seconds;
    //If seconds get negative use a carry from minutes
    if(thisSecond < 0)
    {
        thisSecond += 60;
        thisMinute--;
    }
    //Subtract the minutes from the time
    thisMinute -= minutes;
    //If minutes get negative use a carry from hours
    if(thisMinute < 0)
    {
        thisMinute += 60;
        thisHour--;
    }
    //Subtract the hours from the time
    thisHour -= hours;
    //Add 12 to hours until the hours are negative and each time reverse pm
    while(thisHour < 0)
    {
        thisHour += 12;
        thisPM = !thisPM;
    }
    //If the hours get 0 set it to 12
    if(thisHour == 0)
    {
        thisHour = 12;
    }
    Time.SetSecond(thisSecond);
    Time.SetMinute(thisMinute);
    Time.SetHour(thisHour);
    Time.SetPM(thisPM);
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
    static MyTime OldTime = Time;
    --Time;
    return OldTime;
}

bool operator==(MyTime &Time1, MyTime &Time2)
{
    //Check if both are either AM or PM
    if(Time1.GetPM() == Time2.GetPM())
    {
        //Check if seconds are equal
        if(Time1.GetSecond() == Time2.GetSecond())
        {
            //Check if minutes are equal
            if(Time1.GetMinute() == Time2.GetMinute())
            {
                //Check if hours are equal
                if(Time1.GetHour() == Time2.GetHour())
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
    if(Time1.GetPM() > Time2.GetPM())
    {
        return true;
    }
    else if(Time1.GetPM() == Time2.GetPM())
    {
        //Compare hours
        if(Time1.GetHour() > Time2.GetHour())
        {
            return true;
        }
        else if(Time1.GetHour() == Time2.GetHour())
        {
            //Compare minutes
            if(Time1.GetMinute() > Time2.GetMinute())
            {
                return true;
            }
            else if(Time1.GetMinute() == Time2.GetMinute())
            {
                //Compare seconds
                if(Time1.GetSecond() > Time2.GetSecond())
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
    //If time1 is not greater than equal to time2 then time1 is smaller than time2
    return !(Time1 >= Time2);
}

bool operator<=(MyTime &Time1, MyTime &Time2)
{
    //< OR ==
    return (Time1 < Time2) || (Time1 == Time2);
}

MyTime &operator!(MyTime &Time)
{
    Time.SetHour(13);
    Time.SetMinute(59);
    Time.SetSecond(59);
    if(Time.GetPM() == 1)
    {
        Time.SetPM(false);
    }
    else
    {
        Time.SetPM(true);
    }
    return Time;
}

MyTime &operator-(MyTime &Time)
{
    Time + (12 * 60 * 60);
    return Time;
}

