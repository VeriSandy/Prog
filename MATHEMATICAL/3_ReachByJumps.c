//Reach the numbers by making jumps of two given lengths
//https://www.geeksforgeeks.org/reach-the-numbers-by-making-jumps-of-two-given-lengths/
/*
Given integers k, d1, d2 and an integer array arr[]. Starting from number k you are allowed to make jumps of size d1 and d2 i.e. all the possible moves from k are:
k + d1 and k – d1
k + d2 and k – d2
The task is to find which of the numbers from the array are reachable from k making any number of jumps and any given jump is either of size d1 or d2. For every number print 1 if its reachable else print 0.
*/

/*
IDEA - 
Use Diophantine algo

let say we are making these below operations to reach a[i] from k
a[i] = k + pd1 + qd2 
a[i] - k = pd1 + q d2

so if mod(a[i] - k)%gcd(d1, d2) == 0 then we can reach to a[i] == Diophantine algo
*/

#include "../../COMMON/common.h"

int Mod(int a)
{
    return ( a> 0 ? a :-a);
}

int GCD(int a, int b)
{
    if(!b) return a;
    return GCD(b, a%b);
}

void reachbyJumps(int *a , int k, int d1, int d2, int n)
{
    int gcd = GCD(d1, d2);
    int i = 0;

    for(i = 0; i < n ; i++)
    {
        if(!(Mod(a[i] -k)%gcd))
            printf("1 ");
        else
            printf("0 ");
    }
    printf("\n");
}
   
int main()
{
    int nums[] = {9,4,3};
    int n = sizeof(nums) / sizeof(nums[0]);
    int k = 8;
    int d1 = 3, d2 = 2;
    reachbyJumps(nums, k, d1, d2, n);

    //
    k = 10, d1 = 4, d2 = 6;
    int arr[] = {10, 15, 20};
    reachbyJumps(arr, k, d1, d2, n);

    return 0;
}
