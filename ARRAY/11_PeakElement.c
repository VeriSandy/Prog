//Find a peak element
//https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/

/*
Given an array of integers. Find a peak element in it. An array element is peak if it is NOT smaller than its neighbors.
For corner elements, we need to consider only one neighbor. For example, for input array {5, 10, 20, 15}, 20 is the only peak element.
For input array {10, 20, 15, 2, 23, 90, 67}, there are two peak elements: 20 and 90. Note that we need to return any one peak element.
*/

/*
    Since we need to return only one peak.
    So Try using Binary Search 
    If Mid ele is not >= both of its neighbours
    then if mid < mid -1 then peak would be in left half else in right half. It is vlaid in  this problem as only one of all need to return. 
    Try to solve some examples
*/

#include "../../COMMON/common.h"

int FindPeakUtil(int *a, int l, int h)
{
    if(l == h) return a[l];

    if(l+1 == h)
        return (a[l]> a[h]?a[l]:a[h]);

    int mid = (l+h)/2;

    if(a[mid] > a[mid-1] && a[mid] > a[mid+1])
        return a[mid];

    else if(a[mid] < a[mid-1])
        return FindPeakUtil(a, l, mid-1);

    else
        return FindPeakUtil(a, mid+1, h);
}

int findPeak(int *a, int n)
{
    if(!n) return -1;
    return FindPeakUtil(a, 0, n-1);
}

int main()
{
    //int arr[] = {1, 3, 20, 4, 1, 0}; 
    int arr[] = {10, 9, 15, 2, 23, 90, 67};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Index of a peak point is %d\n", findPeak(arr, n));
    return 0;
}
