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

int Wallet::showWallet(){return this->money.euro;};

void Wallet::convertCurrency(){

    int choice;

    do{

        getinputUser("In which currency do you want to convert your money ?\n1.\teuro\n2.\tdollar\n3.\tyen\n",&choice);

    if(choice != 1 && choice != 2 && choice != 3){std::cout << "Please chose a valid currency." << std::endl;}

    }while(choice != 1 && choice != 2 && choice != 3);

    float money = this->money.euro;

    switch (choice)
    {
    case 1:
        this->currency = euro;
        std::cout << "The currency was already in euro, no conversion occured." << std::endl;
        break;
    case 2:
        this->currency = dollar;
        this->money.dollar = money * 1.07;
        cout << "Your " << money << "euro have been converted into " << this->money.dollar << " dollar." << std::endl;
        break;
    case 3:
        this->currency = yen;
        this->money.dollar = money * 140.22;
        cout << "Your " << money << "euro have been converted into " << this->money.yen << " yen." << std::endl;
        break;
    }


};

// People class methods

People::People(){this->ownWallet.money.euro = 2000; this->ownWallet.currency = euro;};

void People::getName(){getinputUser("What is your firstname ?", &(this->firstname));}
void People::getAge(){getinputUser("How old are you ?", &(this->age));}

