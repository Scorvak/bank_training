#include "basics.h"
#include "classes.h"


// Wallet class methods 

// Asks user ow many times there will be a money input
void Wallet::askDebit(){getinputUser("How many items did you buy ?", &(this->balance.nbexpenses));};
void Wallet::askCredit(){getinputUser("How many funds did you get ?", &(this->balance.nbprofits));};

// Gets from the user the money input
void Wallet::addDebit(int index){getinputUser("How much did it cost ?", &(this->balance.expenses[index]));};
void Wallet::addCredit(int index){getinputUser("How much did you get ?", &(this->balance.profits[index]));};

// Shows to the user how many inputs there are
int Wallet::getDebit(){return this->balance.nbexpenses;};
int Wallet::getCredit(){return this->balance.nbprofits;};

// Computes the total benefit and expense of the user money
void Wallet::computeWallet(){
    
    std::cout << "Total profits: " << sumArray(this->balance.profits,this->balance.nbprofits) << "\n" << "Total expenses:" <<  sumArray(this->balance.expenses,balance.nbexpenses) << endl;
    
    this->money.euro = this-> money.euro + (sumArray(this->balance.profits,this->balance.nbprofits) - sumArray(this->balance.expenses,balance.nbexpenses));
    
    };

// Shows available money in the wallet
int Wallet::showWallet(){return this->money.euro;};

// Converts money in another currency
void Wallet::convertCurrency(){

    int choice;
    float money;
    string preconv, postconv;
    
    switch(this->currency)
    {
        case Currency::dollar:
            money = this->money.dollar;
            preconv = "dollar";
            getinputUser("In which currency do you want to convert your money ?\n1.\teuro\n2.\tyen\n",&choice);
            if(choice == 1){this->money.euro = money * 0.94; postconv = "euro"; this->currency = euro; showConversion(money, &(this->money.euro),preconv,postconv);}
            else if(choice == 2){this->money.yen = money * 130.76; postconv = "yen"; this->currency = yen; showConversion(money, &(this->money.yen),preconv,postconv);}
            break;

        case Currency::euro:
            money = this->money.euro;
            preconv = "euro";
            getinputUser("In which currency do you want to convert your money ?\n1.\tdollar\n2.\tyen\n",&choice);
            if(choice == 1){this->money.dollar = money * 1.07; postconv = "dollar"; this->currency = dollar; showConversion(money, &(this->money.dollar),preconv,postconv);}
            else if(choice == 2){this->money.yen = money * 140.22; postconv = "yen"; this->currency = yen; showConversion(money, &(this->money.yen),preconv,postconv);}
            break;

        case Currency::yen:
            money = this->money.yen;
            preconv = "yen";
            getinputUser("In which currency do you want to convert your money ?\n1.\tdollar\n2.\teuro\n",&choice);
            if(choice == 1){this->money.dollar = money * 0.0076; postconv = "dollar"; this->currency = dollar; showConversion(money, &(this->money.dollar),preconv,postconv);}
            else if(choice == 2){this->money.euro = money * 0.0072; postconv = "euro"; this->currency = euro; showConversion(money, &(this->money.euro),preconv,postconv);}
            break;

    }


};

void Wallet::showConversion(float& premoney, float* postmoney, string& preconv, string& postconv)
 {std::cout << "Successful conversion of your " << premoney << " " << preconv << " in " << *postmoney << " " << postconv << "." << std::endl;};

// People class methods

People::People(){this->ownWallet.money.euro = 2000; this->ownWallet.currency = euro;};

void People::getName(){getinputUser("What is your firstname ?", &(this->firstname));}
void People::getAge(){getinputUser("How old are you ?", &(this->age));}
