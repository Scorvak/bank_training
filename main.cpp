#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "basics.h"
#include "classes.h"

using namespace std;


int main()

{
    int nbCredit, nbDebit, debitMoney = 0, creditMoney = 0;

    People Person1;
    People* pPerson1;

    pPerson1 = &Person1;

    pPerson1->getName();
    pPerson1->getAge();
 
pPerson1->ownWallet.askCredit();
pPerson1->ownWallet.askDebit();

nbCredit = pPerson1->ownWallet.getCredit();
nbDebit = pPerson1->ownWallet.getDebit();

    
    if(nbDebit > 0)
    {
        for(int i = 0; i < nbDebit; i++)
        {pPerson1->ownWallet.addDebit(i);}  
    }

    if(nbCredit > 0){
        for(int i = 0; i < nbCredit ; i++)
        {pPerson1->ownWallet.addCredit(i);}
    }
    
    pPerson1->ownWallet.computeWallet();
    cout << "Then your remaining money is " << pPerson1->ownWallet.showWallet() << endl;


    return 0;
}