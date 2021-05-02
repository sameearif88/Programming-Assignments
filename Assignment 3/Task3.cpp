#include <iostream>

long double power(long double x, long long int n);
long long int factorial(long long int n);
long double antiLog(long double x, long long int n);

int main()
{
    long double x; 
    long long int n;
    system("cls");
    //Enter value of x and validate
    std::cout << "Enter value of x: ";
    std::cin >> x;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry! Enter value of x again: ";
        std::cin >> x;
    }
    system("cls");

    //Enter value of n and validate
    std::cout << "Enter value of n: ";
    std::cin >> n;
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry! Enter value of n again: ";
        std::cin >> n;
    }
    system("cls");

    //Find the antilog
    std::cout << "Natural anti-log = " << "e^" << x << " = " << antiLog(x, n);
    return 0;
}

long double power(long double x, long long int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return x * power(x, n - 1);
    }
}

long long int factorial(long long int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

long double antiLog(long double x, long long int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return power(x, n)/factorial(n) + antiLog(x, n - 1);
    }
    
}

