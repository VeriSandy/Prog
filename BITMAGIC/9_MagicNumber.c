//Find nth Magic Number
//https://www.geeksforgeeks.org/find-nth-magic-number/
/*
A magic number is defined as a number which can be expressed as a power of 5 or sum of unique powers of 5.
 First few magic numbers are 5, 25, 30(5 + 25), 125, 130(125 + 5), ….

If we see carefully magic numbers can be represented as 001, 010, 011, 100, 101, 110, 111 and so on 

001 ==> pow(5, 1)
010 ==> pow(5, 2)
011 ==> pow(5, 2) + pow(5, 1)
*/

#include "../../COMMON/common.h"


int NthMagicNumber(int n)
{
    int pow = 1;
    int res = 0;
    while(n)
    {
        pow = pow *5;
        if(n & 1)
            res += pow;

        n >>= 1;
    }

    return res;
}

int main()
{
    //int n = 5;
    int n = 7;
    //int n = 3;
//  int n = 2;

    printf("%d\n", NthMagicNumber(n));

    return 0;
}
