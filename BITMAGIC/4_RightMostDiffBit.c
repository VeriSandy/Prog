//Position of rightmost different bit
//https://www.geeksforgeeks.org/position-rightmost-different-bit/

/*
Ideas - 
1. Take XOR of two numbers and find out the right most set bit
2. Check each bit see if it is different else left shift both numbers
*/

#include "../../COMMON/common.h"

int RightMostDiffBit2(int a, int b)
{
    int pos = 1;

    while(a|b)
    {
        if( (a&1) != (b&1))
            break;

        a >>= 1;
        b >>= 1;
        pos++;
    }
    return pos;
}

int RightMostDiffBit1(int a, int b)
{
    int xr = a^b;
    return (log2(xr & -xr) + 1);
}

int main()
{
    int a = 4, b = 52;
    //int a = 10, b = 1;

    printf("%d \n", RightMostDiffBit1(a, b));
    printf("%d \n", RightMostDiffBit2(a, b));

    return 0;
}
