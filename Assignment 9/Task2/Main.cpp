#include <iostream>
#include <iomanip>

class Date
{
    private:
        unsigned short Day;
        unsigned short Month;
        unsigned long long Year;
    public:
        Date();
        Date(unsigned short Day, unsigned short Month, unsigned long long Year);
        void Display();
};

class Time: public Date
{
    private:
        unsigned short Hour;
        unsigned short Minute;
        unsigned short Second;
    public:
        Time();
        Time(unsigned short Hour, unsigned short Minute, unsigned short Second,
            unsigned short Day, unsigned short Month, unsigned long long Year);
        void Display();
};

int main()
{
    Date D(1, 2, 2020);
    Time T(1, 2, 3, 5, 5, 2020);
    T.Display();
    T.Date::Display();
    std::cout << std::endl;
    D.Display();
    return 0;
}

Date::Date()
{
    Day = 1;
    Month = 1;
    Year = 1;
}

Date::Date(unsigned short Day, unsigned short Month, unsigned long long Year)
{
    this->Day = Day;
    this->Month = Month;
    this->Year = Year;
}

void Date::Display()
{
    std::cout << std::setw(2) << std::setfill('0') << Day << "-";
    std::cout << std::setw(2) << std::setfill('0') << Month << "-";
    if(Year < 10000)
    {
        std::cout << std::setw(4) << std::setfill('0') << Year;
    }
    else
    {
        std::cout << Year;
    }   
}

Time::Time()
{
    Hour = 1;
    Minute = 1;
    Second = 1;
}

Time::Time(unsigned short Hour, unsigned short Minute, unsigned short Second,
            unsigned short Day, unsigned short Month, unsigned long long Year):Date(Day, Month, Year)
{
    this->Hour = Hour;
    this->Minute = Minute;
    this->Second = Second;
}

void Time::Display()
{
    std::cout << std::setw(2) << std::setfill('0') << Hour << "-";
    std::cout << std::setw(2) << std::setfill('0') << Minute << "-";
    std::cout << std::setw(2) << std::setfill('0') << Second << " ";
}

