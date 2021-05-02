#include <iostream>
#include <cmath>

void HanoiRecusive(int NumberOfDisc, char From, char To, char Using);
void HanoiIterative(int NumberOfDisc, char From, char To, char Using);
bool LegalMove(int From[], int To[], int NUmberOfDisc);

int main()
{
    system("cls");
    //std::cout << "RECURSIVE:" << std::endl;
    //HanoiRecusive(6, 'A', 'C', 'B');
    std::cout << "ITERATIVE:" << std::endl;
    HanoiIterative(5, 'A', 'C', 'B');
    return 0;
}

void HanoiRecusive(int NumberOfDisc, char From, char To, char Using)
{
    if(NumberOfDisc == 0)
    {
        return;
    }   
    else
    {
        HanoiRecusive(NumberOfDisc - 1, From, Using, To);
        std::cout << "Move disc " << NumberOfDisc << " from " << From << " to " << To << std::endl;
        HanoiRecusive(NumberOfDisc - 1, Using, To, From);
    }   
}

void HanoiIterative(int NumberOfDisc, char From, char To, char Using)
{
    int A[NumberOfDisc];
    int B[NumberOfDisc];
    int C[NumberOfDisc];
    for(int i = 0; i < NumberOfDisc; ++i)
    {
        A[i] = NumberOfDisc - i;
        B[i] = 0;
        C[i] = 0;
    }
    if(NumberOfDisc%2 == 0)
    {
        char Temp = Using;
        Using = To;
        To = Temp;
        for(int i = 0; i < NumberOfDisc; ++i)
        {
            int Temp = B[i];
            B[i] = C[i];
            C[i] = Temp;
        }
    }
    int Moves = pow(2, NumberOfDisc) - 1;
    for(int i = 1; i <= Moves; ++i)
    {
        if(i%3 == 1)
        {
            //A to C
            if(LegalMove(A, C, NumberOfDisc))
            {
                std::cout << From << " to " << To << std::endl;
            }
            else if(LegalMove(C, A, NumberOfDisc))
            {
                std::cout << To << " to " << From << std::endl;
            }
        }
        if(i%3 == 2)
        {
            //A to B
            if(LegalMove(A, B, NumberOfDisc))
            {
                std::cout << From << " to " << Using << std::endl;
            }
            else if(LegalMove(B, A, NumberOfDisc))
            {
                std::cout << Using << " to " << From << std::endl;
            }
        }
        if(i%3 == 0)
        {
            //B to C
            if(LegalMove(B, C, NumberOfDisc))
            {
                std::cout << Using << " to " << To << std::endl;
            }
            else if(LegalMove(C, B, NumberOfDisc))
            {
                std::cout << To << " to " << Using << std::endl;
            }
        }
    }
}

bool LegalMove(int From[], int To[], int NUmberOfDisc)
{
    bool Empty = true;
    for(int i = NUmberOfDisc - 1; i >= 0; --i)
    {
        if(To[i] != 0)
        {
            Empty = false;
            break;
        }
    }
    int FromTop, ToTop;
    for(int i = NUmberOfDisc - 1; i >= 0; --i)
    {
        if(From[i] == 0)
        {
            continue;
        }
        FromTop = From[i];
        break;
    }
    for(int i = NUmberOfDisc - 1; i >= 0; --i)
    {
        if(To[i] == 0)
        {
            continue;
        }
        ToTop = To[i];
        break;
    }
    if(FromTop < ToTop || Empty)
    {
        std::cout << "Move disc " << FromTop << " from ";
        for(int i = 0; i < NUmberOfDisc; ++i)
        {
            if(To[i] == 0)
            {
                To[i] = FromTop;
                break;
            }
        }
        for(int i = 0; i < NUmberOfDisc; ++i)
        {
            if(From[i] == FromTop)
            {
                From[i] = 0;
                break;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
    
}

