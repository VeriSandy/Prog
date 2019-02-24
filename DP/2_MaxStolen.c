//Find maximum possible stolen value from houses
//https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/
//Either he chooses to steal at house i or not, depends on the max of hval[i] + max till i-2 and max till i-1th house

#include "../../COMMON/common.h"

int max(int a, int b)
{   
    return (a > b?a :b);
}

int maxStolen(int *a, int n)
{   
    if(!n) return 0;
    
    if( n == 1)
        return a[0];
    
    if(n == 2) 
        return (a[1]>a[0]? a[1]:a[0]);
    
    int dp[n];
    int i = 0;
    dp[0] = a[0];
    dp[1] = a[1] > a[0] ? a[1]: a[0];
    
    for(i = 2; i < n; i++) 
        dp[i] = max(a[i] + dp[i-2], dp[i-i]);
        
    return dp[n-1];
}

//no need to use whole array here, two variables will be suffice.
int maxStolen1(int *a, int n)
{
    if(!n) return 0;

    int value1 = a[0];
    if(n == 1) return value1;

    int value2 = a[1];
    if(n == 2)
        return (value1 > value2 ? value1 : value2);

    int i = 0;
    int maxval = 0;
    for(i = 2 ; i <  n ; i++)
    {
        maxval = max(a[i] + value1, value2);
        value1 = value2;
        value2 = maxval;
    }

    return maxval;
}

int main()
{
    int hval[] = {6, 7, 1, 3, 8, 2, 4};
    int n = sizeof(hval)/sizeof(hval[0]);
    printf("%d\n", maxStolen(hval, n));
    printf("%d\n", maxStolen1(hval, n));
    return 0;
}
