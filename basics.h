#ifndef BASICS_H
#define BASICS_H

#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

#define SIZE_PINT 5
#define SIZE_PFLOAT 3

struct DataBase {

    bool boolBase[5];
    int intBase[SIZE_PINT];
    float floatBase[SIZE_PFLOAT];
    std::string stringBase[5];
};

    // bool : 0 = authorization access to user's account; 1 = user firstname validation; 2 = user password validation; 3 = spot availabilty 
    // int : 0 = user bank ID number; 1 =  user choice selection; 2 = index bank ID number balance; 3 = try count for bank operation; 4 = init loop for availibilty checking
    // float: 0 = profits; 1 = expenses; 2 = money
    // string: 0 = pre conversion currency; 1 = post conversion currency; 2 = firstname user; 3 = password user; 4 = temporary

template <typename T>
void getinputUser(const std::string& requestUser, std::string& inputUser, T* choiceUser){

    std::cout << requestUser << std::endl;
    getline(std::cin, inputUser); 
    std::stringstream(inputUser) >> *choiceUser; 
    
}

template <typename T>
void getinputUser(const std::string& requestUser, std::string& inputUser, T& choiceUser){

    std::cout << requestUser << std::endl;
    getline(std::cin, inputUser); 
    std::stringstream(inputUser) >> *choiceUser; 
    
}


int sumArray(int* array, const int size);
float sumArray(float* array, const int size);

#endif