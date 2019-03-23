//Smallest of three integers without comparison operators
//https://www.geeksforgeeks.org/smallest-of-three-integers-without-comparison-operators/

#include "../../COMMON/common.h"

//Subtracting 1 from each number one by one untill one of them becomes zero
//this is not going to work for negative numbers
int Smallest3(int a, int b, int c)
{
    int temp1 = a, temp2 = b, temp3 = c;

    while( a && b && c)
    {
        a--;
        b--;
        c--;
    }
    if(!a) return temp1;
    else if(!b) return temp2;
    else return temp3;
}

//Using bitwise
int Smallest2(int a, int b, int c)
{
    return (a-b)&(1<<31)?((a-c)&(1<< 31)?a:c):((b-c)&(1<< 31)?b:c);
}
//using division
int Smallest1(int a, int b, int c)
{
    if(!(a/b))
        if(!(a/c))
            return a;
        else
            return c;
    else
        if(!(b/c))
            return b;
        else
            return c;
}


int main()
{
    int a = 3;
    int b = 4;
    int c = -1;

    printf("Smallest of three numbers %d\n", Smallest1(a, b, c));
    printf("Smallest of three numbers %d\n", Smallest2(a, b, c));
    printf("Smallest of three numbers %d\n", Smallest3(a, b, c));

    return 0;
}
