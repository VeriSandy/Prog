////Check if two numbers are bit rotations of each other or not
//https://www.geeksforgeeks.org/check-two-numbers-bit-rotations-not/
/*
This is similar to, if need to find out "strings are rotations of each other or not". 
Then conactenate (X,X) and see if Y occurs in this concatenated string or not. Use similar concept here.
*/

#include "../../COMMON/common.h"

int isRotation(unsigned int x, unsigned int y)
{
    unsigned long long temp = x | ((unsigned long long)x <<32);

    while(temp >= y)
    {
        if(y == (unsigned int)temp)
            return 1;

        temp >>= 1;
    }

    return 0;
}

int main()
{
    //unsigned int x = 122; 
    //unsigned int y = 2147483678; 

    unsigned int x = 1;
    unsigned int y = 8;

    if (isRotation(x, y))
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}
