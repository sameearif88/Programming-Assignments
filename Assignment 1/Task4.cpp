#include <iostream>

int numberLength(int number);

int main()
{
    unsigned int number, newNumber = 0, len, multiplyer = 1;
    std::cout << "Enter positive integer: ";
    std::cin >> number;
    len = numberLength(number);
    for(int i = 2; i <= len; ++i)
    {
        multiplyer *= 10;
    }
    for(int i = 1; i <= len; ++i)
    {
        newNumber += ((number%10)*multiplyer);
        number /= 10;
        multiplyer /= 10;
    }
    std::cout << "Reverse number: " << newNumber;
    return 0;
}

int numberLength(int number)
{
    int temp = number, count = 1;
    while(temp/10 > 0)
    {
        count++;
        temp /= 10;
    }
    return count;
}