#ifndef MyTime_H
#define MyTIme_H
#include <iostream>

class MyTime
{
    private:
        int hour;
        int minute;
        int second;
        bool pm;
    public:
        MyTime();
        MyTime(int hour, int minute, int second, bool pm);
        MyTime(MyTime &CopyTime);
        void SetHour(int hour);
        void SetMinute(int minute);
        void SetSecond(int second);
        void SetPM(bool pm);
        void SetHour(std::istream &Input);
        void SetMinute(std::istream &Input);
        void SetSecond(std::istream &Input);
        void SetPM(std::istream &Input);
        int GetHour();
        int GetMinute();
        int GetSecond();
        bool GetPM();
        MyTime &operator=(MyTime &Time);
        MyTime &operator+(int const &Sec);
        MyTime &operator-(int const &Sec);
        MyTime &operator++();
        MyTime &operator++(int);
        MyTime &operator--();
        MyTime &operator--(int);
        bool operator==(MyTime &Time);
        bool operator!=(MyTime &Time);
        bool operator>(MyTime &Time);
        bool operator>=(MyTime &Time);
        bool operator<(MyTime &Time);
        bool operator<=(MyTime &Time);
        MyTime &operator!();
        MyTime &operator-();
};

std::istream &operator>>(std::istream &Input, MyTime &Time);
std::ostream &operator<<(std::ostream &Output, MyTime &Time);
MyTime &operator+(int const &Sec, MyTime &Time);
MyTime &operator-(int const &Sec, MyTime &Time);

#endif