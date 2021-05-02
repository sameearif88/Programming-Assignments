#ifndef MyTime_H
#define MyTIme_H
#include <iostream>

struct MyTime
{
    private:
        int hour;
        int minute;
        int second;
        bool pm;
    public:
        friend std::istream &operator>>(std::istream &Input, MyTime &Time);
        MyTime &operator=(MyTime &Time);
        friend std::ostream &operator<<(std::ostream &Output, MyTime &Time);
        friend MyTime &operator+(MyTime &Time, int const &Sec);
        friend MyTime &operator+(int const &Sec, MyTime &Time);
        friend MyTime &operator-(MyTime &Time, int const &Sec);
        friend MyTime &operator-(int const &Sec, MyTime &Time);
        friend MyTime &operator++(MyTime &Time);
        friend MyTime &operator++(MyTime &Time, int);
        friend MyTime &operator--(MyTime &Time);
        friend MyTime &operator--(MyTime &Time, int);
        friend bool operator==(MyTime &Time1, MyTime &Time2);
        friend bool operator!=(MyTime &Time1, MyTime &Time2);
        friend bool operator>(MyTime &Time1, MyTime &Time2);
        friend bool operator>=(MyTime &Time1, MyTime &Time2);
        friend bool operator<(MyTime &Time1, MyTime &Time2);
        friend bool operator<=(MyTime &Time1, MyTime &Time2);
        friend MyTime &operator!(MyTime &Time);
        friend MyTime &operator-(MyTime &Time);
};

#endif