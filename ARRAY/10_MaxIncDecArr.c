
//https://www.geeksforgeeks.org/find-the-maximum-element-in-an-array-which-is-first-increasing-and-then-decreasing/
//Find the maximum element in an array which is first increasing and then decreasing

/*
    Idea 
    A number which is > both of its adjacent elements
    wrt problem statment, binary search can be used here very well
*/

#include "../../COMMON/common.h"


int MaxIncDecArr(int *a, int l, int h)
{
    int mid = 0;
    if(l == h)//one element
        return a[l];

    if(l == h -1)//two elements
        return (a[l] > a[h-1] ? a[l] : a[h-1]);

    mid = (l +h)/2;

    if(a[mid] > a[mid-1] && a[mid] > a[mid+1])
        return a[mid];

    else if(a[mid -1] < a[mid] && a[mid] < a[mid+1])//increasing array, so find elem in right half
        return MaxIncDecArr(a, mid+1, h);

    //else if(a[mid -1] > a[mid] && a[mid] > a[mid+1])//decreasing array, so find elem in right half
    else
        return MaxIncDecArr(a, l, mid-1);
}


int main()
{
  // int arr[] = {1, 3, 50, 10, 9, 7, 6}; 
   int arr[] = {60, 50, 10, 9, 7, 6};
   int n = sizeof(arr)/sizeof(arr[0]);
   printf("The maximum element is %d\n", MaxIncDecArr(arr, 0, n-1));
   return 0;
}
