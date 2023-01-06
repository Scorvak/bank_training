#include "classes.h"

// Wallet class methods 

// Gets from the user the money input
void Bank::getDebit(int& index, int& user, int& tryUser, const std::string qUser, const int& threshold){

    if(tryUser == 0)
    {
        getinputUser(qUser,&(this->customers[user].ownWallet.balance.expenses[index]));
        tryUser++;
        getDebit(index, user, tryUser, "Incorrect money amount, please retry:", threshold);

    }else if(tryUser > 0 && this->customers[user].ownWallet.balance.expenses[index] < threshold)
    {
        getinputUser("Incorrect money amount, please retry:",&(this->customers[user].ownWallet.balance.expenses[index]));
        getDebit(index, user, tryUser, "Incorrect money amount, please retry:", threshold);
    }
    
}; 

void Bank::getCredit(int& index, int& user, int& tryUser, const std::string qUser, const int& threshold){

    if(tryUser == 0)
    {
        getinputUser(qUser,&(this->customers[user].ownWallet.balance.profits[index]));
        tryUser++;
        getCredit( index, user, tryUser, "Incorrect money amount, please retry:", threshold);

    }else if(tryUser >0 && this->customers[user].ownWallet.balance.profits[index] < threshold)
    {
        getinputUser("Incorrect money amount, please retry:", &(this->customers[user].ownWallet.balance.profits[index]));
        tryUser++;
        getCredit( index, user, tryUser, "Incorrect money amount, please retry:", threshold);  
        }
    else{
        tryUser = 0;
    }
 };

// Computes the total benefit and expense of the user money
void Bank::computeWallet(int& user, float& profits, float& expenses){

    profits = sumArray(this->customers[user].ownWallet.balance.profits,SIZE_BALANCE);
    expenses = sumArray(this->customers[user].ownWallet.balance.expenses,SIZE_BALANCE);

    this->resetExpenses(user);
    this->resetProfits(user);

    std::cout << "Total profits: " << profits << "\n" << "Total expenses: " << expenses << std::endl;
    
    switch(this->customers[user].ownWallet.currency)
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

void Bank::resetWallet(int& user){

 switch(this->customers[user].ownWallet.currency)
    {
        case euro:
        this->customers[user].ownWallet.money.euro = 0;
        break;
        case dollar:
        this->customers[user].ownWallet.money.dollar = 0;
        break;
        case yen:
        this->customers[user].ownWallet.money.yen = 0;
        break;

    }

};

// Shows available money in the wallet
int Bank::showWallet(int& user){return this->customers[user].ownWallet.money.euro;};
int Bank::showCurrency(int& user){return int(this->customers[user].ownWallet.currency);};

// Converts money in another currency
void Bank::convertCurrency(int& user, int& choice, float& money, std::string& preconv, std::string& postconv){

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

// Checks user firstname and password for accessing account
bool Bank::checkUser(bool* access, int& userCheck, std::string& inputName, std::string& password){

    getinputUser("Pleaser enter your firstname:\n",inputName);
    for(int i = 0; i<this->sizeUsers; i++)
    {
        if(inputName == this->customers[i].firstname){access[1] = true;userCheck = i;std::cout << "TEST" << std::endl;}

    }
    if(access[1])
    {

    std::cout << "Hello " << showName(userCheck);getinputUser(", please enter your password:\n",password);

    if(password == this->customers[userCheck].password){std::cout << "Sucessful access\n" << std::endl;access[2] =  true;}
    else{std::cout << "Failed access\n" << std::endl; access[2] = false;}

        return access[2];
    }
    else{
        std::cout << "Sorry, we can't find your account with your name. Please retry again or open a new account through the main menu." << std::endl;
        return false;
    }

};

// Resets profits and expenses
    void Bank::resetProfits(int& user){

        std::fill(this->customers[user].ownWallet.balance.profits, this->customers[user].ownWallet.balance.profits + SIZE_BALANCE,0.0f);

    };
    void Bank::resetExpenses(int& user){

        std::fill(this->customers[user].ownWallet.balance.expenses, this->customers[user].ownWallet.balance.expenses + SIZE_BALANCE,0.0f);
    };


People::People(){this->ownWallet.money.euro = 0; this->ownWallet.currency = euro;};

void Bank::getName(int &user){getinputUser("Please enter your firstname:\n", &(this->customers[user].firstname));}
void Bank::getPassword(int &user){getinputUser("Please enter a password for your account:\n", &(this->customers[user].password));}
void Bank::getAge(int &user){getinputUser("Please enter your age:\n", &(this->customers[user].age));}

int Bank::showAge(int &user){return this->customers[user].age;}
std::string Bank::showName(int &user){return this->customers[user].firstname;};