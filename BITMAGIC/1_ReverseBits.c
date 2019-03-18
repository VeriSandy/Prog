//Write an Efficient C Program to Reverse Bits of a Number
//https://www.geeksforgeeks.org/write-an-efficient-c-program-to-reverse-bits-of-a-number/

#include "../../COMMON/common.h"

void RevBits(int n)
{
    int i = 0;
    int size = sizeof(int) * 8;
    int rev =0;

    for(; i < size; i++)
    {
        if(n & (1 << i))
            rev |= 1 << ((size -1) - i);
    }
    printf("%d \n", rev);
    return;
}

void RevBitsOther(int n)
{
    int rev = n;
    int count = sizeof(n) * 8;

    while(n)
    {
        rev <<= 1;
        rev |= (n & 1);
        n >>= 1;
        count--;
    }

    rev <<= count;

    printf("%d\n", rev);

    return ;
}

int main()
{
    int n = 1;

    RevBits(n);
    RevBitsOther(n);

    return 0;
}
