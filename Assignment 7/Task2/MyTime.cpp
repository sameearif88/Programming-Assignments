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

MyTime &MyTime::operator+(int const &Sec)
{
    //Add the seconds to the time
    this->second += Sec;
    //Check if the updated seconds are greater than 59
    if(this->second >= 60)
    {
        //Update the minutes and re-assign the seconds
        this->minute += this->second/60;
        this->second = this->second%60;
        //Check if the upated minutes are greater than 59
        if(this->minute >= 60)
        {
            //Update the hours and re-assign the minutes
            this->hour += this->minute/60;
            this->minute = this->minute%60;
            //Check if the updated hours are greater than 11
            if(this->hour >= 12)
            {
                //CheckPM will switch AM to PM and vice versa if it is odd
                int CheckPM = this->hour/12;
                if(CheckPM%2 == 1)
                {
                    this->pm = !this->pm;
                }
                //Re-assign the hours
                this->hour = this->hour%12;
                //Re-assign 12 to hours if it gets 0
                if(this->hour == 0)
                {
                    this->hour = 12;
                }
            }
        }
    }
    return *this;
}

MyTime &operator+(int const &Sec, MyTime &Time)
{
    //Call the other overloaded + operator
    Time + Sec;
    return Time;
}

MyTime &MyTime::operator-(int const &Sec)
{
    //Convert seconds into hours, minutes and seconds
    int minutes = Sec/60;
    int seconds = Sec%60;
    int hours = minutes/60;
    minutes = minutes%60;
    //Subtract the seconds from the time
    this->second -= seconds;
    //If seconds get negative use a carry from minutes
    if(this->second < 0)
    {
        this->second += 60;
        this->minute--;
    }
    //Subtract the minutes from the time
    this->minute -= minutes;
    //If minutes get negative use a carry from hours
    if(this->minute < 0)
    {
        this->minute += 60;
        this->hour--;
    }
    //Subtract the hours from the time
    this->hour -= hours;
    //Add 12 to hours until the hours are negative and each time reverse pm
    while(this->hour < 0)
    {
        this->hour += 12;
        this->pm = !this->pm;
    }
    //If the hours get 0 set it to 12
    if(this->hour == 0)
    {
        this->hour = 12;
    }
    return *this;
}

MyTime &operator-(int const &Sec, MyTime &Time)
{
    //Call the other overloaded - operator
    Time - Sec;
    return Time;
}

MyTime &MyTime::operator++()
{
    //Increment seconds and return the updated time
    *this + 1;
    return *this;
}

MyTime &MyTime::operator++(int)
{
    //Increment seconds but return the time without increment
    static MyTime OldTime = *this;
    ++(*this);
    return OldTime;
}

MyTime &MyTime::operator--()
{
    //Decrement seconds and return the updated time
    *this - 1;
    return *this;
}

MyTime &MyTime::operator--(int)
{
    //Decrement seconds but return the time without increment
    static MyTime OldTime;
    OldTime = *this;
    --(*this);
    return OldTime;
}

bool MyTime::operator==(MyTime &Time)
{
    //Check if both are either AM or PM
    if(this->pm == Time.pm)
    {
        //Check if seconds are equal
        if(this->second == Time.second)
        {
            //Check if minutes are equal
            if(this->minute == Time.minute)
            {
                //Check if hours are equal
                if(this->hour == Time.hour)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool MyTime::operator!=(MyTime &Time)
{
    //Just the opposite answer of ==
    return !(*this == Time);
}

bool MyTime::operator>(MyTime &Time)
{
    //Compare pm
    if(this->pm > Time.pm)
    {
        return true;
    }
    else if(this->pm == Time.pm)
    {
        //Compare hours
        if(this->hour > Time.hour)
        {
            return true;
        }
        else if(this->hour == Time.hour)
        {
            //Compare minutes
            if(this->minute > Time.minute)
            {
                return true;
            }
            else if(this->minute == Time.minute)
            {
                //Compare seconds
                if(this->second > Time.second)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool MyTime::operator>=(MyTime &Time)
{
    //> OR ==
    return (*this > Time) || (*this == Time);
}

bool MyTime::operator<(MyTime &Time)
{
    //Compare pm
    if(this->pm < Time.pm)
    {
        return true;
    }
    else if(this->pm == Time.pm)
    {
        //Compare hours
        if(this->hour < Time.hour)
        {
            return true;
        }
        else if(this->hour == Time.hour)
        {
            //Compare minutes
            if(this->minute < Time.minute)
            {
                return true;
            }
            else if(this->minute == Time.minute)
            {
                //Compare seconds
                if(this->second < Time.second)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool MyTime::operator<=(MyTime &Time)
{
    //< OR ==
    return (*this < Time) || (*this == Time);
}

MyTime &MyTime::operator!()
{
    this->hour = 13;
    this->minute = 59;
    this->second = 59;
    if(this->pm == true)
    {
        this->pm = false;
    }
    else
    {
        this->pm = false;
    }
    return *this;
}

MyTime &MyTime::operator-()
{
    this->pm = !this->pm;
    return *this;
}

