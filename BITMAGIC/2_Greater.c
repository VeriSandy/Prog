//Find out greater in 2 numbers
//based on https://www.geeksforgeeks.org/smallest-of-three-integers-without-comparison-operators/
/*
    Subtracting 1 from each number one by one untill one of them becomes zero
*/

#include "../../COMMON/common.h"

int Greater3(int a, int b)
{
    int temp1 = a, temp2 = b;

    while( a && b)
    {
        a--;
        b--;
    }
    if(!a) return temp2;
    else
        return temp1;
}

//Using bitwise
int Greater2(int a, int b)
{
    return ((a-b) & (1 << (sizeof(int) * 8 -1))?b:a);
}
//using division
int Greater1(int a, int b)
{
    if(!(a/b))
        return b;
    else
        return a;
}

int main()
{
    int a = 3;
    int b = 4;

    printf("greater number of two numbers %d\n", Greater1(a, b));
    printf("greater number of two numbers %d\n", Greater2(a, b));
    printf("greater number of two numbers %d\n", Greater3(a, b));

    return 0;
}
