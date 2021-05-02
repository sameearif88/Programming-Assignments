#include <iostream>
#include <cmath>

//Takes binary input and checks that numbers like 102, a111 are not entered
void inputNumbers(int &numberOne, int &numberTwo);
//Converts binary number to decimal number
int binaryToDecimal(int number);
//Converts decimal number to binary number
int decimalToBinary(int number);
//Takes hexadecimal input and checks that numbers like 11H(out of range) are not entered
void inputString(std::string &hexNumberOne, std::string &hexNumberTwo);
//Converts hexadecimal to decimal
int hexToDecimal(std::string number);
//Converts decimal to hexadecimal
std::string decimalToHex(int number);
//Output hexadecimal
void outputHexadecimal(std::string hexadecimal);

int main()
{
    int numberOne, numberTwo, decimalOne, decimalTwo, choice, answer;
    std::string hexNumberOne, hexNumberTwo, answerHex;
    double rounding;
    
    //Input the number system you want to work with
    system("cls");
    std::cout << "Which number system you wand to work with?" << std::endl;
    std::cout << "Enter 1 for binary system" << std::endl;
    std::cout << "Enter 2 for hexadecimal" << std::endl;
    std::cin >> choice;

    //Validate the choice input
    while(choice != 1 && choice != 2 || std::cin.fail())
    {
        system("cls");
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry!" << std::endl;
        std::cout << "Which number system you wand to work with?" << std::endl;
        std::cout << "Enter 1 for binary system" << std::endl;
        std::cout << "Enter 2 for hexadecimal" << std::endl;
        std::cin >> choice;
    }
    system("cls");

    //If user selected binary calculation
    if(choice == 1)
    {
        //Input the binary numbers
        inputNumbers(numberOne, numberTwo);
        std::cout << std::endl << "ANSWER:" << std::endl;

        //Convert binary values to decimal values
        decimalOne = binaryToDecimal(numberOne);
        decimalTwo = binaryToDecimal(numberTwo);
        std::cout << "In decimal number system: Number 1 = " << decimalOne << " and Number 2 = " << decimalTwo << std::endl;

        //Addition
        answer = decimalToBinary(decimalOne + decimalTwo);
        std::cout << "Sum = " << answer << " in binary or " << decimalOne + decimalTwo << " in decimal system" << std::endl;

        //Subtraction
        if(decimalOne >= decimalTwo)
        {
            answer = decimalToBinary(decimalOne - decimalTwo);
            std::cout << "Subtract = " << answer << " in binary or " << decimalOne - decimalTwo << " in decimal system" << std::endl;
        }
        else
        {
            answer = decimalToBinary(decimalTwo - decimalOne);
            std::cout << "Subtract = " << answer << " in binary or " << decimalTwo - decimalOne << " in decimal system" << std::endl;
        }

        //Multiplication
        answer = decimalToBinary(decimalOne * decimalTwo);
        std::cout << "Multiply = " << answer << " in binary or " << decimalOne * decimalTwo << " in decimal system" << std::endl;

        //Division
        if(decimalTwo != 0 && decimalOne != 0)
        {
            if(decimalOne >= decimalTwo)
            {
                rounding = double(decimalOne)/double(decimalTwo);
                rounding = round(rounding);
                answer = decimalToBinary(int(rounding));
                std::cout << "Divide = " << answer << " in binary or " << int(rounding) << " in decimal system" << std::endl;
            }
            else
            {
                rounding = double(decimalTwo)/double(decimalOne);
                rounding = round(rounding);
                answer = decimalToBinary(int(rounding));
                std::cout << "Divide = " << answer << " in binary or " << int(rounding) << " in decimal system" << std::endl;
            }
        }
        else if(decimalOne == 0 && decimalTwo == 0)
        {
            std::cout << "Divide = MATH ERROR in binary or MATH ERROR in decimal system" << std::endl;
        }
        else
        {
            std::cout << "Divide = " << 0 << " in binary or " << 0 << " in decimal system" << std::endl;
        }
        
        
    }
    //If the user selected hexadecimal calculation
    else
    {
        //Input the hexadecimal numbers
        inputString(hexNumberOne, hexNumberTwo);
        std::cout << std::endl << "ANSWER:" << std::endl;
        
        //Convert hexadecimal value to decimal value
        decimalOne = hexToDecimal(hexNumberOne);
        decimalTwo = hexToDecimal(hexNumberTwo);
        std::cout << "In decimal number system: Number 1 = " << decimalOne << " Number 2 = " << decimalTwo << std::endl;
        
        //Addition
        answerHex = decimalToHex(decimalOne + decimalTwo);
        std::cout << "Sum = ";
        outputHexadecimal(answerHex);
        std::cout << " in Hexadecimal or " << decimalOne + decimalTwo << " in decimal system" << std::endl;

        //Subtraction
        if(decimalOne >= decimalTwo)
        {
            answerHex = decimalToHex(decimalOne - decimalTwo);
            std::cout << "Subtract = ";
            outputHexadecimal(answerHex);
            std::cout << " in Hexadecimal or " << decimalOne - decimalTwo << " in decimal system" << std::endl;
        }
        else
        {
            answerHex = decimalToHex(decimalTwo - decimalOne);
            std::cout << "Subtract = ";
            outputHexadecimal(answerHex);
            std::cout << " in Hexadecimal or " << decimalTwo - decimalOne << " in decimal system" << std::endl;
        }

        //Multiplication
        answerHex = decimalToHex(decimalOne * decimalTwo);
        std::cout << "Multiply = ";
        outputHexadecimal(answerHex);
        std::cout << " in Hexadecimal or " << decimalOne * decimalTwo << " in decimal system" << std::endl;

        //Division
        if(decimalTwo != 0 && decimalOne != 0)
        {
            if(decimalOne >= decimalTwo)
            {
                rounding = double(decimalOne)/double(decimalTwo);
                rounding = round(rounding);
                answerHex = decimalToHex(int(rounding));
                std::cout << "Divide = ";
                outputHexadecimal(answerHex);
                std::cout << " in Hexadecimal or " << int(rounding) << " in decimal system" << std::endl;
            }
            else
            {
                rounding = double(decimalTwo)/double(decimalOne);
                rounding = round(rounding);
                answerHex = decimalToHex(int(rounding));
                std::cout << "Divide = ";
                outputHexadecimal(answerHex);
                std::cout << " in Hexadecimal or " << int(rounding) << " in decimal system" << std::endl;
            }
        }
        else if(decimalOne == 0 && decimalTwo == 0)
        {
            std::cout << "Divide = MATH ERROR in hexadecimal or MATH ERROR in decimal system" << std::endl;
        }
        else
        {
            std::cout << "Divide = " << 0 << " in hexadecimal or " << 0 << " in decimal system" << std::endl;
        }
    }
    return 0;
}

void inputNumbers(int &numberOne, int &numberTwo)
{
    //Enter 1st number
    bool binaryFail = true;
    std::cout << "Enter 1st number: ";
    std::cin >> numberOne;
    while(std::cin.fail() || numberOne < 0)
    {
        system("cls");
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry!" << std::endl;
        std::cout << "Enter 1st number: ";
        std::cin >> numberOne;
    }
    while(binaryFail = true)
    {
        binaryFail = false;
        int temp = numberOne;
        while(temp > 0)
        {
            if(temp%10 > 1)
            {
                binaryFail = true;
                break;
            }
            temp /= 10;
        }
        if(binaryFail == false)
        {
            break;
        }
        system("cls");
        std::cout << "Wrong entry!" << std::endl;
        std::cout << "Enter 1st number: ";
        std::cin >> numberOne;
        while(std::cin.fail())
        {
            system("cls");
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Wrong entry!" << std::endl;
            std::cout << "Enter 1st number: ";
            std::cin >> numberOne;
        }
    }

    //Enter 2nd number
    binaryFail = true;
    std::cout << "Enter 2nd number: ";
    std::cin >> numberTwo;
    while(std::cin.fail() || numberTwo < 0)
    {
        system("cls");
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry!" << std::endl;
        std::cout << "Enter 2nd number: ";
        std::cin >> numberTwo;
    }
    while(binaryFail = true)
    {
        binaryFail = false;
        int temp = numberTwo;
        while(temp > 0)
        {
            if(temp%10 > 1)
            {
                binaryFail = true;
                break;
            }
            temp /= 10;
        }
        if(binaryFail == false)
        {
            break;
        }
        system("cls");
        std::cout << "Wrong entry!" << std::endl;
        std::cout << "Enter 2nd number: ";
        std::cin >> numberTwo;
        while(std::cin.fail())
        {
            system("cls");
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Wrong entry!" << std::endl;
            std::cout << "Enter 2nd number: ";
            std::cin >> numberTwo;
        }
    }
}

int binaryToDecimal(int number)
{
    int n = 0, temp = number, decimalValue = 0;
    while(temp > 0)
    {
        if(temp%10 == 1)
        {
            decimalValue += pow(2, n);
        }
        temp /= 10;
        n ++;
    }
    return decimalValue;
}

int decimalToBinary(int number)
{
    int multiplyer = 1, n = 0, temp = number, binary = 0;
    while(pow(2, n) < number)
    {
        n++;
    }
    for(int i = 0; i < n; ++i)
    {
        multiplyer *= 10;
    }
    while(temp > 0)
    {
        if(temp >= pow(2, n))
        {
            binary += 1 * multiplyer;
            temp = temp - pow(2, n);
        }
        multiplyer /= 10;
        n--;
    }
    return binary;
}

void inputString(std::string &hexNumberOne, std::string &hexNumberTwo)
{
    bool stringFail = true;
    std::cout << "Enter 1st number: ";
    std::cin >> hexNumberOne;
    while(stringFail == true)
    {
        stringFail = false;
        for(int i = 0; i < hexNumberOne.length(); i++)
        {
            int check = int(hexNumberOne[i]);
            if((check < 48 || check > 57) && (check < 97 || check > 102) && (check < 65 || check > 70))
            {
                stringFail = true;
            }
        }
        if(stringFail == false)
        {
            break;
        }
        system("cls");
        std::cout << "Wrong entry!" << std::endl;
        std::cout << "Enter 1st number: ";
        std::cin >> hexNumberOne;
    }

    stringFail = true;
    std::cout << "Enter 2nd number: ";
    std::cin >> hexNumberTwo;
    while(stringFail == true)
    {
        stringFail = false;
        for(int i = 0; i < hexNumberTwo.length(); i++)
        {
            int check = int(hexNumberTwo[i]);
            if((check < 48 || check > 57) && (check < 97 || check > 102) && (check < 65 || check > 70))
            {
                stringFail = true;
            }
        }
        if(stringFail == false)
        {
            break;
        }
        system("cls");
        std::cout << "Wrong entry!" << std::endl;
        std::cout << "Enter 2nd number: ";
        std::cin >> hexNumberTwo;
    }
}

int hexToDecimal(std::string number)
{
    int decimal = 0, temp, position = number.length() - 1;
    for(int i = 0; i < number.length(); ++i)
    {
        if(int(number[i]) >= 48 && int(number[i]) <= 57)
        {
            temp = int(number[i]) - 48;
            decimal = decimal + (temp * pow(16, position));
        }
        else if(int(number[i]) >= 97 && int(number[i]) <= 102)
        {
            temp = int(number[i]) - 87;
            decimal = decimal + (temp * pow(16, position));
        }
        else
        {
            temp = int(number[i]) - 55;
            decimal = decimal + (temp * pow(16, position));
        }
        position--;
    }
    return decimal;
}

std::string decimalToHex(int number)
{
    int temp = number, remainder;
    std::string hexadecimal = "";
    while(temp > 0)
    {
        remainder = temp%16;
        if(remainder <= 9)
        {
            hexadecimal += char(remainder + 48);
        }
        else
        {
            hexadecimal += char(remainder + 55);
        }
        temp = temp/16;
    }
    return hexadecimal;
}

void outputHexadecimal(std::string hexadecimal)
{
    for(int i = hexadecimal.length() - 1; i >= 0; --i)
    {
        std::cout << hexadecimal[i];
    }
}

