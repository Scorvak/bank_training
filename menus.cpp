#include "menus.h"

void showMenu(Bank* account, bool* access, int* pintUser, float* pfloatUser, std::string* pstringUser)
{
    getinputUser("\n\tWelcome to Securrency Bank Inc.\t\n\nPlease select an option among the following ones:\n\n\t1. Open new account\n\t2. Manage account\n\t3. Close the program\n",pintUser[1]);

    switch(pintUser[1])
    {
        case 1:
        account->checkSpot(access[3],pintUser[0], pintUser[4],"There is no longer spot available to open an account in our bank. We're deeply sorry for our huge lack of competences. We'll commit sepuku right away...");
        if(access[3])
        {
            std::cout << "In order to open your new account, you need to provide several personnal informations." << std::endl;
            account->getAge(pintUser[0]);

            if(account->showAge(pintUser[0]) < 18)
            {
            std::cout << "Sorry, opening a new account is not available for minors. Please grow up, get a job and return to us when you'll be worth it dumbass.\n" << std::endl;
            }else{

            account->resetProfits(pintUser[0]); account->resetExpenses(pintUser[0]);
            account->getName(pintUser[0]);account->getPassword(pintUser[0]);
            pintUser[2] = 0; pintUser[3] = 0; 
            account->getCredit(pintUser[0],pintUser[2],pintUser[3], "To confirm your account opening, please make a first deposit of at least 50 euros",50);
            account->computeWallet(pintUser[0], pfloatUser[0], pfloatUser[1]);
            account->resetFriends(pintUser[0],pintUser[4]);

            std::cout << "\nGreat, your new account has been successfully opened. You can now consult it on the main menu.\n" << std::endl;
            
            }
        }
        showMenu(account,access, pintUser, pfloatUser, pstringUser);
        break;

        case 2:
            access[0] = account->checkUser(access, pintUser[0], pintUser[4], pstringUser[2], pstringUser[3], "Pleaser enter your firstname:\n");
            if(access[0]){accountMenu(account, access, pintUser, pfloatUser, pstringUser);}
            else{showMenu(account, access, pintUser, pfloatUser, pstringUser);}
        break;

        case 3:
            std::cout << "\nWe hope our services have brought satisfaction to your demands and to see you back soon.\n" << std::endl;
            break;

        default:
            std::cout << "\nPlease reconsider your choice, which is invalid from our available operations..." << std::endl;
            showMenu(account, access, pintUser, pfloatUser, pstringUser);
            break;
    }
};


void accountMenu(Bank* account, bool* access, int* pintUser, float* pfloatUser, std::string* pstringUser)
{
        getinputUser("Please choose a bank operation on your account:\n\n\t1. Consult your account balance\n\t2. Add funds or make a transfer order to another account\n\t3. Convert your currency balance\n\t4. Add friend account\n\t5. Return to the main menu\n",pintUser[1]);
        switch(pintUser[1])
        {
            case 1:
                std::cout << "Your balance account is now at " << account->showWallet(pintUser[0], pfloatUser[2]) << " " << currency[account->showCurrency(pintUser[0])]<< "\n" << std::endl;
                accountMenu(account, access, pintUser, pfloatUser, pstringUser);
                break;
                
            case 2:
                std::cout << "Ongoing development...\n\n";
                operationMenu(account, access, pintUser, pfloatUser, pstringUser);
                break;

            case 3:
                account->convertCurrency(pintUser[0], pintUser[1], pfloatUser[2], pstringUser[0], pstringUser[1]);
                accountMenu(account, access, pintUser, pfloatUser, pstringUser);
                break;

            case 4:
                account->checkFriend(access[3],pintUser[0], pintUser[4],"Sorry, you can't have more friends. Cherish those you already have. Or kill one if you really need one free spot :)\n");
                if(access[3]){account->addFriend(pintUser[0],pintUser[4],pstringUser[0]);}
                accountMenu(account, access, pintUser, pfloatUser, pstringUser);
                break;

            case 5:
                access[0] = false;
                showMenu(account, access, pintUser, pfloatUser, pstringUser);
                break;

            default:
                 std::cout << "Please reconsider your choice, which is invalid from our available operations..." << std::endl;
                 accountMenu(account, access, pintUser, pfloatUser, pstringUser);
                 break;
        }
}

void operationMenu(Bank* account, bool* access, int* pintUser, float* pfloatUser, std::string* pstringUser){

    getinputUser("Please choose which operation you want to do:\n\n\t1. Make deposit\n\t2. Transfer money to another account\n\t3. Return to previous menu",pintUser[1]);

    switch(pintUser[1])
    {
        case 1:
            account->repeatOperation(pintUser[0], pintUser[2], pintUser[3], pintUser[4], pstringUser[0], "How much money do you want to deposit ?", 0 , &Bank::getCredit);
            account->computeWallet(pintUser[0], pfloatUser[0], pfloatUser[1]);
            operationMenu(account, access, pintUser, pfloatUser, pstringUser);
            break;

        case 2:
            std::cout << "To whom do you want transfer money ?\n" << std::endl;
            account->showFriends(pintUser[0],pintUser[2], pintUser[3], pstringUser[0]);
            operationMenu(account, access, pintUser, pfloatUser, pstringUser);
            break;

        case 3:
            accountMenu(account, access, pintUser, pfloatUser, pstringUser);
            break;

        default:
            std::cout << "Please reconsider your choice, which is invalid from our available operations..." << std::endl;
            operationMenu(account, access, pintUser, pfloatUser, pstringUser);
            break;

    }
};

