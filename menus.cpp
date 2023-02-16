#include "menus.h"

void showMenu(Bank* bank)
{
    bank->getChoice("\n\tWelcome to Securrency Bank Inc.\t\n\nPlease select an option among the following ones:\n\n\t1. Open new account\n\t2. Manage account\n\t3. Close the program\n");
    switch(bank->showChoice())
    {
        case 1:
        bank->checkSpot("There is no longer spot available to open an account in our bank. We're deeply sorry for our huge lack of competences. We'll commit sepuku right away...");
        if(bank->showBool(2))
        {
            std::cout << "In order to open your new account, you need to provide several personnal informations." << std::endl;
            bank->getAge();

            if(bank->showAge() < 18)
            {
            std::cout << "Sorry, opening a new account is not available for minors. Please grow up, get a job and return to us when you'll be worth it dumbass.\n" << std::endl;
            }else{

            bank->resetProfits(); bank->resetExpenses();
            bank->getName();bank->getPassword();
            bank->resetDB(2); bank->resetDB(3); 
            bank->getCredit( "To confirm your account opening, please make a first deposit of at least 50 euros", 50);
            bank->computeWallet();
            bank->resetFriends();

            std::cout << "\nGreat, your new account has been successfully opened. You can now consult it on the main menu.\n" << std::endl;
            
            }
        }
        showMenu(bank);
        break;

        case 2:
            bank->checkUser("Pleaser enter your firstname:\n");
            if(bank->showBool(1)){accountMenu(bank);}
            else{showMenu(bank);}
        break;

        case 3:
            std::cout << "\nWe hope our services have brought satisfaction to your demands and to see you back soon.\n" << std::endl;
            break;

        default:
            std::cout << "\nPlease reconsider your choice, which is invalid from our available operations..." << std::endl;
            showMenu(bank);
            break;
    }
};


void accountMenu(Bank* bank)
{
        bank->getChoice( "Please choose a bank operation on your account:\n\n\t1. Consult your account balance\n\t2. Add funds or make a transfer order to another account\n\t3. Convert your currency balance\n\t4. Add friend account\n\t5. Return to the main menu\n");
       
        switch(bank->showChoice())
        {
            case 1:
                std::cout << "Your balance account is now at " << bank->showWallet() << " " << currency[bank->showCurrency()]<< "\n" << std::endl;
                accountMenu(bank);
                break;
                
            case 2:
                std::cout << "Ongoing development...\n\n";
                operationMenu(bank);
                break;

            case 3:
                bank->convertCurrency();
                accountMenu(bank);
                break;

            case 4:
                bank->checkFriend("Sorry, you can't have more friends. Cherish those you already have. Or kill one if you really need one free spot :)\n");
                if(bank->showBool(3)){bank->addFriend();}
                accountMenu(bank);
                break;

            case 5:
                showMenu(bank);
                break;

            default:
                 std::cout << "Please reconsider your choice, which is invalid from our available operations..." << std::endl;
                 accountMenu(bank);
                 break;
        }
}

void operationMenu(Bank* bank){

    bank->getChoice("Please choose which operation you want to do:\n\n\t1. Make deposit\n\t2. Transfer money to another account\n\t3. Return to previous menu");
    switch(bank->showChoice())
    {
        case 1:
            bank->repeatOperation("How much money do you want to deposit ?", 0 , &Bank::getCredit);
            bank->computeWallet();
            operationMenu(bank);
            break;

        case 2:
            std::cout << "To whom do you want transfer money ?\n" << std::endl;
            bank->showFriends();
            operationMenu(bank);
            break;

        case 3:
            accountMenu(bank);
            break;

        default:
            std::cout << "Please reconsider your choice, which is invalid from our available operations..." << std::endl;
            operationMenu(bank);
            break;

    }
};

