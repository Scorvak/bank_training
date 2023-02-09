#include "classes.h"

// Wallet class methods 

// Gets from the user the money input
void Bank::getDebit(int& user, int& index, int& tryUser, const std::string& qUser, std::string& inputUser, const int& threshold){

    if(tryUser == 0)
    {
        getinputUser(qUser, inputUser,&(this->customers[user].ownWallet.balance.expenses[index]));
        tryUser++;
        getDebit(user, index, tryUser, "Incorrect money amount, please retry:", inputUser, threshold);

    }else if(tryUser > 0 && this->customers[user].ownWallet.balance.expenses[index] < threshold)
    {
        getinputUser("Incorrect money amount, please retry:", inputUser, &(this->customers[user].ownWallet.balance.expenses[index]));
        tryUser++;
        getDebit(user, index, tryUser, "Incorrect money amount, please retry:", inputUser, threshold);
    }else if(tryUser > 0 && this->customers[user].ownWallet.balance.expenses[index] >= threshold){tryUser = 0;}

}; 

void Bank::getCredit(int& user, int& index, int& tryUser, const std::string& qUser, std::string& inputUser, const int& threshold){

    if(tryUser == 0)
    {
        getinputUser(qUser, inputUser, &(this->customers[user].ownWallet.balance.profits[index]));
        tryUser++;
        getCredit(user, index, tryUser, "Incorrect money amount, please retry:", inputUser, threshold);

    }else if(tryUser > 0 && this->customers[user].ownWallet.balance.profits[index] < threshold)
    {
        getinputUser("Incorrect money amount, please retry:", inputUser, &(this->customers[user].ownWallet.balance.profits[index]));
        tryUser++;
        getCredit( user, index, tryUser, "Incorrect money amount, please retry:", inputUser, threshold);  
    }else if(tryUser > 0 && this->customers[user].ownWallet.balance.profits[index] >= threshold){tryUser = 0;}
 };

// Repeats operations for user



 void Bank::repeatOperation(int& user, int& index, int& tryUser, int& iniLoop, std::string& stringUser, const std::string& qUser, const int& threshold, void (Bank::*function)(int&,int&,int&,const std::string&, const int&))
 {
    index = 0;
    tryUser = 0;
    iniLoop = 0;

    do{

        (this->*function)(user, index, tryUser, qUser, threshold);
        getinputUser("Do you want to add one more operation ?", stringUser);
        if(stringUser == "yes" || stringUser == "Yes"){iniLoop++; index++; tryUser = 0;}

    }while(stringUser == "yes" || stringUser == "Yes" && iniLoop < SIZE_BALANCE);

 };




// Computes the total benefit and expense of the user money
void Bank::computeWallet(int& user, float& profits, float& expenses){

    profits = sumArray(this->customers[user].ownWallet.balance.profits,SIZE_BALANCE);
    expenses = sumArray(this->customers[user].ownWallet.balance.expenses,SIZE_BALANCE);

    this->resetExpenses(user);
    this->resetProfits(user);

    //std::cout << "Total profits: " << profits << "\n" << "Total expenses: " << expenses << std::endl;
    
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
float Bank::showWallet(int& user, float& money){
    
    switch(this->customers[user].ownWallet.currency)
    {
        case euro:
        money = this->customers[user].ownWallet.money.euro;
        break;
        case dollar:
        money = this->customers[user].ownWallet.money.dollar;
        break;
        case yen:
        money = this->customers[user].ownWallet.money.yen;
        break;
    }
    return money;
};

int Bank::showCurrency(int& user){return int(this->customers[user].ownWallet.currency);};

// Converts money in another currency
void Bank::convertCurrency(int& user, int& choice, float& money, std::string& preconv, std::string& postconv){

    switch(this->customers[user].ownWallet.currency)
    {
        case Currency::dollar:
            money = this->customers[user].ownWallet.money.dollar ;
            money -= money*RATE_CONVERSION;
            preconv = "dollar";
            getinputUser("In which currency do you want to convert your balance ?\n1.\teuro\n2.\tyen\n",&choice);
            if(choice == 1){
                this->customers[user].ownWallet.money.euro = money * 0.94;
                postconv = "euro"; this->customers[user].ownWallet.currency = euro;
                showConversion(money, &(this->customers[user].ownWallet.money.euro),preconv,postconv);}
            else if(choice == 2){
                this->customers[user].ownWallet.money.yen = money * 130.76;
                postconv = "yen"; this->customers[user].ownWallet.currency = yen; 
                showConversion(money, &(this->customers[user].ownWallet.money.yen),preconv,postconv);}
            break;

        case Currency::euro:
            money = this->customers[user].ownWallet.money.euro;
            money -= money*RATE_CONVERSION;
            preconv = "euro";
            getinputUser("In which currency do you want to convert your balance ?\n1.\tdollar\n2.\tyen\n",&choice);
            if(choice == 1){
                this->customers[user].ownWallet.money.dollar = money * 1.07; postconv = "dollar";
                this->customers[user].ownWallet.currency = dollar;
                showConversion(money, &(this->customers[user].ownWallet.money.dollar),preconv,postconv);}
            else if(choice == 2){
                this->customers[user].ownWallet.money.yen = money * 140.22; postconv = "yen";
                this->customers[user].ownWallet.currency = yen;
                showConversion(money, &(this->customers[user].ownWallet.money.yen),preconv,postconv);}
            break;

        case Currency::yen:
            money = this->customers[user].ownWallet.money.yen;
            money -= money*RATE_CONVERSION;
            preconv = "yen";
            getinputUser("In which currency do you want to convert your balance ?\n1.\tdollar\n2.\teuro\n",&choice);
            if(choice == 1){
                this->customers[user].ownWallet.money.dollar = money * 0.0076; postconv = "dollar";
                this->customers[user].ownWallet.currency = dollar;
                showConversion(money, &(this->customers[user].ownWallet.money.dollar),preconv,postconv);}
            else if(choice == 2){
                this->customers[user].ownWallet.money.euro = money * 0.0072; postconv = "euro";
                this->customers[user].ownWallet.currency = euro;
                showConversion(money, &(this->customers[user].ownWallet.money.euro),preconv,postconv);}
            break;

    }

};

void Bank::showConversion(float& premoney, float* postmoney, std::string& preconv, std::string& postconv)
 {std::cout << "Successful conversion of your " << premoney << " " << preconv << " in " << *postmoney << " " << postconv << "." << std::endl;};

// Checks user firstname and password for accessing account
bool Bank::checkUser(bool* access, int& userCheck, int& userspot, std::string& inputName, std::string& password, const std::string& qUser){

    access[1] = false;
    getinputUser(qUser,inputName);

    for(int userspot = 0; userspot < SIZE_CUSTOMERS; userspot++)
    {
        if(inputName == this->customers[userspot].firstname){access[1] = true;userCheck = userspot;}

    }
    if(access[1])
    {

    std::cout << "Dear " << showName(userCheck);getinputUser(", please enter your password:\n",password);

    if(password == this->customers[userCheck].password){std::cout << "Sucessful access\n" << std::endl;access[2] =  true;}
    else{std::cout << "Failed access\n" << std::endl; access[2] = false;}

        return access[2];
    }
    else{
        std::cout << "Sorry, we can't find this account with this name. Please retry again or open a new account through the main menu." << std::endl;
        return false;
    }
};

void Bank::checkSpot(bool& access, int& user, int& userfree, const std::string& rUser){

    for(userfree = 0; userfree < SIZE_CUSTOMERS; userfree++)
    {
        if(this->customers[userfree].firstname == "userfree"){ user = userfree; access = true; break;}else{access = false;}
        if(access == false && userfree == (SIZE_CUSTOMERS-1)){
            std::cout << rUser << std::endl;
        }
    }
 };

void Bank::checkFriend(bool& access, int& user, int& userfree, const std::string& rUser){

    for(userfree = 0; userfree < SIZE_FRIENDS; userfree++)
    {
        if(this->customers[user].friends[userfree] == "userfree"){; access = true; break;}else{access = false;}
        if(access == false && userfree == (SIZE_FRIENDS-1)){
            std::cout << rUser << std::endl;
        }
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

void Bank::resetFriends(int& user, int& iniFriend){for(iniFriend = 0; iniFriend < SIZE_FRIENDS;iniFriend++){this->customers[user].friends[iniFriend] = "userfree";}};
void Bank::addFriend(int& user, int& friendspot, std::string& friendname){

    getinputUser("What is the name of your friend ?\n",friendname);
    this->customers[user].friends[friendspot] = friendname;
};

void Bank::showFriends(int& user, int& friendspot, int& friendnum ,std::string& friendname){

friendnum = 1;

    for(friendspot = 0; friendspot < SIZE_FRIENDS; friendspot++)
    {
        if(this->customers[user].friends[friendspot] != "userfree")
        {friendname = this->customers[user].friends[friendspot]; std::cout << "\t" << friendnum << ". "<<friendname << std::endl; friendnum++;}

    }
};



int Bank::showAge(int &user){return this->customers[user].age;}
std::string Bank::showName(int &user){return this->customers[user].firstname;};