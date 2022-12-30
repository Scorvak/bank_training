#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

struct Balance {

    int expenses[10] = {0};
    int profits[10] = {0};
    int nbexpenses = 10;
    int nbprofits = 10;
};

class Wallet {

private:

Balance balance;

int money;

union {
    struct {
        float dollar;
        float euro;
        float yen;
    } Currency;
};
public:

void addDebit(int index);
void addCredit(int index);
void askDebit();
void askCredit();
int getDebit();
int getCredit();
void computeWallet();
int showWallet();
void convertCurrency();

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