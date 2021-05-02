#include <iostream>

class BankAccount
{
    private:
        double balance;
        int accountNumber;
        std::string firstName;
        std::string lastName;
        std::string accountType;
    public:
        BankAccount();
        void AccountDetail(std::string name1, std::string name2, std::string accountT, int accountN, double bal);
        void Transaction(double TransactionAmount);
        void ChangeName();
        void changeType(std::string NewType);
        std::string GetFirstName();
        std::string GetLastName();
        double GetBalance();
        int GetAccountNumber();
        std::string GetAccountType();
        void OutputBalance();
        void OutputType();
        void Output(int CustomerNumber);
};  

void Menu(char& Choice);
void NumberValidation(int &Number);
void NumberValidation(double &Number);
void ValidateAccountExists(BankAccount *&Accounts, int &CurrentCustomers, int &AccountNumber);
void CopyArray(BankAccount *&AccountsOne, BankAccount *&AccountsTwo, int CurrentCustomers);
void ChoiceA(BankAccount *&Accounts, int &CurrentCustomers, double &InitialBalance, int &AccountNumber, std::string &FirstName, std::string &LastName, std::string &AccountType);
void Append(BankAccount *&Accounts, int &CurrentCustomers);
void AccountExists(BankAccount *&Accounts, int &CurrentCustomers, int &AccountNumber, bool &Found, int &Index);
void ChoiceB(int &AccountNumber, BankAccount *&Accounts, int &CurrentCustomers);

int main()
{
    int N, CurrentCustomers = 0;
    char Choice = 'F';
    int AccountNumber;
    double TransactionAmount;
    std::string NewType;
    //Initilization varaibles
    double InitialBalance; 
    std::string FirstName, LastName, AccountType;
    
    //Enter the maximum number of customers
    std::cout << "Enter the maximum number of customers: ";
    std::cin >> N;
    while(std::cin.fail() || N < 1)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry! Enter again: ";
        std::cin >> N;
    }

    //Declare the dymanic array of size N
    BankAccount *Accounts = new BankAccount[N];
    
    //Menu loop
    while(Choice != '0')
    {
        //Display menu
        system("cls");
        Menu(Choice);
        switch(Choice)
        {
            //If we input A
            case 'A':
            {
                //Check if the maximum limit of customers has reached or not
                if(CurrentCustomers != N)
                {
                    //Ask for the initializers and Deallocate and reallocate memory with incremented size
                    ChoiceA(Accounts, CurrentCustomers, InitialBalance, AccountNumber, FirstName, LastName, AccountType);
                    //Store in the array
                    Accounts[CurrentCustomers - 1].AccountDetail(FirstName, LastName, AccountType, AccountNumber, InitialBalance);
                    //Output the confirmation message
                    std::cout << "Account with name " << Accounts[CurrentCustomers - 1].GetFirstName() << " ";
                    std::cout << Accounts[CurrentCustomers - 1].GetLastName() << " and account number ";
                    std::cout << Accounts[CurrentCustomers - 1].GetAccountNumber() << " has been created." << std::endl;
                    std::cout << "Press enter to continue...";
                    std::cin.ignore(1000, '\n');
                    std::cin.get();
                }
                else
                {   
                    //We can't enter more customers
                    std::cout << "Maximum limit of customers has reached. Can't add more customers. Press enter to continue..." << std::endl;
                    std::cin.ignore(1000, '\n');
                    std::cin.get();
                }
                break;
            }
            case 'B':
            {
                //Call the function 
                ChoiceB(AccountNumber, Accounts, CurrentCustomers);
                break;
            }
            case 'C':
            {
                //Enter and validate account number
                std::cout << "Enter account number you want to deposit to: ";
                std::cin >> AccountNumber;
                NumberValidation(AccountNumber);
                while (AccountNumber < 0)
                {
                    std::cout << "It can't be smaller than 0. Enter again: ";
                    std::cin >> AccountNumber;
                    NumberValidation(AccountNumber);
                }
                //Check if the account number exisits and store the Index if it exisits
                bool Found = false;
                int Index;
                AccountExists(Accounts, CurrentCustomers, AccountNumber, Found, Index);
                //If found then ask for transaction amout
                if(Found)
                {
                    //Enter and validate transaction amout
                    std::cout << "Enter transaction amount: ";
                    std::cin >> TransactionAmount;
                    NumberValidation(TransactionAmount);
                    while (AccountNumber < 0)
                    {
                        std::cout << "It can't be smaller than 0. Enter again: ";
                        std::cin >> TransactionAmount;
                        NumberValidation(TransactionAmount);
                    }
                    //Complete the transaction
                    Accounts[Index].Transaction(TransactionAmount);
                    std::cout << "Transaction of account with name " << Accounts[Index].GetFirstName() << " ";
                    std::cout << Accounts[Index].GetLastName() << " and account number ";
                    std::cout << Accounts[Index].GetAccountNumber() << " has been completed." << std::endl;
                    std::cout << "Press enter to continue...";
                    std::cin.ignore(1000, '\n');
                    std::cin.get();
                }
                //If the acount number was not found output error message
                else
                {
                    std::cout << "Account does not exists" << std::endl;
                    std::cout << "Press enter to continue...";
                    std::cin.ignore(1000, '\n');
                    std::cin.get();
                }
                break;
            }
            case 'D':
            {
                //Enter and validate account number
                std::cout << "Enter account number you want to widthraw to: ";
                std::cin >> AccountNumber;
                NumberValidation(AccountNumber);
                while (AccountNumber < 0)
                {
                    std::cout << "It can't be smaller than 0. Enter again: ";
                    std::cin >> AccountNumber;
                    NumberValidation(AccountNumber);
                }
                //Check if the account number exisits and store the Index if it exisits
                bool Found = false;
                int Index;
                AccountExists(Accounts, CurrentCustomers, AccountNumber, Found, Index);
                //If found then ask for transaction amount
                if(Found)
                {
                    //Enter and validate transaction amout
                    std::cout << "Enter transaction amount: ";
                    std::cin >> TransactionAmount;
                    NumberValidation(TransactionAmount);
                    while (AccountNumber < 0)
                    {
                        std::cout << "It can't be smaller than 0. Enter again: ";
                        std::cin >> TransactionAmount;
                        NumberValidation(TransactionAmount);
                    }
                    //Complete the transaction if balance does not get negative
                    if(Accounts[Index].GetBalance() - TransactionAmount < 0)
                    {
                        std::cout << "Insfficient balance. Transaction unsuccessful." << std::endl;
                        std::cout << "Press enter to continue...";
                        std::cin.ignore(1000, '\n');
                        std::cin.get();
                    }
                    //If balance gets negative
                    else
                    {
                        Accounts[Index].Transaction(-1 * TransactionAmount);
                        std::cout << "Transaction of account with name " << Accounts[CurrentCustomers - 1].GetFirstName() << " ";
                        std::cout << Accounts[CurrentCustomers - 1].GetLastName() << " and account number ";
                        std::cout << Accounts[CurrentCustomers - 1].GetAccountNumber() << " has been completed." << std::endl;
                        std::cout << "Press enter to continue...";
                        std::cin.get();
                    }
                }
                //If the acount number was not found output error message
                else
                {
                    std::cout << "Account does not exists" << std::endl;
                    std::cout << "Press enter to continue...";
                    std::cin.ignore(1000, '\n');
                    std::cin.get();
                }
                break;
            }
            case 'E':
            {
                //Enter and validate account number
                std::cout << "Enter account number you want to change type of: ";
                std::cin >> AccountNumber;
                NumberValidation(AccountNumber);
                while (AccountNumber < 0)
                {
                    std::cout << "It can't be smaller than 0. Enter again: ";
                    std::cin >> AccountNumber;
                    NumberValidation(AccountNumber);
                }
                //Check if the account number exisits and store the Index if it exisits
                bool Found = false;
                int Index;
                AccountExists(Accounts, CurrentCustomers, AccountNumber, Found, Index);
                //If found then ask for transaction amout
                if(Found)
                {
                    std::cout << "Enter type you want to change to: ";
                    std::cin >> NewType;
                    while(NewType != "Basic" && NewType != "Current")
                    {
                        std::cout << "Account type can only be \"Basic\" or \"Current\" .Enter account type: ";
                        std::cin >> NewType;
                    }
                    Accounts[Index].changeType(NewType);
                }
                else
                {
                    std::cout << "Account does not exists" << std::endl;
                    std::cout << "Press enter to continue...";
                    std::cin.ignore(1000, '\n');
                    std::cin.get();
                }
                
                break;
            }    
            case 'F':
            {
                //Enter and validate account number
                std::cout << "Enter account number you want to check balance of: ";
                std::cin >> AccountNumber;
                NumberValidation(AccountNumber);
                while (AccountNumber < 0)
                {
                    std::cout << "It can't be smaller than 0. Enter again: ";
                    std::cin >> AccountNumber;
                    NumberValidation(AccountNumber);
                }
                //Check if the account number exisits and store the Index if it exisits
                bool Found = false;
                int Index;
                AccountExists(Accounts, CurrentCustomers, AccountNumber, Found, Index);
                //If found then output data
                if(Found)
                {
                    Accounts[Index].OutputBalance();
                }
                else
                {
                    std::cout << "Account does not exists" << std::endl;
                    std::cout << "Press enter to continue...";
                    std::cin.ignore(1000, '\n');
                    std::cin.get();
                }
                
                break;
            }
            case 'G':
            {
                //Enter and validate account number
                std::cout << "Enter account number you want to check type of: ";
                std::cin >> AccountNumber;
                NumberValidation(AccountNumber);
                while (AccountNumber < 0)
                {
                    std::cout << "It can't be smaller than 0. Enter again: ";
                    std::cin >> AccountNumber;
                    NumberValidation(AccountNumber);
                }
                //Check if the account number exisits and store the Index if it exisits
                bool Found = false;
                int Index;
                AccountExists(Accounts, CurrentCustomers, AccountNumber, Found, Index);
                //If found then output data
                if(Found)
                {
                    Accounts[Index].OutputType();
                }
                else
                {
                    std::cout << "Account does not exists" << std::endl;
                    std::cout << "Press enter to continue...";
                    std::cin.ignore(1000, '\n');
                    std::cin.get();
                }
                
                break;
            }
            case 'H':
            {
                int TotalBalance = 0;
                //Add balance at each index of the array in total balance
                for(int i = 0; i < CurrentCustomers; ++i)
                {
                    TotalBalance += Accounts[i].GetBalance();
                }
                //Output the total balance
                std::cout << "Total balance of the bank is: " << TotalBalance << std::endl;
                std::cout << "Press enter to continue..." << std::endl;
                std::cin.ignore(1000, '\n');
                std::cin.get();
                break;
            }
            case 'I':
            {
                //Enter and validate account number
                std::cout << "Enter account number you want to change name of: ";
                std::cin >> AccountNumber;
                NumberValidation(AccountNumber);
                while (AccountNumber < 0)
                {
                    std::cout << "It can't be smaller than 0. Enter again: ";
                    std::cin >> AccountNumber;
                    NumberValidation(AccountNumber);
                }
                //Check if the account number exisits and store the Index if it exisits
                bool Found = false;
                int Index;
                AccountExists(Accounts, CurrentCustomers, AccountNumber, Found, Index);
                //If found then call the change name function
                if(Found)
                {
                    Accounts[Index].ChangeName();
                }
                break;
            }
        }
    }
    for(int i = 0; i < CurrentCustomers; ++i)
    {
        Accounts[i].Output(i);
    }
    delete [] Accounts;
    return 0;
}

void Menu(char& Choice)
{
    //Output all the options and ask for the choice
    std::cout << "Enter A to create a new bank account" << std::endl;
    std::cout << "Enter B to delete an existing bank account" << std::endl;
    std::cout << "Enter C to perform a deposit transaction" << std::endl;
    std::cout << "Enter D to perform a withdrawal transaction" << std::endl;
    std::cout << "Enter E to change account type of a customer" << std::endl;
    std::cout << "Enter F to check balance of a customer" << std::endl;
    std::cout << "Enter G to check account type of a customer" << std::endl;
    std::cout << "Enter H to check the total balance of the bank" << std::endl;
    std::cout << "Enter I to change name of a customer" << std::endl;
    std::cout << "Enter 0 to exit" << std::endl;
    std::cout << "Choice: ";
    std::cin >> Choice;
    //Validate choice
    while((int(Choice) < 65 || int(Choice) > 73) && Choice != '0')
    {
        std::cout << "Wrong entry! Enter Choice: " << std::endl;
        std::cin >> Choice;
    }
    system("cls");
}

void NumberValidation(int &Number)
{
    //Check that user does not enter character
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Cant input characters, input again: ";
        std::cin >> Number;
    }
}

void NumberValidation(double &Number)
{
    //Check that user does not enter character
    while(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Cant input characters, input again: ";
        std::cin >> Number;
    }
}

void ValidateAccountExists(BankAccount *&Accounts, int &CurrentCustomers, int &AccountNumber)
{
    bool found = true;
    //Ask to input again if the account number already exits
    while(found)
    {   
        found = false; 
        for(int i = 0; i < CurrentCustomers; ++i)
        {
            if(Accounts[i].GetAccountNumber() == AccountNumber)
            {
                found = true;
                break;
            }
        }
        if(found)
        {
            std::cout << "Account number already exits. Enter account number: ";
            std::cin >> AccountNumber;
            NumberValidation(AccountNumber);
        }
    }
}

void CopyArray(BankAccount *&AccountsOne, BankAccount *&AccountsTwo, int CurrentCustomers)
{
    //Copy array one into array two
    for(int i = 0; i < CurrentCustomers; ++i)
    {
        AccountsTwo[i] = AccountsOne[i];
    }
}

void ChoiceA(BankAccount *&Accounts, int &CurrentCustomers, double &InitialBalance, int &AccountNumber, std::string &FirstName, std::string &LastName, std::string &AccountType)
{
    //Enter first name
    std::cout << "Enter first name: ";
    std::cin >> FirstName;
    //Enter last name
    std::cout << "Enter last name: ";
    std::cin >> LastName;
    //Enter and validate account type
    std::cout << "Enter account type: ";
    std::cin >> AccountType; 
    while(AccountType != "Basic" && AccountType != "Current")
    {
        std::cout << "Account type can only be \"Basic\" or \"Current\" .Enter account type: ";
        std::cin >> AccountType;
    }
    //Enter and validate account number
    bool AlreadyExits = false;
    std::cout << "Enter account number: ";
    std::cin >> AccountNumber;
    NumberValidation(AccountNumber);
    ValidateAccountExists(Accounts, CurrentCustomers, AccountNumber);
    while (AccountNumber < 0)
    {
        std::cout << "It can't be smaller than 0. Enter again: ";
        std::cin >> AccountNumber;
        NumberValidation(AccountNumber);
        ValidateAccountExists(Accounts, CurrentCustomers, AccountNumber);
    }
    //Enter and validate initial balance
    std::cout << "Enter initial balance: ";
    std::cin >> InitialBalance;
    NumberValidation(InitialBalance);
    while (AccountNumber < 0)
    {
        std::cout << "It can't be smaller than 0. Enter again: ";
        std::cin >> InitialBalance;
        NumberValidation(InitialBalance);
    }
    //Deallocate and reallocate memory with incremented size
    Append(Accounts, CurrentCustomers);
}

void Append(BankAccount *&Accounts, int &CurrentCustomers)
{
    //Make a dymanic array of 1 elemet if we are entring 1st customer
    if(CurrentCustomers == 0)
    {
        delete [] Accounts;
        CurrentCustomers++;
        Accounts = new BankAccount[CurrentCustomers];
    }
    //Copy all the element from the dymanic array to the new dynamic array with one more element
    else
    {
        //Create a temporary array and copy all the data in it
        BankAccount *TempAccounts = new BankAccount[CurrentCustomers];
        CopyArray(Accounts, TempAccounts, CurrentCustomers);
        //Delete the previous array and make a new one with incremented elemets
        delete [] Accounts;
        CurrentCustomers++;
        Accounts = new BankAccount[CurrentCustomers];
        //Copy the elements from temporary array to the new array
        CopyArray(TempAccounts, Accounts, CurrentCustomers - 1);
        //Delete the temporary array and set the dangling pointer to NULL
        delete [] TempAccounts;
        TempAccounts = NULL;
    }
}

void AccountExists(BankAccount *&Accounts, int &CurrentCustomers, int &AccountNumber, bool &Found, int &Index)
{
    //Find the account number in the array and set found to true and index to the index of the array if found
    for(int i = 0; i < CurrentCustomers; ++i)
    {
        if(Accounts[i].GetAccountNumber() == AccountNumber)
        {
            Found = true;
            Index = i;
            break;
        }
    }
}

void ChoiceB(int &AccountNumber, BankAccount *&Accounts, int &CurrentCustomers)
{
    //Enter and validate the account number you want to delete
    std::cout << "Enter account number of the account you ant to delete: ";
    std::cin >> AccountNumber;
    NumberValidation(AccountNumber);
    while (AccountNumber < 0)
    {
        std::cout << "It can't be smaller than 0. Enter again: ";
        std::cin >> AccountNumber;
        NumberValidation(AccountNumber);
    }
    //Find the account number in array
    bool Found = false;
    bool IsBalanceZero = false;
    int Index;
    AccountExists(Accounts, CurrentCustomers, AccountNumber, Found, Index);
    //Check if balance is zero or not
    if(Found)
    {
        if(Accounts[Index].GetBalance() == 0)
        {
            IsBalanceZero = true;
        }
    }
    //If the account number is found and balance is zero we will delete the account
    if(Found && IsBalanceZero)
    {
        //Declare a temporary array and store the elements in it
        BankAccount *TempAccounts = new BankAccount[CurrentCustomers];
        CopyArray(Accounts, TempAccounts, CurrentCustomers);
        //Delete the old array and declare a new one with decremented elements
        delete [] Accounts;
        CurrentCustomers--;
        Accounts = new BankAccount[CurrentCustomers];
        //Loop through all the elements and store them in array
        for(int i = 0; i < CurrentCustomers + 1; ++i)
        {
            if(i == Index)
            {
                //Output that the accound has been deleted
                std::cout << "Account with name " << TempAccounts[Index].GetFirstName() << " ";
                std::cout << TempAccounts[Index].GetLastName() << " and account number ";
                std::cout << TempAccounts[Index].GetAccountNumber() << " has been deleted." << std::endl;
                std::cout << "Press enter to continue...";
                std::cin.ignore(1000, '\n');
                std::cin.get();
                continue;
            }
            else if(i > Index)
            {
                Accounts[i - 1] = TempAccounts[i];   
            }
            else
            {
                Accounts[i] = TempAccounts[i];
            }
        }
        //Delete and set the dangling pointer to NULL
        delete [] TempAccounts;
        TempAccounts = NULL;
    }
    //If the element is not found output the error message
    else if(!Found)
    {
        std::cout << "Bank account with account number " << AccountNumber << " does not exists.";
        std::cout << "Press enter to continue..." << std::endl;
        std::cin.ignore(1000, '\n');
        std::cin.get();
    }
    //If the element is found but the balance is not zero output error message
    else if(!IsBalanceZero && Found)
    {
        std::cout << "Balance is not zero. Can't delete.";
        std::cout << "Press enter to continue..." << std::endl;
        std::cin.ignore(1000, '\n');
        std::cin.get();
    }
    
}

BankAccount::BankAccount()
{
    //Initilize the member variables
    firstName = " ";
    lastName = " ";
    accountType = " ";
    accountNumber = 0;
    balance = 0;
}

void BankAccount::AccountDetail(std::string name1, std::string name2, std::string accountT, int accountN, double bal)
{
    //Store the intended values in the member varaibles
    balance = bal;
    accountNumber = accountN;
    firstName = name1;
    lastName = name2;
    accountType = accountT;
    //Check if the account can be current or not
    if(balance < 50000 && accountType == "Current")
    {
        std::cout << "Account cannot be current, balance is less than 50000, it is set to basic." << std::endl;
        accountType = "Basic";
        std::cout << "Press enter to continue...";
        std::cin.ignore(1000, '\n');
        std::cin.get();
    }
}

void BankAccount::Transaction(double TransactionAmount)
{
    //Add the transaction amount into the balance
   balance += TransactionAmount;
   //If the transaction amount is negative this means we are ithdrawing so we have to change account type if balance falls below 500000
   if(TransactionAmount < 0)
   {
       if(balance < 50000)
       {
           accountType = "Basic";
           std::cout << "Balance is less than 50000. Account type is changed to \"Basic\"" << std::endl;
           std::cin.ignore(1000, '\n');
           std::cin.get();
       }
   }
}

void BankAccount::ChangeName()
{
    //Store the old name
    std::string oldFirstName = firstName;
    std::string oldLastName = lastName;
    //Ask user to input new name
    std::cout << "Enter new first name: ";
    std::cin >> firstName;
    std::cout << "Enter new last name: ";
    std::cin >> lastName;
    //Output success messsage
    std::cout << "Name of account number " << accountNumber << " has been successfully changed from ";
    std::cout << oldFirstName << " " << oldLastName << " to " << firstName << " " << lastName << "." << std::endl;
    std::cout << "Press enter to continue...";
    std::cin.ignore(1000, '\n');
    std::cin.get();
}

void BankAccount::changeType(std::string NewType)
{
    //If balance is less than 50000 account type will remain basic
    if(balance >= 50000 && NewType == "Basic")
    {
        accountType = "Basic";
        std::cout << "The account type is changed to \"Basic\"" << std::endl;
        std::cout << "Press enter to continue..." << std::endl;
        std::cin.ignore(1000, '\n');
        std::cin.get();
    }
    //If balance is more than or equal to 50000 account type can be Current or basic
    else if(balance >= 50000 && NewType == "Current")
    {
        accountType = "Current";
        std::cout << "The account type is changed to \"Current\"" << std::endl;
        std::cout << "Press enter to continue..." << std::endl;
        std::cin.ignore(1000, '\n');
        std::cin.get();
    }
    //Output error message if balance is less than 50000 and user wants to change account type to current
    else if(balance < 50000 && NewType == "Current")
    {
        std::cout << "Can't change account type to \"Current\" because balance is less than 50000" << std::endl;
        std::cout << "Press enter to continue...";
        std::cin.ignore(1000, '\n');
        std::cin.get();
    }
    
}

std::string BankAccount::GetFirstName()
{
    return firstName;
}

std::string BankAccount::GetLastName()
{
    return lastName;
}

double BankAccount::GetBalance()
{
    return balance;
}

int BankAccount::GetAccountNumber()
{
    return accountNumber;
}

std::string BankAccount::GetAccountType()
{
    return accountType;
}

void BankAccount::OutputBalance()
{
    //Output data for all the customer
    std::cout << "Name: " << GetFirstName() << " " << GetLastName() << std::endl;
    std::cout << "Account Number: " << GetAccountNumber() << std::endl;
    std::cout << "Account Balance: " << GetBalance() << std::endl;
    std::cout << "Press enter to continue..." << std::endl;
    std::cin.ignore(1000, '\n');
    std::cin.get();
}

void BankAccount::OutputType()
{
    //Output data for all the customer
    std::cout << "Name: " << GetFirstName() << " " << GetLastName() << std::endl;
    std::cout << "Account Number: " << GetAccountNumber() << std::endl;
    std::cout << "Account Type: " << GetAccountType() << std::endl;
    std::cout << "Press enter to continue..." << std::endl;
    std::cin.ignore(1000, '\n');
    std::cin.get();
}

void BankAccount::Output(int CustomerNumber)
{
    //Output data for all customers
    std::cout << "CUSTOMER " << CustomerNumber + 1 << std::endl;
    std::cout << "Name: " << GetFirstName() << " " << GetLastName() << std::endl;
    std::cout << "Account Type: " << GetAccountType() << std::endl;
    std::cout << "Account Number: " << GetAccountNumber() << std::endl;
    std::cout << "Account Balance: " << GetBalance() << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

