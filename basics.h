#ifndef BASICS_H
#define BASICS_H

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

void getinputUser(const std::string& requestUser, std::string* choiceUser);
void getinputUser(const std::string& requestUser, int* choiceUser);

int sumArray(int* array, const int size);


#endif