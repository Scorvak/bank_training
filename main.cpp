#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "basics.h"
#include "classes.h"
#include "menus.h"

int main()

{
    int choiceUser, idUser = 1;

    Bank dataBank;
    Bank* pdataBank;

    pdataBank = &dataBank;

    showMenu(idUser,choiceUser,pdataBank);
    return 0;
}


/*

    for(int per = 0; per < 1;per ++)
    {
        pPerson[per]->getName();
        pPerson[per]->getAge();

        pPerson[per]->ownWallet.askCredit();
        pPerson[per]->ownWallet.askDebit();

        nbCredit = pPerson[per]->ownWallet.getCredit();
        if(nbCredit > 0){for(int i = 0; i < nbCredit ; i++){pPerson[per]->ownWallet.addCredit(i);}}

        nbDebit = pPerson[per]->ownWallet.getDebit();
        if(nbDebit > 0){for(int i = 0; i < nbDebit; i++){pPerson[per]->ownWallet.addDebit(i);}}

        pPerson[per]->ownWallet.computeWallet();
        std::cout << "Then your remaining money is " << pPerson[per]->ownWallet.showWallet() << "\n" << std::endl;}

    pPerson[0]->ownWallet.convertCurrency();

*/