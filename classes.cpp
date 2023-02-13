#include "classes.h"

// Wallet class methods 

// Gets from the user the money input
void Bank::getDebit(int& user, int& index, int& tryUser, std::string& inputUser, const std::string& qUser, const int& threshold){

    if(tryUser == 0)
    {
        getinputUser(qUser, inputUser,&(this->customers[user].ownWallet.balance.expenses[index]));
        tryUser++;
        getDebit(user, index, tryUser, inputUser, "Incorrect money amount, please retry:", threshold);

    }else if(tryUser > 0 && this->customers[user].ownWallet.balance.expenses[index] < threshold)
    {
        getinputUser("Incorrect money amount, please retry:", inputUser, &(this->customers[user].ownWallet.balance.expenses[index]));
        tryUser++;
        getDebit(user, index, tryUser, inputUser, "Incorrect money amount, please retry:", threshold);
    }else if(tryUser > 0 && this->customers[user].ownWallet.balance.expenses[index] >= threshold){tryUser = 0;}

}; 

void Bank::getCredit(int& user, int& index, int& tryUser, std::string& inputUser, const std::string& qUser, const int& threshold){

    if(tryUser == 0)
    {
        getinputUser(qUser, inputUser, &(this->customers[user].ownWallet.balance.profits[index]));
        tryUser++;
        getCredit(user, index, tryUser, inputUser, "Incorrect money amount, please retry:", threshold);

    }else if(tryUser > 0 && this->customers[user].ownWallet.balance.profits[index] < threshold)
    {
        getinputUser("Incorrect money amount, please retry:", inputUser, &(this->customers[user].ownWallet.balance.profits[index]));
        tryUser++;
        getCredit( user, index, tryUser, inputUser, "Incorrect money amount, please retry:", threshold);  
    }else if(tryUser > 0 && this->customers[user].ownWallet.balance.profits[index] >= threshold){tryUser = 0;}
 };

// Repeats operations for user

 void Bank::repeatOperation(int& user, int& index, int& tryUser, int& iniLoop, std::string* stringUser, const std::string& qUser, const int& threshold, void (Bank::*function)(int&,int&,int&, std::string&, const std::string&, const int&))
 {
    index = 0;
    tryUser = 0;
    iniLoop = 0;

    do{

        (this->*function)(user, index, tryUser, stringUser[1], qUser, threshold);
        getinputUser("Do you want to add one more operation ?", stringUser[2], stringUser[0]);
        if(stringUser[0] == "yes" || stringUser[0] == "Yes"){iniLoop++; index++; tryUser = 0;}

    }while(stringUser[0] == "yes" || stringUser[0] == "Yes" && iniLoop < SIZE_BALANCE);

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
void Bank::convertCurrency(int& user, int& choice, float& money, std::string* stringUser){

    switch(this->customers[user].ownWallet.currency)
    {
        case Currency::dollar:
            money = this->customers[user].ownWallet.money.dollar ;
            money -= money*RATE_CONVERSION;
            stringUser[0] = "dollar";
            getinputUser("In which currency do you want to convert your balance ?\n1.\teuro\n2.\tyen\n", stringUser[4] , choice);
            if(choice == 1){
                this->customers[user].ownWallet.money.euro = money * 0.94;
                stringUser[1] =  "euro"; this->customers[user].ownWallet.currency = euro;
                showConversion(money, &(this->customers[user].ownWallet.money.euro), stringUser[0], stringUser[1]);}
            else if(choice == 2){
                this->customers[user].ownWallet.money.yen = money * 130.76;
                stringUser[1] =  "yen"; this->customers[user].ownWallet.currency = yen; 
                showConversion(money, &(this->customers[user].ownWallet.money.yen), stringUser[0], stringUser[1]);}
            break;

        case Currency::euro:
            money = this->customers[user].ownWallet.money.euro;
            money -= money*RATE_CONVERSION;
            stringUser[0] = "euro";
            getinputUser("In which currency do you want to convert your balance ?\n1.\tdollar\n2.\tyen\n", stringUser[4] , choice);
            if(choice == 1){
                this->customers[user].ownWallet.money.dollar = money * 1.07; stringUser[1] =  "dollar";
                this->customers[user].ownWallet.currency = dollar;
                showConversion(money, &(this->customers[user].ownWallet.money.dollar), stringUser[0], stringUser[1]);}
            else if(choice == 2){
                this->customers[user].ownWallet.money.yen = money * 140.22; stringUser[1] =  "yen";
                this->customers[user].ownWallet.currency = yen;
                showConversion(money, &(this->customers[user].ownWallet.money.yen), stringUser[0], stringUser[1]);}
            break;

        case Currency::yen:
            money = this->customers[user].ownWallet.money.yen;
            money -= money*RATE_CONVERSION;
            stringUser[0] = "yen";
            getinputUser("In which currency do you want to convert your balance ?\n1.\tdollar\n2.\teuro\n", stringUser[4] , choice);
            if(choice == 1){
                this->customers[user].ownWallet.money.dollar = money * 0.0076; stringUser[1] =  "dollar";
                this->customers[user].ownWallet.currency = dollar;
                showConversion(money, &(this->customers[user].ownWallet.money.dollar), stringUser[0], stringUser[1]);}
            else if(choice == 2){
                this->customers[user].ownWallet.money.euro = money * 0.0072; stringUser[1] =  "euro";
                this->customers[user].ownWallet.currency = euro;
                showConversion(money, &(this->customers[user].ownWallet.money.euro), stringUser[0], stringUser[1]);}
            break;

    }

};

void Bank::showConversion(float& premoney, float* postmoney, std::string& preconv, std::string& postconv)
 {std::cout << "Successful conversion of your " << premoney << " " << preconv << " in " << *postmoney << " " << postconv << "." << std::endl;};

// Checks user firstname and password for accessing account
void Bank::checkUser(bool* access, int& userCheck, int& userspot, int& userTry, std::string* stringUser, const std::string& qUser){

    access[1] = false;
    getinputUser(qUser, stringUser[4], stringUser[2]);

    for(int userspot = 0; userspot < SIZE_CUSTOMERS; userspot++)
    {
        if(stringUser[2] == this->customers[userspot].firstname){access[1] = true; userCheck = userspot;}
 
    }
    if(access[1])
    {

    std::cout << "Dear " << showName(userCheck); getinputUser(", please enter your password:\n", stringUser[4], stringUser[3]);

    for(userTry = 0; userTry < 2; userTry++){

    if(stringUser[3] == this->customers[userCheck].password){
            std::cout << "Sucessful access\n" << std::endl; access[2] =  true; break;}
    else if(stringUser[3] != this->customers[userCheck].password && userTry < 2){
        getinputUser("Incorrect password, please try again:", stringUser[4], stringUser[3]);}
    else if(userTry == 2){
        std::cout << "Sorry, too many attempts done, try to log in later." << std::endl;
        access[2] = false;
        }
    }
    }
    else{
        std::cout << "Sorry, we can't find this account with this name. Please retry again or open a new account through the main menu." << std::endl;
        access[2] = false;
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

void Bank::getName(int& user, std::string& inputUser){getinputUser("Please enter your firstname:\n", inputUser, &(this->customers[user].firstname));}
void Bank::getPassword(int& user, std::string& inputUser){getinputUser("Please enter a password for your account:\n", inputUser, &(this->customers[user].password));}
void Bank::getAge(int& user, std::string& inputUser){getinputUser("Please enter your age:\n", inputUser, &(this->customers[user].age));}

void Bank::resetFriends(int& user, int& iniFriend){for(iniFriend = 0; iniFriend < SIZE_FRIENDS;iniFriend++){this->customers[user].friends[iniFriend] = "userfree";}};
void Bank::addFriend(int& user, int& friendspot, std::string* stringUser){

    getinputUser("What is the name of your friend ?\n",stringUser[4], stringUser[3]);
    this->customers[user].friends[friendspot] = stringUser[3];
};

void Bank::showFriends(int& user, int& friendspot, int& friendnum ,std::string& friendname){

friendnum = 1;

    for(friendspot = 0; friendspot < SIZE_FRIENDS; friendspot++)
    {
        if(this->customers[user].friends[friendspot] != "userfree")
        {friendname = this->customers[user].friends[friendspot]; std::cout << "\t" << friendnum << ". "<<friendname << std::endl; friendnum++;}

    }
};



int Bank::showAge(int& user){return this->customers[user].age;}
std::string Bank::showName(int& user){return this->customers[user].firstname;};