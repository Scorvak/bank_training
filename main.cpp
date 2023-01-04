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

