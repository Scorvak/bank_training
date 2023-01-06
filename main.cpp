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

    int choiceUser, idUser = 1;


    bool* paccessUser;
    int* pintUser;
    float* pfloatUser;
    std::string* pstringUser;



    paccessUser = new bool [3]; // 0 = authorization access to user's account; 1 = user firstname validation; 2 = user password validation
    pintUser = new int [SIZE_PINT]; // 0 = user bank ID number; 1 =  user choice selection; 2 = user bank ID checking number; 3 = index bank ID number balance; 4 = try count for bank operation
    pfloatUser = new float [SIZE_PFLOAT]; // 0 = profits; 1 = expenses; 2 = money
    pstringUser = new std::string [4]; // 0 = pre conversion currency; 1 = post conversion currency; 2 = firstname user; 3 = password user

    std::fill(pintUser,pintUser+SIZE_PINT,0);
    std::fill(pfloatUser,pfloatUser+SIZE_PFLOAT,0);

    Bank dataBank;
    Bank* pdataBank;

    pdataBank = &dataBank;

    showMenu(pdataBank, paccessUser, pintUser, pfloatUser, pstringUser);

    delete paccessUser, pintUser, pfloatUser, pstringUser;

    return 0;
    
}

