#include "menus.h"

void showMenu(int& choiceUser,People* account)
{

    getinputUser("t Welcome to Securrency Bank Inc.\t\n\nPlease select an option among the following ones:\n\n\t1. Open new account\n\t2. Manage account\n\t3. Close the program\n",choiceUser);

    switch(choiceUser)
    {
        case 1:
        std::cout << "In order to open your new account, you need to provide several personnal informations." << std::endl;
        
        account->getAge();
        if(account->showAge() < 18)
        {
            std::cout << "Sorry, opening a new account is not available for minors. Please grow up, get a job and return to us when you'll be worth it dumbass.\n" << std::endl;
            std::exit;
        }else{
            account->getName();account->getPassword();
            std::cout << "Great, your new account has been successfully opened. You can now consult it one the main menu.\n" << std::endl;
            showMenu(choiceUser, account);}
        break;
        case 2:
            operationMenu(choiceUser, account);
        break;
        case 3:
        std::cout << "We hope our services have brought satisfaction to your demands and to see you back soon.\n" << std::endl;
        std::exit;
        default:
        std::cout << "Please reconsider your choice, which is invalid from our available operations..." << std::endl;
        showMenu(choiceUser, account);
        break;

    }
};


void operationMenu(int& choiceUser, People* account)
{

        getinputUser("Please choose a bank operation on your account:\n\n\t1. Consult your account balance\n\t2. Add funds or make a transfer order to another account\n\t3. Convert your currency balance\n\t4. Return to the main menu\n\n",choiceUser);
        switch(choiceUser)
        {
            case 1:
                std::cout << "Your balance account is now at " << account->ownWallet.showWallet() << currency[account->ownWallet.showCurrency()]<< "\n" << std::endl;
            break;
            case 2:
                std::cout << "Ongoing development...\n\n";
                operationMenu(choiceUser, account);
            break;
            case 3:
                account->ownWallet.convertCurrency();
                operationMenu(choiceUser, account);
            case 4:
                showMenu(choiceUser, account);
            default:
                 std::cout << "Please reconsider your choice, which is invalid from our available operations..." << std::endl;
                 operationMenu(choiceUser, account);

        }

}