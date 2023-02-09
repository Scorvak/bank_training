#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "basics.h"
#include "classes.h"


void showMenu(Bank* account, DataBase* userBase);
void accountMenu(Bank* account, DataBase* userBase);
void operationMenu(Bank* account, DataBase* userBase);

#endif
