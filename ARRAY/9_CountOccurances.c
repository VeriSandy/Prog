
//Count number of occurrences (or frequency) in a sorted array
//https://www.geeksforgeeks.org/count-number-of-occurrences-or-frequency-in-a-sorted-array/

/*
    Ideas - 
    do linear traversal and find out the frequency
    
    else use binary search
    and find out the first and last index of the key 


*/

#include "../../COMMON/common.h"

int FirstOccur(int *a, int n, int k)
{
    if(!n) return -1;
    
    int l = 0;
    int h = n-1, mid = 0;

    while(l <= h)
    {
        mid = (l+h)/2;
    
        if(a[mid] == k)
        {
            if(a[mid-1] != k)
                return mid;
            else
                h = mid -1;
        }
            
        else if(a[mid] < k)
            l = mid +1;
        else
            h = mid -1;
    }
    return -1;
}



int LastOccur(int *a, int n, int k)
{
    if(!n) return -1;
    
    int l = 0;
    int h = n-1, mid = 0;

    while(l <= h)
    {
        mid = (l+h)/2;

        if(a[mid] == k)
        {
            if(a[mid+1] != k)
                return mid;
            else
                l = mid +1;
        }

        else if(a[mid] < k)
            l = mid +1;
        else
            h = mid -1;
    }
    return -1;
}

int count(int *a, int k, int n)
{
    int first = FirstOccur(a, n, k);
    int last = LastOccur(a, n, k);
    if(first == -1 || last == -1) return -1;
    return last - first +1 ;
}

int main()
{  
    int arr[] = {1, 2, 2, 3, 3, 3, 3};
    int x =  5;  // Element to be counted in arr[] 
    int n = sizeof(arr)/sizeof(arr[0]);
    int c = count(arr, x, n);
    printf("%d occurs %d times \n", x, c);
    return 0;
}
