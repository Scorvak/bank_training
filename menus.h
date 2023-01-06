#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "basics.h"
#include "classes.h"


void showMenu(Bank* account, bool* access, int* pintUser, float* pfloatUser, std::string* pstringUser);
void operationMenu(Bank* account, bool* access, int* pintUser, float* pfloatUser, std::string* pstringUser);


#endif
