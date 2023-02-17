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
    CresusBank = new Entities::Bank;

    Menus::showMenu(CresusBank);

    delete CresusBank;

    return 0;  
}

