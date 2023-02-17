#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "basics.h"
#include "classes.h"
#include "menus.h"

int main()

{

    Entities::Bank* CresusBank;

    //void (*pfunUser)(int&,int&,int&,const std::string, const int&);
    CresusBank = new Entities::Bank;
//   std::fill(userBase->intBase, userBase->intBase + SIZE_PINT,0);
//  std::fill(userBase->floatBase, userBase->floatBase + SIZE_PFLOAT,0);

    Menus::showMenu(CresusBank);

    delete CresusBank;

    return 0;
    
}

