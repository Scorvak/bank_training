#include "basics.h"

void getinputUser(const std::string& requestUser, std::string* choiceUser)
{
    std::string inputUser;
    std::cout << requestUser << std::endl;
    getline(std::cin, inputUser); // getline in order to get user input even if there are blank space character
    std::stringstream(inputUser) >> *choiceUser; // stringstream allows a string-based object to be treated as a stream, thus the string can be converted into another object type.

}
void getinputUser(const std::string& requestUser, int* choiceUser)
{
    std::string inputUser;
    std::cout << requestUser << std::endl;
    getline(std::cin, inputUser); // getline in order to get user input even if there are blank space character
    std::stringstream(inputUser) >> *choiceUser; // stringstream allows a string-based object to be treated as a stream, thus the string can be converted into another object type.
}

void getinputUser(const std::string& requestUser, float* choiceUser)
{
    std::string inputUser;
    std::cout << requestUser << std::endl;
    getline(std::cin, inputUser); // getline in order to get user input even if there are blank space character
    std::stringstream(inputUser) >> *choiceUser; // stringstream allows a string-based object to be treated as a stream, thus the string can be converted into another object type.
}



int sumArray(int* array, const int size)
{
    if(size > 0)
    {
        return *(array + size) + sumArray(array, size - 1);
    }
    else{
        return *array;

    } 
}

float sumArray(float* array, const int size)
{
    if(size > 0)
    {
        return *(array + size) + sumArray(array, size - 1);
    }
    else{
        return *array;

    } 
}