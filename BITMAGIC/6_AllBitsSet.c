//Check if all bits of a number are set
//https://www.geeksforgeeks.org/check-bits-number-set/

/*
Ideas - 
1. Adding one to the number should give the number, power of 2. That means number of set bit is 1.
2. Find out left most set bit, these many max bits can be set in this number. Find the actual set bits in numnber, see if both are same 
*/

#include "../../COMMON/common.h"

int AllBitsSet2(int a)
{
    int temp = a;
    int setbit = 0;

    while(temp)
    {
        temp = temp & (temp -1);
        setbit++;
    }
    int leftset = log2(a) + 1;//these many max bits can be set in number

    return (leftset == setbit)?1:0;
}

int AllBitsSet1(int a)
{
    return !((a+1)&a)?1:0;
}

int main()
{
//  int a = 15;
    int a = 14;

    printf("%s \n", AllBitsSet1(a)?"YES":"NO");
    printf("%s \n", AllBitsSet2(a)?"YES":"NO");

    return 0;
}
