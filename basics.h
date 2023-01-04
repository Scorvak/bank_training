#ifndef BASICS_H
#define BASICS_H

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

void getinputUser(const std::string& requestUser, std::string* choiceUser);
void getinputUser(const std::string& requestUser, int* choiceUser);
void getinputUser(const std::string& requestUser, int& choiceUser);
void getinputUser(const std::string& requestUser, float* choiceUser);


int sumArray(int* array, const int size);
float sumArray(float* array, const int size);

#endif