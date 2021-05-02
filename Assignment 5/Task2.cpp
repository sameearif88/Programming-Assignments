#include <iostream>
#include <iomanip>

class Tables
{
    private:
        int NumberOfColumns;
        int *ColumnLength;
        std::string *Header;
        int **Data;
        int MaxColumnLength();
    public:
        Tables();
        Tables(int Columns, int *Length, std::string *Header, int **DataTable);
        ~Tables();
        void ChangeColumnData(int Column, int Length, int *ArraySize);
        void SetData(int **DataTable);
        void PrintTable();
        void PrintColumnAverage();
        void PrintColumn(int ColumnNumber);
};

int main()
{
    //Input and validate number of colums
    int ColumnNumber;
    std::cout << "Enter number of columns: ";
    std::cin >> ColumnNumber;
    while(std::cin.fail() || ColumnNumber < 1)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entery. Enter number of columns: ";
        std::cin >> ColumnNumber;
    }
    system("cls");

    //Input and validate length of each column
    int *ColumnLengthArray = new int[ColumnNumber];
    for(int i = 0; i < ColumnNumber; ++i)
    {
        std::cout << "Enter length of columnn " << i + 1 << " : ";
        std::cin >> ColumnLengthArray[i];
        while(std::cin.fail() || ColumnLengthArray[i] < 1)
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Wrong entry. Enter length of column " << i + 1 << " : ";
            std::cin >> ColumnLengthArray[i];
        }
    }
    system("cls");

    //Input Headers
    std::string *HeaderArray = new std::string[ColumnNumber];
    std::cin.ignore();
    for(int i = 0; i < ColumnNumber; ++i)
    {
        std::cout << "Enter header for column " << i + 1 << " : ";
        getline(std::cin, HeaderArray[i]);
    }
    system("cls");

    //Allocate memory to data array
    int **DataArray = new int*[ColumnNumber];
    for(int i = 0; i < ColumnNumber; ++i)
    {
        DataArray[i] = new int[ColumnLengthArray[i]];
    }
    //Input the data
    for(int i = 0; i < ColumnNumber; ++i)
    {
        for(int j = 0; j < ColumnLengthArray[i]; ++j)
        {
            std::cout << "Enter element " << j + 1 << " of column " << i + 1<< " : ";
            std::cin >> DataArray[i][j];
            while(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "Wrong entry. " << "Enter element " << j + 1 << " of column " << i + 1<< " : ";
                std::cin >> DataArray[i][j];
            }
        }
        std::cout << std::endl;
    }
    system("cls");

    //Declare the table variable
    Tables Table(ColumnNumber, ColumnLengthArray, HeaderArray, DataArray);

    //Print full table
    Table.PrintTable();
    std::cout << std::endl << "Press enter to continue...";
    std::cin.ignore();
    std::cin.get();
    system("cls");
    //Print average
    Table.PrintColumnAverage();
    std::cout << std::endl << "Press enter to continue...";
    std::cin.get();
    system("cls");
    //Print a perticular column
    int PrintColumn;
    std::cout << "Enter column you want to print: ";
    std::cin >> PrintColumn;
    while(std::cin.fail() || PrintColumn < 1 || PrintColumn > ColumnNumber)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry. Enter column you want to print: ";
        std::cin >> PrintColumn;
    }
    Table.PrintColumn(PrintColumn);
    std::cout << std::endl << "Press enter to continue...";
    std::cin.ignore();
    std::cin.get();
    system("cls");

    //Input column you want to change and validate
    int ColumnChange;
    std::cout << "Enter column you want to change: ";
    std::cin >> ColumnChange;
    while(std::cin.fail() || ColumnChange < 1 || ColumnChange > ColumnNumber)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry. Enter column you want to print: ";
        std::cin >> ColumnChange;
    }

    //Input and valudate the new length of the column
    int LengthChange;
    std::cout << "Enter new length of the column: ";
    std::cin >> LengthChange;
    while(std::cin.fail() || LengthChange < 1)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry. Enter column you want to print: ";
        std::cin >> LengthChange;
    }
    system("cls");

    //Input new data for the column and validate
    int* NewColumnData = new int[LengthChange];
    std::cout << "Enter new data for the column: " << std::endl;
    for(int i = 0; i < LengthChange; ++i)
    {
        std::cout << "Enter element " << i + 1 << " of column " << ColumnChange << " : ";
        std::cin >> NewColumnData[i];
        while(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Wrong entry. " << "Enter element " << i + 1 << " of column " << ColumnChange << " : ";
            std::cin >> NewColumnData[i];
        }
    }
    system("cls");

    //Call the method function
    Table.ChangeColumnData(ColumnChange, LengthChange, NewColumnData);
    
    //Print the table after the change
    Table.PrintTable();

    //Deallocate the memory
    delete [] ColumnLengthArray;
    delete [] HeaderArray;
    delete [] NewColumnData;
    for(int i = 0; i < ColumnNumber; ++i)
    {
        delete [] DataArray[i];
    }
    delete [] DataArray;
    return 0;
}

Tables::Tables()
{
    //Set number of columns to 0 and all the pointers to NULL
    NumberOfColumns = 0;
    ColumnLength = NULL;
    Header = NULL;
    Data = NULL;
}

Tables::Tables(int Columns, int *Length, std::string *HeaderString, int **DataTable)
{
    //Initialize NumberOfColumns
    NumberOfColumns = Columns;

    //Initialize the lengths
    ColumnLength = new int[NumberOfColumns];
    for(int i = 0; i < NumberOfColumns; ++i)
    {
        ColumnLength[i] = Length[i];
    }

    //Initialize the header
    Header = new std::string[NumberOfColumns];
    for(int i = 0; i < NumberOfColumns; ++i)
    {
        Header[i] = HeaderString[i];
    }
    //Allocate memory to data array
    Data = new int*[NumberOfColumns];
    for(int i = 0; i < NumberOfColumns; ++i)
    {
        Data[i] = new int[ColumnLength[i]];
    }
    //Initialize the data
    for(int i = 0; i < NumberOfColumns; ++i)
    {
        for(int j = 0; j < ColumnLength[i]; ++j)
        {
            Data[i][j] = DataTable[i][j];
        }
    }
}

Tables::~Tables()
{
    //Delete ColumnLength array 
    delete [] ColumnLength;

    //Delete Header array 
    delete [] Header;

    //Delete Data array 
    for(int i = 0; i < NumberOfColumns; ++i)
    {
        delete [] Data[i];
    }
    delete [] Data;
}

void Tables::ChangeColumnData(int Column, int Length, int *Array)
{
    //Check if the pointer is NULL and if the new length does not equal the old length
    if(ColumnLength != NULL && ColumnLength[Column]- 1 != Length)
    {
        //Change the length and delete the column and reallocate memory with new column length
        delete [] Data[Column - 1];
        ColumnLength[Column - 1] = Length;
        Data[Column - 1] = new int[Length];
    }
    //Change to new data
    for(int i = 0; i < Length; ++i)
    {
        Data[Column - 1][i] = Array[i];
    }
}

void Tables::SetData(int **DataTable)
{
    //Delete Data array
    if(Data != NULL)
    {
        for(int i = 0; i < NumberOfColumns; ++i)
        {
            delete [] Data[i];
        }
        delete [] Data;
    }

    //Allocate memory to Data
    Data = new int*[NumberOfColumns];
    for(int i = 0; i < NumberOfColumns; ++i)
    {
        Data[i] = new int[ColumnLength[i]];
    }
    //Initialize the data
    for(int i = 0; i < NumberOfColumns; ++i)
    {
        for(int j = 0; j < ColumnLength[i]; ++j)
        {
            Data[i][j] = DataTable[i][j];
        }
    }
}

void Tables::PrintTable()
{
    //Print headers
    for(int i = 0; i < NumberOfColumns; ++i)
    {
        std::cout << std::setw(Header[i].length() + 4) << std::left << Header[i];
    }
    std::cout << std::endl;

    //Find the maximum length of the column
    int MaxColumn = MaxColumnLength();
    //Print data
    for(int i = 0; i < MaxColumn; ++i)
    {
        for(int j = 0; j < NumberOfColumns; ++j)
        {
            if(ColumnLength[j] > i)
            {
                std::cout << std::setw(Header[j].length() + 4) << std::left << Data[j][i];
            }
            else
            {
                std::cout << std::setw(Header[j].length() + 4) << std::left << " ";
            }
        }
        std::cout << std::endl;
    }    
}

void Tables::PrintColumnAverage()
{
    //Print headers
    for(int i = 0; i < NumberOfColumns; ++i)
    {
        std::cout << std::setw(Header[i].length() + 4) << std::left << Header[i];
    }
    std::cout << std::endl;

    //Print column sum
    double Sum = 0;
    for(int i = 0; i < NumberOfColumns; ++i)
    {
        for(int j = 0; j < ColumnLength[i]; ++j)
        {
            Sum += (double)Data[i][j];   
        }
        std::cout << std::fixed << std::setprecision(2) << std::setw(Header[i].length() + 4) << std::left << Sum/(double)ColumnLength[i];
        Sum = 0;
    }
}

void Tables::PrintColumn(int ColumnNumber)
{
    //Print header
    std::cout << std::setw(Header[ColumnNumber - 1].length() + 4) << std::left << Header[ColumnNumber - 1] << std::endl;;

    //Print data
    for(int i = 0; i < ColumnLength[ColumnNumber - 1]; ++i)
    {
        std::cout << std::setw(Header[ColumnNumber - 1].length() + 4) << std::left << Data[ColumnNumber - 1][i] << std::endl;
    }
}

int Tables::MaxColumnLength()
{
    //Find the maximun number of column in the data so we can print data
    int Max = 0;
    for(int i = 0; i < NumberOfColumns; ++i)
    {
        if(ColumnLength[i] > Max)
        {
            Max = ColumnLength[i];
        }
    }
    return Max;
}

