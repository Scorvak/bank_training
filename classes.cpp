#include "classes.h"

// People class methods

Entities::People::People(){this->ownWallet.money.euro = 0; this->ownWallet.currency = euro;};

// Bank class methods 

Entities::Bank::Bank(){std::fill(this->ID_customers, this->ID_customers + SIZE_CUSTOMERS,0);};



void Entities::Bank::getName(){Basics::getinputUser("Please enter your firstname:\n",this->bankDB.stringBase[4], this->customers[this->bankDB.intBase[0]].firstname);}
void Entities::Bank::getPassword(){Basics::getinputUser("Please enter a password for your account:\n",this->bankDB.stringBase[4], this->customers[this->bankDB.intBase[0]].password);}
void Entities::Bank::getAge(){Basics::getinputUser("Please enter your age:\n",this->bankDB.stringBase[4], this->customers[this->bankDB.intBase[0]].age);}

void Entities::Bank::getChoice(const std::string& displayMenu){
    Basics::getinputUser(displayMenu, this->bankDB.stringBase[4], this->bankDB.intBase[1]);
}

int Entities::Bank::showAge(){return this->customers[this->bankDB.intBase[0]].age;}
int Entities::Bank::showChoice(){return this->bankDB.intBase[1];}

bool Entities::Bank::showBool(const int& check){return this->bankDB.boolBase[check];}

std::string Entities::Bank::showName(){return this->customers[this->bankDB.intBase[0]].firstname;}

// Gets from the user the money input
void Entities::Bank::getDebit(const std::string& qUser, const int& threshold){

    if(this->bankDB.intBase[3] == 0)
    {
        Basics::getinputUser(qUser, this->bankDB.stringBase[4], this->customers[this->bankDB.intBase[0]].ownWallet.balance.expenses[this->bankDB.intBase[2]]);
        this->bankDB.intBase[3]++;
        getDebit("Incorrect money amount, please retry:", threshold);

    }else if(this->bankDB.intBase[3] > 0 && this->customers[this->bankDB.intBase[0]].ownWallet.balance.expenses[this->bankDB.intBase[2]] < threshold)
    {
        Basics::getinputUser("Incorrect money amount, please retry:",this->bankDB.stringBase[4], this->customers[this->bankDB.intBase[0]].ownWallet.balance.expenses[this->bankDB.intBase[2]]);
        this->bankDB.intBase[3]++;
        getDebit("Incorrect money amount, please retry:", threshold);
    }else if(this->bankDB.intBase[3] > 0 && this->customers[this->bankDB.intBase[0]].ownWallet.balance.expenses[this->bankDB.intBase[2]] >= threshold){
        std::cout << "Thank you, we successfully take in account the debit of " << this->customers[this->bankDB.intBase[0]].ownWallet.balance.expenses[this->bankDB.intBase[2]]<< " " << showCurrency() << "." << std::endl;
    }

}

void Entities::Bank::getCredit(const std::string& qUser, const int& threshold){

    if(this->bankDB.intBase[3] == 0)
    {
        Basics::getinputUser(qUser,this->bankDB.stringBase[4], this->customers[this->bankDB.intBase[0]].ownWallet.balance.profits[this->bankDB.intBase[2]]);
        this->bankDB.intBase[3]++;
        getCredit("Incorrect money amount, please retry:", threshold);

    }else if(this->bankDB.intBase[3] > 0 && this->customers[this->bankDB.intBase[0]].ownWallet.balance.profits[this->bankDB.intBase[2]] < threshold)
    {
        Basics::getinputUser("Incorrect money amount, please retry:",this->bankDB.stringBase[4], this->customers[this->bankDB.intBase[0]].ownWallet.balance.profits[this->bankDB.intBase[2]]);
        this->bankDB.intBase[3]++;
        getCredit("Incorrect money amount, please retry:", threshold);  
    }else if(this->bankDB.intBase[3] > 0 && this->customers[this->bankDB.intBase[0]].ownWallet.balance.profits[this->bankDB.intBase[2]] >= threshold){
        std::cout << "Thank you, we successfully receive your " << this->customers[this->bankDB.intBase[0]].ownWallet.balance.profits[this->bankDB.intBase[2]] << " " << showCurrency() << "." << std::endl;}
 }

// Repeats operations for user

 void Entities::Bank::repeatOperation(const std::string& qUser, const int& threshold, void (Entities::Bank::*function)(const std::string&, const int&))
 {
    this->bankDB.intBase[2] = 0; // index
    this->bankDB.intBase[3] = 0; // try count

    do{

        (this->*function)(qUser, threshold);
        Basics::getinputUser("Do you want to add one more operation ?", this->bankDB.stringBase[1], this->bankDB.stringBase[0]);
        if(this->bankDB.stringBase[0] == "yes" || this->bankDB.stringBase[0] == "Yes"){this->bankDB.intBase[2]++    ; this->bankDB.intBase[3] = 0;}

    }while(this->bankDB.stringBase[0]  == "yes" || this->bankDB.stringBase[0]  == "Yes" &&  this->bankDB.intBase[2] < SIZE_BALANCE);

 }

// Computes the total benefit and expense of the user money
void Entities::Bank::computeWallet(){

    this->bankDB.floatBase[0] = Basics::sumArray<float>(this->customers[this->bankDB.intBase[0]].ownWallet.balance.profits,SIZE_BALANCE);
    this->bankDB.floatBase[1] = Basics::sumArray<float>(this->customers[this->bankDB.intBase[0]].ownWallet.balance.expenses,SIZE_BALANCE);

    this->resetExpenses();
    this->resetProfits();

    //std::cout << "Total profits: " << profits << "\n" << "Total expenses: " << expenses << std::endl;
    
    switch(this->customers[this->bankDB.intBase[0]].ownWallet.currency)
    {
        case euro:
        this->customers[this->bankDB.intBase[0]].ownWallet.money.euro = this->customers[this->bankDB.intBase[0]].ownWallet.money.euro + this->bankDB.floatBase[0] - this->bankDB.floatBase[1];
        break;
        case dollar:
        this->customers[this->bankDB.intBase[0]].ownWallet.money.dollar = this->customers[this->bankDB.intBase[0]].ownWallet.money.dollar + this->bankDB.floatBase[0] - this->bankDB.floatBase[1];
        break;
        case yen:
        this->customers[this->bankDB.intBase[0]].ownWallet.money.yen = this->customers[this->bankDB.intBase[0]].ownWallet.money.yen + this->bankDB.floatBase[0] - this->bankDB.floatBase[1];
        break;

    }
}

void Entities::Bank::resetWallet(){

 switch(this->customers[this->bankDB.intBase[0]].ownWallet.currency)
    {
        case euro:
        this->customers[this->bankDB.intBase[0]].ownWallet.money.euro = 0;
        break;
        case dollar:
        this->customers[this->bankDB.intBase[0]].ownWallet.money.dollar = 0;
        break;
        case yen:
        this->customers[this->bankDB.intBase[0]].ownWallet.money.yen = 0;
        break;
    }
}

// Shows available money in the wallet
float Entities::Bank::showWallet(){
    
    switch(this->customers[this->bankDB.intBase[0]].ownWallet.currency)
    {
        case euro:
        this->bankDB.floatBase[2] = this->customers[this->bankDB.intBase[0]].ownWallet.money.euro;
        break;
        case dollar:
        this->bankDB.floatBase[2] = this->customers[this->bankDB.intBase[0]].ownWallet.money.dollar;
        break;
        case yen:
        this->bankDB.floatBase[2] = this->customers[this->bankDB.intBase[0]].ownWallet.money.yen;
        break;
    }
    return this->bankDB.floatBase[2];
};

std::string Entities::Bank::showCurrency(){
    return this->currencies[int(this->customers[this->bankDB.intBase[0]].ownWallet.currency)];
}

// Converts money in another currency
void Entities::Bank::convertCurrency(){

    switch(this->customers[this->bankDB.intBase[0]].ownWallet.currency)
    {
        case Currency::dollar:
            this->bankDB.floatBase[2] = this->customers[this->bankDB.intBase[0]].ownWallet.money.dollar ;
            this->bankDB.floatBase[2] -= this->bankDB.floatBase[2]*RATE_CONVERSION;
            this->bankDB.stringBase[0] = "dollar";
            Basics::getinputUser("In which currency do you want to convert your balance ?\n1.\teuro\n2.\tyen\n", this->bankDB.stringBase[4] , this->bankDB.intBase[1]);
            if(this->bankDB.intBase[1] == 1){
                this->customers[this->bankDB.intBase[0]].ownWallet.money.euro = this->bankDB.floatBase[2] * 0.94;
                this->bankDB.stringBase[1] =  "euro"; this->customers[this->bankDB.intBase[0]].ownWallet.currency = euro;
                }
            else if(this->bankDB.intBase[1] == 2){
                this->customers[this->bankDB.intBase[0]].ownWallet.money.yen = this->bankDB.floatBase[2] * 130.76;
                this->bankDB.stringBase[1] =  "yen"; this->customers[this->bankDB.intBase[0]].ownWallet.currency = yen; 
                }
            break;

        case Currency::euro:
            this->bankDB.floatBase[2] = this->customers[this->bankDB.intBase[0]].ownWallet.money.euro;
            this->bankDB.floatBase[2] -= this->bankDB.floatBase[2]*RATE_CONVERSION;
            this->bankDB.stringBase[0] = "euro";
            Basics::getinputUser("In which currency do you want to convert your balance ?\n1.\tdollar\n2.\tyen\n", this->bankDB.stringBase[4], this->bankDB.intBase[1]);
            if(this->bankDB.intBase[1] == 1){
                this->customers[this->bankDB.intBase[0]].ownWallet.money.dollar = this->bankDB.floatBase[2] * 1.07; this->bankDB.stringBase[1] =  "dollar";
                this->customers[this->bankDB.intBase[0]].ownWallet.currency = dollar;
                }
            else if(this->bankDB.intBase[1] == 2){
                this->customers[this->bankDB.intBase[0]].ownWallet.money.yen = this->bankDB.floatBase[2] * 140.22; this->bankDB.stringBase[1] =  "yen";
                this->customers[this->bankDB.intBase[0]].ownWallet.currency = yen;
                }
            break;

        case Currency::yen:
            this->bankDB.floatBase[2] = this->customers[this->bankDB.intBase[0]].ownWallet.money.yen;
            this->bankDB.floatBase[2] -= this->bankDB.floatBase[2]*RATE_CONVERSION;
            this->bankDB.stringBase[0] = "yen";
            Basics::getinputUser("In which currency do you want to convert your balance ?\n1.\tdollar\n2.\teuro\n", this->bankDB.stringBase[4] , this->bankDB.intBase[1]);
            if(this->bankDB.intBase[1] == 1){
                this->customers[this->bankDB.intBase[0]].ownWallet.money.dollar = this->bankDB.floatBase[2] * 0.0076; this->bankDB.stringBase[1] =  "dollar";
                this->customers[this->bankDB.intBase[0]].ownWallet.currency = dollar;
                }
            else if(this->bankDB.intBase[1] == 2){
                this->customers[this->bankDB.intBase[0]].ownWallet.money.euro = this->bankDB.floatBase[2] * 0.0072; this->bankDB.stringBase[1] =  "euro";
                this->customers[this->bankDB.intBase[0]].ownWallet.currency = euro;
                }
            break;

    }

}

// Checks user firstname and password for accessing account
void Entities::Bank::checkUser(const std::string& qUser){

    this->bankDB.boolBase[0] = false;
    Basics::getinputUser(qUser, this->bankDB.stringBase[4], this->bankDB.stringBase[2]);

    for(this->bankDB.intBase[4] = 0; this->bankDB.intBase[4] < SIZE_CUSTOMERS; this->bankDB.intBase[4]++)
    {
        if(this->bankDB.stringBase[2] == this->customers[this->bankDB.intBase[4]].firstname){this->bankDB.boolBase[0] = true; this->bankDB.intBase[0] = this->bankDB.intBase[4];}
 
    }
    if(this->bankDB.boolBase[0])
    {

    this->bankDB.boolBase[1] =  false;
    std::cout << "Dear " << showName(); Basics::getinputUser(", please enter your password:\n", this->bankDB.stringBase[4], this->bankDB.stringBase[3]);

    for(this->bankDB.intBase[3] = 0; this->bankDB.intBase[3] < 2; this->bankDB.intBase[3]++){

    if(this->bankDB.stringBase[3] == this->customers[this->bankDB.intBase[0]].password){
            std::cout << "Sucessful access\n" << std::endl; this->bankDB.boolBase[1] =  true; break;}
    else if(this->bankDB.stringBase[3] != this->customers[this->bankDB.intBase[0]].password && this->bankDB.intBase[3] < 2){
        Basics::getinputUser("Incorrect password, please try again:", this->bankDB.stringBase[4], this->bankDB.stringBase[3]);}
    else if(this->bankDB.intBase[3] == 2){
        std::cout << "Sorry, too many attempts done, try to log in later." << std::endl;
        this->bankDB.boolBase[1] = false;
        }
    }
    }
    else{
        std::cout << "Sorry, we can't find this account with this name. Please retry again or open a new account through the main menu." << std::endl;
        this->bankDB.boolBase[1] = false;
    }
}

void Entities::Bank::checkSpot(const std::string& rUser){

    for( this->bankDB.intBase[4] = 0;  this->bankDB.intBase[4] < SIZE_CUSTOMERS; this->bankDB.intBase[4]++)
    {
        if(this->customers[this->bankDB.intBase[4]].firstname == "userfree"){ this->bankDB.intBase[0] =  this->bankDB.intBase[4]; this->bankDB.boolBase[2] = true; break;}else{this->bankDB.boolBase[2] = false;}
        if(this->bankDB.boolBase[2] == false &&  this->bankDB.intBase[4] == (SIZE_CUSTOMERS-1)){
            std::cout << rUser << std::endl;
        }
    }
 }

// Resets profits and expenses
    void Entities::Bank::resetProfits(){

        std::fill(this->customers[this->bankDB.intBase[0]].ownWallet.balance.profits, this->customers[this->bankDB.intBase[0]].ownWallet.balance.profits + SIZE_BALANCE,0.0f);

    }
    void Entities::Bank::resetExpenses(){

        std::fill(this->customers[this->bankDB.intBase[0]].ownWallet.balance.expenses, this->customers[this->bankDB.intBase[0]].ownWallet.balance.expenses + SIZE_BALANCE,0.0f);
    }



void Entities::Bank::resetFriends(){for(this->bankDB.intBase[4] = 0; this->bankDB.intBase[4] < SIZE_FRIENDS;this->bankDB.intBase[4]++){this->customers[this->bankDB.intBase[0]].friends[this->bankDB.intBase[4]] = "userfree";}}

void Entities::Bank::checkFriend(const std::string& rUser){

    for(this->bankDB.intBase[4] = 0; this->bankDB.intBase[4] < SIZE_FRIENDS; this->bankDB.intBase[4]++)
    {
        if(this->customers[this->bankDB.intBase[0]].friends[this->bankDB.intBase[4]] == "userfree"){this->bankDB.boolBase[3] = true; break;}else{this->bankDB.boolBase[3] = false;}
        if(this->bankDB.boolBase[3]  == false &&  this->bankDB.intBase[4] == (SIZE_FRIENDS-1)){
            std::cout << rUser << std::endl;
        }
    }
 }

void Entities::Bank::addFriend(){

    Basics::getinputUser("What is the name of your friend ?\n",this->bankDB.stringBase[4], this->bankDB.stringBase[3]);
    this->customers[this->bankDB.intBase[0]].friends[this->bankDB.boolBase[4]] = this->bankDB.stringBase[3];
}

void Entities::Bank::showFriends(){

    for(this->bankDB.intBase[4] = 0; this->bankDB.intBase[4] < SIZE_FRIENDS; this->bankDB.intBase[4]++)
    {
        if(this->customers[this->bankDB.intBase[0]].friends[this->bankDB.intBase[4]] != "userfree")
        {this->bankDB.stringBase[4] = this->customers[this->bankDB.intBase[0]].friends[this->bankDB.intBase[4]]; std::cout << "\t" << this->bankDB.intBase[4] + 1 << ". "<< this->bankDB.stringBase[4] << std::endl;}

    }
}

void Entities::Bank::transfer2friend()
{
    std::cout << "Your money will be transfered towards " << this->customers[this->bankDB.intBase[0]].friends[this->bankDB.intBase[1]] << "'s account.";
    this->getDebit("How much do you want to transfer ?",0);
    this->customers[this->bankDB.intBase[0]].ownWallet.balance.expenses[this->bankDB.intBase[2]];

}

void Entities::Bank::resetDB(const int& index){this->bankDB.intBase[index] = 0;}

// void (*pfunUser)(int&,int&,int&,const std::string, const int&);
// std::fill(userBase->intBase, userBase->intBase + SIZE_PINT,0);
// std::fill(userBase->floatBase, userBase->floatBase + SIZE_PFLOAT,0);