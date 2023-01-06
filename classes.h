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
    const int sizeBalance = 10;
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
    std::string firstname;
    std::string password;
    int age;
public:
    Wallet ownWallet ; 
    People();
    friend class Bank;

};


class Bank {

private:
    People customers[5];
    enum Users {user1,user2,user3,user4,user5};
    Users currentUser;
    const int sizeUsers = 5;
public:

    void getName(int &user);
    void getAge(int &user);
    void getPassword(int &user);

    int showAge(int &user);
    std::string showName(int &user);

// Gets from the user the money input
    void getDebit(int& index, int& user);
    void getCredit(int& index, int& user);

// Computes the total benefit and expense of the user money
    void computeWallet(int& user, float& profits, float& expenses);

// Shows available money in the wallet
    int showWallet(int& user);
    int showCurrency(int& user);

// Converts money in another currency
    void convertCurrency(int& user, int& choice, float& money, std::string& preconv, std::string& postconv);
    void showConversion(float& premoney,float* postmoney, std::string& preconv, std::string& postconv);

// Checks user firstname and password for accessing account
    bool checkUser(bool* access, int& userCheck, std::string& inputName, std::string& password);

};

#endif