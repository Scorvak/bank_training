#include "basics.h"

int sumArray(int* array, const int size)
{
    if(size > 1){return array[size-1] + sumArray(array, (size - 1));}
    else{return array[0];} 
}

float sumArray(float* array, const int size)
{
    if(size > 1){return array[size-1] + sumArray(array, (size - 1));}
    else{return array[0];} 
}