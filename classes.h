#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

enum Currency {euro, dollar, yen};

struct Balance {
    float expenses[10] = {0};
    float profits[10] = {0};
    int nbexpenses = 10;
    int nbprofits = 10;
};

class Wallet {

private:

Balance balance;
Currency currency;

union {
    struct {
        float dollar;
        float euro;
        float yen;
    } money;
};
public:

// Asks user ow many times there will be a money input
void addDebit(int index);
void addCredit(int index);

// Gets from the user the money input
void askDebit();
void askCredit();

// Shows to the user how many inputs there are
int getDebit();
int getCredit();

// Computes the total benefit and expense of the user money
void computeWallet();

// Shows available money in the wallet
int showWallet();

// Converts money in another currency
void convertCurrency();
void showConversion(float& premoney,float* postmoney, string& preconv,string& postconv);


// cout << "Successful conversion of your " << money << " "<< preconv << "in " << this->money.dollar << " " << postconv << "." << endl;


friend class People;

};

class People {

private:
string firstname;
int age;
public:
Wallet ownWallet ; 
People();
void getName();
void getAge();
};


#endif