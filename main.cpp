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
    Bank dataBank;
    Bank* pdataBank;

    bool* paccessUser;
    int* pintUser;
    float* pfloatUser;
    std::string* pstringUser;
    //void (*pfunUser)(int&,int&,int&,const std::string, const int&);




    paccessUser = new bool [4]; // 0 = authorization access to user's account; 1 = user firstname validation; 2 = user password validation; 3 = spot availabilty 
    pintUser = new int [SIZE_PINT]; // 0 = user bank ID number; 1 =  user choice selection; 2 = index bank ID number balance; 3 = try count for bank operation; 4 = int loop for availibilty checking
    pfloatUser = new float [SIZE_PFLOAT]; // 0 = profits; 1 = expenses; 2 = money
    pstringUser = new std::string [4]; // 0 = pre conversion currency; 1 = post conversion currency; 2 = firstname user; 3 = password user

    std::fill(pintUser,pintUser+SIZE_PINT,0);
    std::fill(pfloatUser,pfloatUser+SIZE_PFLOAT,0);



    pdataBank = &dataBank;

    showMenu(pdataBank, paccessUser, pintUser, pfloatUser, pstringUser);

    delete paccessUser, pintUser, pfloatUser, pstringUser;

    return 0;
    
}

