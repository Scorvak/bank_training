#include "basics.h"

void getinputUser(string requestUser, string* choiceUser)
{
    string inputUser;
    cout << requestUser << endl;
    getline(cin, inputUser); // getline in order to get user input even if there are blank space character
    stringstream(inputUser) >> *choiceUser; // stringstream allows a string-based object to be treated as a stream, thus the string can be converted into another object type.

}

void getinputUser(string requestUser, int* choiceUser)
{
    string inputUser;
    cout << requestUser << endl;
    getline(cin, inputUser); // getline in order to get user input even if there are blank space character
    stringstream(inputUser) >> *choiceUser; // stringstream allows a string-based object to be treated as a stream, thus the string can be converted into another object type.
}


int sumArray(int* array, int size)
{
    if(size > 0)
    {
        return *(array + size) + sumArray(array, size - 1);
    }
    else{
        return *array;

    }
    
}