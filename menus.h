#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include "basics.h"
#include "classes.h"

namespace Menus
{
void showMenu(Entities::Bank* bank);
void accountMenu(Entities::Bank* bank);
void operationMenu(Entities::Bank* bank);

}


#endif
