#include "menus.h"

void showMenu(Bank* account, DataBase* userBase)
{
    getinputUser("\n\tWelcome to Securrency Bank Inc.\t\n\nPlease select an option among the following ones:\n\n\t1. Open new account\n\t2. Manage account\n\t3. Close the program\n",userBase->stringBase[0],userBase->intBase[1]);

    switch(userBase->intBase[1])
    {
        case 1:
        account->checkSpot(userBase->boolBase[3],userBase->intBase[0], userBase->intBase[4],"There is no longer spot available to open an account in our bank. We're deeply sorry for our huge lack of competences. We'll commit sepuku right away...");
        if(userBase->boolBase[3])
        {
            std::cout << "In order to open your new account, you need to provide several personnal informations." << std::endl;
            account->getAge(userBase->intBase[0], userBase->stringBase[4]);

            if(account->showAge(userBase->intBase[0]) < 18)
            {
            std::cout << "Sorry, opening a new account is not available for minors. Please grow up, get a job and return to us when you'll be worth it dumbass.\n" << std::endl;
            }else{

            account->resetProfits(userBase->intBase[0]); account->resetExpenses(userBase->intBase[0]);
            account->getName(userBase->intBase[0], userBase->stringBase[4]);account->getPassword(userBase->intBase[0], userBase->stringBase[4]);
            userBase->intBase[2] = 0; userBase->intBase[3] = 0; 
            account->getCredit(userBase->intBase[0],userBase->intBase[2],userBase->intBase[3], userBase->stringBase[0], "To confirm your account opening, please make a first deposit of at least 50 euros", 50);
            account->computeWallet(userBase->intBase[0], userBase->floatBase[0], userBase->floatBase[1]);
            account->resetFriends(userBase->intBase[0],userBase->intBase[4]);

            std::cout << "\nGreat, your new account has been successfully opened. You can now consult it on the main menu.\n" << std::endl;
            
            }
        }
        showMenu(account, userBase);
        break;

        case 2:
            account->checkUser(userBase->boolBase, userBase->intBase[0], userBase->intBase[3], userBase->intBase[4], userBase->stringBase, "Pleaser enter your firstname:\n");
            if(userBase->boolBase[2]){accountMenu(account, userBase);}
            else{showMenu(account, userBase);}
        break;

        case 3:
            std::cout << "\nWe hope our services have brought satisfaction to your demands and to see you back soon.\n" << std::endl;
            break;

        default:
            std::cout << "\nPlease reconsider your choice, which is invalid from our available operations..." << std::endl;
            showMenu(account, userBase);
            break;
    }
};


void accountMenu(Bank* account, DataBase* userBase)
{
        getinputUser("Please choose a bank operation on your account:\n\n\t1. Consult your account balance\n\t2. Add funds or make a transfer order to another account\n\t3. Convert your currency balance\n\t4. Add friend account\n\t5. Return to the main menu\n", userBase->stringBase[0], userBase->intBase[1]);
        switch(userBase->intBase[1])
        {
            case 1:
                std::cout << "Your balance account is now at " << account->showWallet(userBase->intBase[0], userBase->floatBase[2]) << " " << currency[account->showCurrency(userBase->intBase[0])]<< "\n" << std::endl;
                accountMenu(account, userBase);
                break;
                
            case 2:
                std::cout << "Ongoing development...\n\n";
                operationMenu(account, userBase);
                break;

            case 3:
                account->convertCurrency(userBase->intBase[0], userBase->intBase[1], userBase->floatBase[2], userBase->stringBase);
                accountMenu(account, userBase);
                break;

            case 4:
                account->checkFriend(userBase->boolBase[3],userBase->intBase[0], userBase->intBase[4],"Sorry, you can't have more friends. Cherish those you already have. Or kill one if you really need one free spot :)\n");
                if(userBase->boolBase[3]){account->addFriend(userBase->intBase[0],userBase->intBase[4],userBase->stringBase);}
                accountMenu(account, userBase);
                break;

            case 5:
                userBase->boolBase[0] = false;
                showMenu(account, userBase);
                break;

            default:
                 std::cout << "Please reconsider your choice, which is invalid from our available operations..." << std::endl;
                 accountMenu(account, userBase);
                 break;
        }
}

void operationMenu(Bank* account, DataBase* userBase){

    getinputUser("Please choose which operation you want to do:\n\n\t1. Make deposit\n\t2. Transfer money to another account\n\t3. Return to previous menu", userBase->stringBase[0], userBase->intBase[1]);

    switch(userBase->intBase[1])
    {
        case 1:
            account->repeatOperation(userBase->intBase[0], userBase->intBase[2], userBase->intBase[3], userBase->intBase[4], userBase->stringBase, "How much money do you want to deposit ?", 0 , &Bank::getCredit);
            account->computeWallet(userBase->intBase[0], userBase->floatBase[0], userBase->floatBase[1]);
            operationMenu(account, userBase);
            break;

        case 2:
            std::cout << "To whom do you want transfer money ?\n" << std::endl;
            account->showFriends(userBase->intBase[0],userBase->intBase[2], userBase->intBase[3], userBase->stringBase[0]);
            operationMenu(account, userBase);
            break;

        case 3:
            accountMenu(account, userBase);
            break;

        default:
            std::cout << "Please reconsider your choice, which is invalid from our available operations..." << std::endl;
            operationMenu(account, userBase);
            break;

    }
};

