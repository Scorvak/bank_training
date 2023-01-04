#include "classes.h"

// Wallet class methods 

// Gets from the user the money input
void Bank::getDebit(int& index, int& user){getinputUser("How much did it cost ?", &(this->customers[user].ownWallet.balance.expenses[index]));}; 
void Bank::getCredit(int& index, int& user){getinputUser("How much did you get ?", &(this->customers[user].ownWallet.balance.profits[index]));};

// Computes the total benefit and expense of the user money
void Bank::computeWallet(int& user){

    Currency currency = this->customers[user].ownWallet.currency;
    float profits = sumArray(this->customers[user].ownWallet.balance.profits,this->customers[user].ownWallet.balance.sizeBalance);
    float expenses = sumArray(this->customers[user].ownWallet.balance.expenses,this->customers[user].ownWallet.balance.sizeBalance);
    
    std::cout << "Total profits: " << profits << "\n" << "Total expenses:" << expenses << std::endl;
    
    switch(currency)
    {
        case euro:
        this->customers[user].ownWallet.money.euro = this->customers[user].ownWallet.money.euro + profits - expenses;
        break;
        case dollar:
        this->customers[user].ownWallet.money.dollar = this->customers[user].ownWallet.money.dollar + profits - expenses;
        break;
        case yen:
        this->customers[user].ownWallet.money.yen = this->customers[user].ownWallet.money.yen + profits - expenses;
        break;

    }
};

// Shows available money in the wallet
int Bank::showWallet(int& user){return this->customers[user].ownWallet.money.euro;};
int Bank::showCurrency(int& user){return int(this->customers[user].ownWallet.currency);};

// Converts money in another currency
void Bank::convertCurrency(int& user){

    int choice;
    float money;
    std::string preconv, postconv;
    
    switch(this->customers[user].ownWallet.currency)
    {
        case Currency::dollar:
            money = this->customers[user].ownWallet.money.dollar;
            preconv = "dollar";
            getinputUser("In which currency do you want to convert your balance ?\n1.\teuro\n2.\tyen\n",&choice);
            if(choice == 1){this->customers[user].ownWallet.money.euro = money * 0.94; postconv = "euro"; this->customers[user].ownWallet.currency = euro; showConversion(money, &(this->customers[user].ownWallet.money.euro),preconv,postconv);}
            else if(choice == 2){this->customers[user].ownWallet.money.yen = money * 130.76; postconv = "yen"; this->customers[user].ownWallet.currency = yen; showConversion(money, &(this->customers[user].ownWallet.money.yen),preconv,postconv);}
            break;

        case Currency::euro:
            money = this->customers[user].ownWallet.money.euro;
            preconv = "euro";
            getinputUser("In which currency do you want to convert your balance ?\n1.\tdollar\n2.\tyen\n",&choice);
            if(choice == 1){this->customers[user].ownWallet.money.dollar = money * 1.07; postconv = "dollar"; this->customers[user].ownWallet.currency = dollar; showConversion(money, &(this->customers[user].ownWallet.money.dollar),preconv,postconv);}
            else if(choice == 2){this->customers[user].ownWallet.money.yen = money * 140.22; postconv = "yen"; this->customers[user].ownWallet.currency = yen; showConversion(money, &(this->customers[user].ownWallet.money.yen),preconv,postconv);}
            break;

        case Currency::yen:
            money = this->customers[user].ownWallet.money.yen;
            preconv = "yen";
            getinputUser("In which currency do you want to convert your balance ?\n1.\tdollar\n2.\teuro\n",&choice);
            if(choice == 1){this->customers[user].ownWallet.money.dollar = money * 0.0076; postconv = "dollar"; this->customers[user].ownWallet.currency = dollar; showConversion(money, &(this->customers[user].ownWallet.money.dollar),preconv,postconv);}
            else if(choice == 2){this->customers[user].ownWallet.money.euro = money * 0.0072; postconv = "euro"; this->customers[user].ownWallet.currency = euro; showConversion(money, &(this->customers[user].ownWallet.money.euro),preconv,postconv);}
            break;

    }

};

void Bank::showConversion(float& premoney, float* postmoney, std::string& preconv, std::string& postconv)
 {std::cout << "Successful conversion of your " << premoney << " " << preconv << " in " << *postmoney << " " << postconv << "." << std::endl;};


People::People(){this->ownWallet.money.euro = 0; this->ownWallet.currency = euro;};

void Bank::getName(int &user){getinputUser("Please enter your firstname:\n", &(this->customers[user].firstname));}
void Bank::getPassword(int &user){getinputUser("Please enter a password for your account:\n", &(this->customers[user].password));}
void Bank::getAge(int &user){getinputUser("Please enter your age:\n", &(this->customers[user].age));}

int Bank::showAge(int &user){return this->customers[user].age;}