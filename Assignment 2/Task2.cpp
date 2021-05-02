#include <iostream>
#include <iomanip>

struct starters
{
    std::string one = "Fruit Salad";
    std::string two = "Fish Crackers";
    std::string three = "Chicken Soup";
    std::string four = "Chips";
    const int fruitSalad = 220;
    const int fishCrackers = 150;
    const int chickenSoup = 200;
    const int chips = 100;
};
struct chinese
{
    std::string one = "Chicken Manchurian";
    std::string two = "Chicken Chowmien";
    std::string three = "American Chopsuey";
    std::string four = "Black Pepper Chicken";
    const int chickenManchurian = 450;
    const int chickenChowmien = 475;
    const int americanChopsuey = 520;
    const int blackPepperChicken = 450; 
};
struct continental
{
    std::string one = "Chicken Karahi";
    std::string two = "Chicken Handi";
    std::string three = "Mutton Handi";
    std::string four = "Beef Handi";
    const int chickenKarahi = 850;
    const int chickenHandi = 950;
    const int muttonHandi = 1250;
    const int beefHandi = 1050;
};
struct fastFood
{
    std::string one = "Chicken Burger";
    std::string two = "Chicken Nuggets";
    std::string three = "Chicken Sandwich";
    std::string four = "fries";
    const int chickenBurger = 450;
    const int chickenNuggets = 325;
    const int chickenSandwich = 330;
    const int fries = 150;
};
struct coldDrinks
{
    std::string one = "Coke";
    std::string two = "Sprite";
    std::string three = "Miranda";
    const int coke = 100;
    const int sprite = 100;
    const int miranda = 100;
};
struct sweetDish 
{
    std::string one = "Kheer";
    std::string two = "Firni";
    std::string three = "Kulfa";
    std::string four = "Gulab Jamon";
    const int kheer = 350;
    const int firni = 300;
    const int kulfa = 40;
    const int gulabJamon = 250;
};
struct receipt
{
    int dishQuantity;
    int dishPrice;
    std::string dishName;
};

bool choiceValidation(int choice, int upperbound);
bool quantityValidation(int choice);
void menu(int &menuChoice);
void quantityMenu(int &quantity, std::string dishName);
bool orderAgainMenu();
void startersMenu(int &dishChoice);
void chineseMenu(int &dishChoice);
void continentalMenu(int &dishChoice);
void fastFoodMenu(int &dishChoice);
void coldDrinksMenu(int &dishChoice);
void sweetDishMenu(int &dishChoice);
void calculatePrice(receipt receiptArray[], int arraySize, int price, std::string name, int quantity);
void receiptMenu(receipt receiptArray[], int arraySize);
void thankyouMenu();

int main()
{
    int menuChoice = 0, dishChoice = 0, quantity, arraySize = 23;
    bool correctChoice = false, orderAgain = true;
    struct receipt receiptArray[23];
    struct starters starters;
    struct chinese chinese;
    struct continental continental;
    struct fastFood fastFood;
    struct coldDrinks coldDrinks;
    struct sweetDish sweetDish;
    
    system("cls");

    //Initilize the receipt array
    for(int i = 0; i < arraySize; ++i)
    {
        receiptArray[i].dishName = " ";
        receiptArray[i].dishPrice = 0;
        receiptArray[i].dishQuantity = 0;
    }

    //Main loop (runs until we exit the menu)
    while(menuChoice != 7 && orderAgain == true)
    {
        //Input and validate the menu choice
        while(correctChoice == false)
        {
            menu(menuChoice);
            correctChoice = choiceValidation(menuChoice, 7);
        }
        correctChoice = false;
        //Ouput the menu according the the choice
        switch (menuChoice)
        {
            //Starters choice
            case 1:
            {
                //Select the starters dish or exit to main menu
                //Input and validate the dish choice
                while(correctChoice == false)
                {
                    startersMenu(dishChoice);
                    correctChoice = choiceValidation(dishChoice, 5);
                }
                correctChoice = false;
                //Enter the quantity of the selected dish
                switch(dishChoice)
                {
                    //In case of 1st dish
                    case 1:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, starters.one);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, starters.fruitSalad, starters.one, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 2nd dish
                    case 2:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, starters.two);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, starters.fishCrackers, starters.two, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 3rd dish
                    case 3:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, starters.three);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, starters.chickenSoup, starters.three, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 4th dish
                    case 4:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, starters.four);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, starters.chips, starters.four, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //Exit to the starters menu
                    case 5:
                    {
                        break;
                    }
                }
                break;
            }
    
            //Chinese choice
            case 2:
            {
                //Select the chinese dish or exit to main menu
                //Input and validate the dish choice
                while(correctChoice == false)
                {
                    chineseMenu(dishChoice);
                    correctChoice = choiceValidation(dishChoice, 5);
                }
                correctChoice = false;
                //Enter the quantity of the selected dish
                switch(dishChoice)
                {
                    //In case of 1st dish
                    case 1:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, chinese.one);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, chinese.chickenManchurian, chinese.one, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 2nd dish
                    case 2:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, chinese.two);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, chinese.chickenChowmien, chinese.two, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 3rd dish
                    case 3:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, chinese.three);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, chinese.americanChopsuey, chinese.three, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 4th dish
                    case 4:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, chinese.four);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, chinese.blackPepperChicken, starters.four, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //Exit to the starters menu
                    case 5:
                    {
                        break;
                    }
                }
                break;
            }
            
            //Continental choice
            case 3:
            {
                //Select the continental dish or exit to main menu
                //Input and validate the dish choice
                while(correctChoice == false)
                {
                    continentalMenu(dishChoice);
                    correctChoice = choiceValidation(dishChoice, 5);
                }
                correctChoice = false;
                //Enter the quantity of the selected dish
                switch(dishChoice)
                {
                    //In case of 1st dish
                    case 1:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, continental.one);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, continental.chickenKarahi, continental.one, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 2nd dish
                    case 2:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, continental.two);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, continental.chickenHandi, continental.two, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 3rd dish
                    case 3:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, continental.three);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, continental.muttonHandi, chinese.three, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 4th dish
                    case 4:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, continental.four);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, continental.beefHandi, starters.four, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //Exit to the starters menu
                    case 5:
                    {
                        break;
                    }
                }
                break;
            }

            //Fast food choice
            case 4:
            {
                //Select the fastfood dish or exit to main menu
                //Input and validate the dish choice
                while(correctChoice == false)
                {
                    fastFoodMenu(dishChoice);
                    correctChoice = choiceValidation(dishChoice, 5);
                }
                correctChoice = false;
                //Enter the quantity of the selected dish
                switch(dishChoice)
                {
                    //In case of 1st dish
                    case 1:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, fastFood.one);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, fastFood.chickenBurger, fastFood.one, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 2nd dish
                    case 2:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, fastFood.two);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, fastFood.chickenNuggets, fastFood.two, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 3rd dish
                    case 3:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, fastFood.three);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, fastFood.chickenSandwich, fastFood.three, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 4th dish
                    case 4:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, fastFood.four);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, fastFood.fries, fastFood.four, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //Exit to the starters menu
                    case 5:
                    {
                        break;
                    }
                }
                break;
            }

            //Cold drink choice
            case 5:
            {
                //Select the cold drink or exit to main menu
                //Input and validate the dish choice
                while(correctChoice == false)
                {
                    coldDrinksMenu(dishChoice);
                    correctChoice = choiceValidation(dishChoice, 4);
                }
                correctChoice = false;
                //Enter the quantity of the selected dish
                switch(dishChoice)
                {
                    //In case of 1st drink
                    case 1:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, coldDrinks.one);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, coldDrinks.coke, coldDrinks.one, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 2nd drink
                    case 2:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, coldDrinks.two);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, coldDrinks.sprite, coldDrinks.two, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 3rd drink
                    case 3:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, coldDrinks.three);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, coldDrinks.miranda, coldDrinks.three, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //Exit to the starters menu
                    case 4:
                    {
                        break;
                    }
                }
                break;
            }

            //Sweet dish choice
            case 6:
            {
                //Select the sweet dish or exit to main menu
                //Input and validate the dish choice
                while(correctChoice == false)
                {
                    sweetDishMenu(dishChoice);
                    correctChoice = choiceValidation(dishChoice, 5);
                }
                correctChoice = false;
                //Enter the quantity of the selected dish
                switch(dishChoice)
                {
                    //In case of 1st dish
                    case 1:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, sweetDish.one);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, sweetDish.kheer, sweetDish.one, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 2nd dish
                    case 2:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, sweetDish.two);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, sweetDish.firni, sweetDish.two, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 3rd dish
                    case 3:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, sweetDish.three);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, sweetDish.kulfa, sweetDish.three, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //In case of 4th dish
                    case 4:
                    {
                        //Input and validate quantity
                        while(correctChoice == false)
                        {
                            quantityMenu(quantity, sweetDish.four);
                            correctChoice = quantityValidation(quantity);
                        }
                        calculatePrice(receiptArray, arraySize, sweetDish.gulabJamon, sweetDish.four, quantity);
                        correctChoice = false;
                        orderAgain = orderAgainMenu();
                        break;
                    }
                    //Exit to the starters menu
                    case 5:
                    {
                        break;
                    }
                }
                break;
            }
            
            dishChoice = 0;
        }
    }
    receiptMenu(receiptArray, arraySize);
    thankyouMenu();
    return 0;
}

bool choiceValidation(int choice, int upperBound)
{
    if(std::cin.fail() || choice < 1 || choice > upperBound)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry!" << std::endl;
        return false;
    }
    else
    {
        return true;
    }   
}

bool quantityValidation(int choice)
{
    if(std::cin.fail() || choice < 0)
    {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Wrong entry!" << std::endl;
        return false;
    }
    else
    {
        return true;
    }   
}

void menu(int &menuChoice)
{
    std::cout << "**********************MENU**********************" << std::endl << std::endl;
    std::cout << "Please select the category of food you would like to order" << std::endl;
    std::cout << "1) Starters" << std::endl;
    std::cout << "2) Chinese" << std::endl;
    std::cout << "3) Continental" << std::endl;
    std::cout << "4) Fast food" << std::endl;
    std::cout << "5) Cold drinks" << std::endl;
    std::cout << "6) Sweet dish" << std::endl;
    std::cout << "7) Exit the menu" << std::endl;
    std::cout << "Choice: ";
    std::cin >> menuChoice;
    system("cls");
}

void startersMenu(int &dishChoice)
{
    struct starters menu;
    std::cout << "Which starter would you like to order? Please enter the digit" << std::endl << std::endl;
    std::cout << std::left << std::setw(30) << "1) Fruit salad"  << menu.fruitSalad << std::endl;
    std::cout << std::left << std::setw(30) << "2) Fish Crackers" << menu.fishCrackers << std::endl;
    std::cout << std::left << std::setw(30) << "3) Chicken Soup" << menu.chickenSoup << std::endl;
    std::cout << std::left << std::setw(30) << "4) Chips" << menu.chips << std::endl;
    std::cout << std::left << std::setw(30) << "5) Main menu" << std::endl;
    std::cout << "Choice: ";
    std::cin >> dishChoice;
    system("cls");
}

void chineseMenu(int &dishChoice)
{
    struct chinese menu;
    std::cout << "Which chinese would you like to order? Please enter the digit" << std::endl << std::endl;
    std::cout << std::left << std::setw(30) << "1) Chicken Manchurian"  << menu.chickenManchurian << std::endl;
    std::cout << std::left << std::setw(30) << "2) Chicken Chowmien" << menu.chickenChowmien << std::endl;
    std::cout << std::left << std::setw(30) << "3) American Chopsuey" << menu.americanChopsuey << std::endl;
    std::cout << std::left << std::setw(30) << "4) Black Pepper Chicken" << menu.blackPepperChicken << std::endl;
    std::cout << std::left << std::setw(30) << "5) Main menu" << std::endl;
    std::cout << "Choice: ";
    std::cin >> dishChoice;
    system("cls");
}

void continentalMenu(int &dishChoice)
{
    struct continental menu;
    std::cout << "Which continental would you like to order? Please enter the digit" << std::endl << std::endl;
    std::cout << std::left << std::setw(30) << "1) Chicken Karahi"  << menu.chickenKarahi << std::endl;
    std::cout << std::left << std::setw(30) << "2) Chicken Handi" << menu.chickenHandi << std::endl;
    std::cout << std::left << std::setw(30) << "3) Mutton Handi" << menu.muttonHandi << std::endl;
    std::cout << std::left << std::setw(30) << "4) Beef handi" << menu.beefHandi << std::endl;
    std::cout << std::left << std::setw(30) << "5) Main menu" << std::endl;
    std::cout << "Choice: ";
    std::cin >> dishChoice;
    system("cls");
}

void fastFoodMenu(int &dishChoice)
{
    struct fastFood menu;
    std::cout << "Which fast food would you like to order? Please enter the digit" << std::endl << std::endl;
    std::cout << std::left << std::setw(30) << "1) Chicken Burger"  << menu.chickenBurger << std::endl;
    std::cout << std::left << std::setw(30) << "2) Chicken Nuggets" << menu.chickenNuggets << std::endl;
    std::cout << std::left << std::setw(30) << "3) Chicken Sandwitch" << menu.chickenSandwich << std::endl;
    std::cout << std::left << std::setw(30) << "4) Fries" << menu.fries << std::endl;
    std::cout << std::left << std::setw(30) << "5) Main menu" << std::endl;
    std::cout << "Choice: ";
    std::cin >> dishChoice;
    system("cls");
}

void coldDrinksMenu(int &dishChoice)
{
    struct coldDrinks menu;
    std::cout << "Which chinese would you like to order? Please enter the digit" << std::endl << std::endl;
    std::cout << std::left << std::setw(30) << "1) Coke"  << menu.coke << std::endl;
    std::cout << std::left << std::setw(30) << "2) Sprite" << menu.sprite << std::endl;
    std::cout << std::left << std::setw(30) << "3) Miranda" << menu.miranda << std::endl;
    std::cout << std::left << std::setw(30) << "4) Main menu" << std::endl;
    std::cout << "Choice: ";
    std::cin >> dishChoice;
    system("cls");
}

void sweetDishMenu(int &dishChoice)
{
    struct sweetDish menu;
    std::cout << "Which chinese would you like to order? Please enter the digit" << std::endl << std::endl;
    std::cout << std::left << std::setw(30) << "1) Kheer"  << menu.kheer << std::endl;
    std::cout << std::left << std::setw(30) << "2) Firni" << menu.firni << std::endl;
    std::cout << std::left << std::setw(30) << "3) Kulfa" << menu.kulfa << std::endl;
    std::cout << std::left << std::setw(30) << "4) Gulab Jamon" << menu.gulabJamon << std::endl;
    std::cout << std::left << std::setw(30) << "5) Main menu" << std::endl;
    std::cout << "Choice: ";
    std::cin >> dishChoice;
    system("cls");
}

void quantityMenu(int &quantity, std::string dishName)
{
    std::cout << "How many " << dishName << " would you like to order?" << std::endl;
    std::cout << "Quantity: ";
    std::cin >> quantity;
    system("cls");
}

bool orderAgainMenu()
{
    char choice;
    std::cout << "Do you want to order again? (Y/N)" << std::endl;
    std::cout << "Choice: ";
    std::cin >> choice;
    while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
    {
        system("cls");
        std::cout << "Wrong entry!" << std::endl;
        std::cout << "Do you want to order again? (Y/N)" << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;
    }
    if(choice == 'y' || choice == 'Y')
    {
        system("cls");
        return true;
    }
    else
    {
        system("cls");
        return false;
    }
}

void calculatePrice(receipt receiptArray[], int arraySize, int price, std::string name, int quantity)
{
    bool found = false;
    int position;
    for(int i = 0; i < arraySize; ++i)
    {
        if(receiptArray[i].dishName == name)
        {
            found = true;
            position = i;
            break;
        }
        else if(receiptArray[i].dishName == " ")
        {
            position = i;
            break;
        }
    }
    if(found == false && quantity > 0)
    {
        receiptArray[position].dishName = name;
        receiptArray[position].dishPrice += (quantity * price);
        receiptArray[position].dishQuantity += quantity;
    }
    else
    {
        receiptArray[position].dishPrice = receiptArray[position].dishPrice + (quantity * price);
        receiptArray[position].dishQuantity += quantity;
    }
}

void receiptMenu(receipt receiptArray[], int arraySize)
{
    if(receiptArray[0].dishName != " ")
    {
        int price = 0;
        std::cout << "YOUR RECEIPT:" << std::endl << std::endl;
        std::cout << "******************************************* RECEIPT *******************************************" << std::endl;
        std::cout << std::setw(30) << "NAME";
        std::cout << std::setw(10) << "UNIT";
        std::cout << std::setw(15) << "PRICE";
        std::cout << std::setw(20) << "QUANTITY";
        std::cout << std::setw(10) << "TOTAL";
        std::cout << std::setw(10) << "PRICE" << std::endl << std::endl;
        for(int i = 0; i < arraySize; ++i)
        {
            if(receiptArray[i].dishName == " ")
            {
                break;
            }
            std::cout << std::setw(30) << receiptArray[i].dishName;
            std::cout << std::setw(10) << "Rs";
            std::cout << std::setw(15) << receiptArray[i].dishPrice/receiptArray[i].dishQuantity;
            std::cout << std::setw(20) << receiptArray[i].dishQuantity;
            std::cout << std::setw(10) << "Rs";
            std::cout << receiptArray[i].dishPrice << std::endl;
            price += receiptArray[i].dishPrice;
        }
        std::cout << std::endl;
        std::cout << std::setw(30) << "Total";
        std::cout << std::right << std::setw(37) << " ";
        std::cout << std::setw(10) << "Rs";
        std::cout << std::setw(11) << price << std::endl;
        std::cout << "***********************************************************************************************";
    }
}

void thankyouMenu()
{
    std::cout << std::endl << std::endl << "Enter any key to contunue to continue...";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cin.get();
    system("cls");
    std::cout << std::setw(40) << "THANK YOU" << std::endl;
    std::cout << std::setw(41) << "FOR COMMING" << std::endl;
    std::cout << std::setw(45) << "TO OUR RESTAURANT." << std::endl;
    std::cout << std::setw(41) << "PLEASE COME" << std::endl;
    std::cout << std::setw(41) << "BACK SOON." << std::endl;
}