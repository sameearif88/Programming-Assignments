#include <iostream>

void input(char &choice);
int answer(int &number);

int main()
{
    char choice;
    int number, sum;
    input(choice);
    while(choice != 'e')
    {
        while (choice != 'e' && choice != 'c')
        {
            std::cout << "Invalid option!" << std::endl;
            input(choice);
        }
        if(choice == 'e')
        {
            break;
        }
        std::cout << "Enter an integer: ";
        std::cin >> number;
        sum = answer(number);
        std::cout << "Sum of digits: " << sum << std::endl << std::endl;
        input(choice);  
    }
    return 0;
}

void input(char &choice)
{
    std::cout << "Enter 'e' to exit and 'c' to continue: ";
    std::cin >> choice;
    std::cout << std::endl;
}

int answer(int &number)
{
    int ans = 0, temp = 0;
    while(number/10 > 0)
    {
        temp = number%10;
        ans += temp;
        number /= 10;
    }
    ans += number;
    return ans;
}