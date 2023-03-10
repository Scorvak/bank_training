#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "basics.h"

#define SIZE_DB 5
#define SIZE_BALANCE 10
#define SIZE_FRIENDS 5
#define SIZE_CUSTOMERS 10
#define RATE_CONVERSION 0.025


namespace Entities
{



enum Currency {euro, dollar, yen};

struct DataBase {

    bool boolBase[SIZE_DB];
    int intBase[SIZE_DB];
    float floatBase[SIZE_DB];
    std::string stringBase[SIZE_DB];
};

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
    std::string friends [SIZE_FRIENDS];
    int age;
public:
    Wallet ownWallet ; 
    People();
    friend class Bank;

};

class Bank {

private:
    int ID_customers[SIZE_CUSTOMERS];
    People customers[SIZE_CUSTOMERS];
    DataBase bankDB;
    std::string currencies[3] = {"euro","dollar","yen"};
public:

    Bank();

    void getName();
    void getAge();
    void getPassword();
    void getChoice(const std::string& displayMenu);

    int showAge();
    int showChoice();

    bool showBool(const int& check);
    std::string showName();

// Gets from the user the money input
    void getDebit(const std::string& qUser, const int& threshold);
    void getCredit(const std::string& qUser, const int& threshold);

// Computes the total benefit and expense of the user money
    void computeWallet();
    void resetWallet();

// Shows available money in the wallet
    float showWallet();
    std::string showCurrency();
// Converts money in another currency
    void convertCurrency();

// Checks user firstname and password for accessing account
    void checkUser(const std::string& qUser);
    void checkSpot(const std::string& rUser);
    void checkFriend(const std::string& rUser);

// Resets profits and expenses
    void resetProfits();
    void resetExpenses();

// Repeats operation 
    void repeatOperation(const std::string& qUser, const int& threshold, void (Bank::*function)(const std::string&, const int&));

// Methods related to customer's friends
    void resetFriends();
    void addFriend();
    void showFriends();
    void transfer2friend();

// Resets bank database
    void resetDB(const int& index);
};

}

#endif