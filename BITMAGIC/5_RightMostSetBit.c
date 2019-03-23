//Position of rightmost set bit
//https://www.geeksforgeeks.org/position-of-rightmost-set-bit/

/*
Ideas - 
1. Use left shift
2. Use right shift
3. Take 2's complement of a number, this will give all the bits reverted except the right most set bit. Now take the log of logical and of this number and original number
*/

#include "../../COMMON/common.h"

int RightMostSetBit3(int n)
{
    int i = 1;
    int pos = 1;

    while(!(n & i))
    {
        pos++;
        i <<= 1;
    }
    return pos;
}

int RightMostSetBit2(int n)
{
    int i = 1;
    int pos = 1;

    while(!(n & i))
    {
        pos++;
        n >>= 1;
    }
    return pos;
}

int RightMostSetBit1(int n)
{
    return (log2(n & -n) + 1);
}

int main()
{
    //int a = 10;
    int a = 18;

    printf("%d \n", RightMostSetBit1(a));
    printf("%d \n", RightMostSetBit2(a));
    printf("%d \n", RightMostSetBit3(a));

    return 0;
}

