//Number of array elements derivable from D after performing certain operations
//https://www.geeksforgeeks.org/number-of-array-elements-derivable-from-d-after-performing-certain-operations/
/*
Given an array of N integers and 3 integers D, A and B. The task is to find the number of array elements that we can convert D into by performing the following operations on D:
Add A (+A)
Subtract A (-A)
Add B (+B)
Subtract B (-B)
Note: It is allowed to perform any number of operations of any type.    
*/
/*
    Idea - 

    Let say a[i] can be derived frm a, b and d
    a[i] = d - (xa - ya + pb - qb);
    a[i] = d - a(y-x) - b(q-p);
    d-a[i] = aX + bY;
    so a[i] can be derived from a, b, d if 
    (|d-a[i]\)%GCD(a, b) == 0

*/

#include "../../COMMON/common.h"

int Mod(int a)
{
    return a > 0 ? a: -a;
}

int GCD(int a, int b)
{
    if(!b) return a;

    return GCD(b, a%b);
}

int findDerivables(int *p, int n, int d, int a, int b)
{
    int count = 0;
    int i = 0;
    int gcd = GCD(a, b);

    for(i = 0; i < n ; i++)
    {
        if((Mod(p[i] - d)%gcd) == 0)
        {
            count++;
            printf("%d ", p[i]);
        }
    }
    printf("\n");
    return count;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 7, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int D = 5, A = 4, B = 2;
    printf("No of Derivables %d \n", findDerivables(arr, n, D, A, B));

    int a[] = { 1, 2, 3 };
    n = sizeof(a) / sizeof(a[0]);
    D = 6, A = 3, B = 2;
    printf("No of Derivables %d \n", findDerivables(arr, n, D, A, B));
    return 0;
}
