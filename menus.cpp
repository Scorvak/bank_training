#include "menus.h"

void showMenu(int& idUser,int& choiceUser,Bank* account)
{
    getinputUser("\t Welcome to Securrency Bank Inc.\t\n\nPlease select an option among the following ones:\n\n\t1. Open new account\n\t2. Manage account\n\t3. Close the program\n",choiceUser);

    switch(choiceUser)
    {
        case 1:
        std::cout << "In order to open your new account, you need to provide several personnal informations." << std::endl;
        
        account->getAge(idUser);
        if(account->showAge(idUser) < 18)
        {
            std::cout << "Sorry, opening a new account is not available for minors. Please grow up, get a job and return to us when you'll be worth it dumbass.\n" << std::endl;
            break;
        }else{
            account->getName(idUser);account->getPassword(idUser);
            std::cout << "\nGreat, your new account has been successfully opened. You can now consult it one the main menu.\n" << std::endl;
            showMenu(idUser,choiceUser, account);}
        break;
        case 2:
            operationMenu(idUser,choiceUser, account);
        break;
        case 3:
        std::cout << "\nWe hope our services have brought satisfaction to your demands and to see you back soon.\n" << std::endl;
        break;
        default:
        std::cout << "\nPlease reconsider your choice, which is invalid from our available operations..." << std::endl;
        showMenu(idUser,choiceUser, account);
        break;

    }
    exit;
};


void operationMenu(int& idUser,int& choiceUser, Bank* account)
{

        getinputUser("Please choose a bank operation on your account:\n\n\t1. Consult your account balance\n\t2. Add funds or make a transfer order to another account\n\t3. Convert your currency balance\n\t4. Return to the main menu\n",choiceUser);
        switch(choiceUser)
        {
            case 1:
                std::cout << "Your balance account is now at " << account->showWallet(idUser) << " " << currency[account->showCurrency(idUser)]<< "\n" << std::endl;
                 operationMenu(idUser,choiceUser, account);
            break;
            case 2:
                std::cout << "Ongoing development...\n\n";
                operationMenu(idUser,choiceUser, account);
            break;
            case 3:
                account->convertCurrency(idUser);
                operationMenu(idUser,choiceUser, account);
            case 4:
                showMenu(idUser,choiceUser, account);
            default:
                 std::cout << "Please reconsider your choice, which is invalid from our available operations..." << std::endl;
                 operationMenu(idUser,choiceUser, account);

        }

}
