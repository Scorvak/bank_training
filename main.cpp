#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "basics.h"
#include "classes.h"
#include "menus.h"

#define SIZE_PINT 5
#define SIZE_PFLOAT 3

int main()

{

    Bank* pdataBank;
    DataBase* userBase;

    //void (*pfunUser)(int&,int&,int&,const std::string, const int&);

    userBase = new DataBase;
    pdataBank = new Bank;
    std::fill(userBase->intBase, userBase->intBase + SIZE_PINT,0);
    std::fill(userBase->floatBase, userBase->floatBase + SIZE_PFLOAT,0);

    showMenu(pdataBank, userBase);

    delete userBase, pdataBank;

    return 0;
    
}

