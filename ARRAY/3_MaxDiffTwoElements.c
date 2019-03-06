//Maximum difference between two elements such that larger element appears after the smaller number
//https://www.geeksforgeeks.org/maximum-difference-between-two-elements/

/*
Ideas -- 
1. Run two loops, second loop will find out the max element at the right of any particluar element and this way we can pull the max diff. O(n2)
2. We can have one array which says max element at the right. This could be done in O(n) time. In next traverse of original array, find out the max diff by using new array and original array.
3. In above method we can only we can keep track of max element from the right and see the diff with each element and what is max return. O(n)
4. Keep track of min element and max diff found till now
*/

#include "../../COMMON/common.h"

int MaxDiff(int *a, int n)
{
    int i = 0;
    int diff = 0;
    int maxdiff = -1;//in case if array is in decreasing order then no max diff is possible
    int right = a[n-1];//max from right
    for(i = n-2; i >= 0 ; i--)
    {
        diff = right - a[i];
        if(right < a[i])
            right = a[i];

        if(diff > maxdiff)
            maxdiff = diff;
    }
    return maxdiff;
}

int main()
{
    //int arr[] = {1, 2, 90, 10, 110}; 
    //int arr[] = {100, 92, 90, 80, 10}; 
    int arr[] = {80, 2, 6, 3, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("max diff %d\n", MaxDiff(arr, n));
    return 0;
}
