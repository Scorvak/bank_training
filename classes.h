#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "basics.h"

#define SIZE_BALANCE 10
#define SIZE_CUSTOMERS 5
#define RATE_CONVERSION 0.025

enum Currency {euro, dollar, yen};
const std::string currency[3] = {"euro","dollar","yen"};

struct Balance {
    float expenses[SIZE_BALANCE];
    float profits[SIZE_BALANCE];
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
    friend class People;
    friend class Bank;

};

class People {

private:
    std::string firstname = "userfree";
    std::string password;
    int age;
public:
    Wallet ownWallet ; 
    People();
    friend class Bank;

};


class Bank {

private:
    People customers[SIZE_CUSTOMERS];
public:

    void getName(int &user);
    void getAge(int &user);
    void getPassword(int &user);

    int showAge(int &user);
    std::string showName(int &user);

// Gets from the user the money input
    void getDebit(int& user, int& index, int& tryUser, const std::string qUser, const int& threshold);
    void getCredit(int& user, int& index, int& tryUser, const std::string qUser, const int& threshold);

// Computes the total benefit and expense of the user money
    void computeWallet(int& user, float& profits, float& expenses);
    void resetWallet(int& user);

// Shows available money in the wallet
    float showWallet(int& user, float& money);
    int showCurrency(int& user);

// Converts money in another currency
    void convertCurrency(int& user, int& choice, float& money, std::string& preconv, std::string& postconv);
    void showConversion(float& premoney,float* postmoney, std::string& preconv, std::string& postconv);

// Checks user firstname and password for accessing account
    bool checkUser(bool* access, int& userCheck, int& userspot, std::string& inputName, std::string& password);
    void checkSpot(bool& access, int& user, int& userfree);

// Resets profits and expenses
    void resetProfits(int& user);
    void resetExpenses(int& user);

// Repeats operation 
    void repeatOperation(int& user, int& index, int& tryUser, int& iniLoop, std::string stringUser, const std::string qUser, const int& threshold, void (Bank::*function)(int&,int&,int&,const std::string, const int&));


};

#endif