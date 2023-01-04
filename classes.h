#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "basics.h"

enum Currency {euro, dollar, yen};
const std::string currency[3] = {"euro","dollar","yen"};

struct Balance {
    float expenses[10] = {0};
    float profits[10] = {0};
    int nbexpenses = 0;
    int nbprofits = 0;
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
    int showCurrency();

// Converts money in another currency
    void convertCurrency();
    void showConversion(float& premoney,float* postmoney, std::string& preconv, std::string& postconv);


friend class People;

};

class People {

private:
    std::string firstname;
    std::string password;
    int age;
public:
    Wallet ownWallet ; 
    People();
    int showAge();
    void getName();
    void getAge();
    void getPassword();
};


#endif