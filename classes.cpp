#include "basics.h"
#include "classes.h"


// Wallet class methods 

void Wallet::addDebit(int index){getinputUser("How much did it cost ?", &(this->balance.expenses[index]));};
void Wallet::addCredit(int index){getinputUser("How much did you get ?", &(this->balance.profits[index]));};
void Wallet::askDebit(){getinputUser("How many items did you buy ?", &(this->balance.nbexpenses));};
void Wallet::askCredit(){getinputUser("How many funds did you get ?", &(this->balance.nbprofits));};

int Wallet::getDebit(){return this->balance.nbexpenses;};
int Wallet::getCredit(){return this->balance.nbprofits;};

void Wallet::computeWallet(){
    
    cout << "Total profits: " << sumArray(this->balance.profits,this->balance.nbprofits) << "\n" << "Total expenses:" <<  sumArray(this->balance.expenses,balance.nbexpenses) << endl;
    
    this->money = this-> money + (sumArray(this->balance.profits,this->balance.nbprofits) - sumArray(this->balance.expenses,balance.nbexpenses));
    
    
    
    };
int Wallet::showWallet(){return this->money;};

void Wallet::convertCurrency(){};

// People class methods

People::People(){this->ownWallet.money = 2000;};

void People::getName(){getinputUser("What is your firstname ?", &(this->firstname));}
void People::getAge(){getinputUser("How old are you ?", &(this->age));}

