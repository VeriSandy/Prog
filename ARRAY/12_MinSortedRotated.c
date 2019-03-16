
//Find the minimum element in a sorted and rotated array
//https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/

/*
Idea
Use Binary Search

Find in case if middle ele is min
else 
    if right half is sorted then min will be in left half
else
    in right half
*/

#include "../../COMMON/common.h"

int findMin(int *a, int l, int h)
{
    if(l == h) return a[l];

    if(l+1 == h)
        return (a[l]<a[h]?a[l]:a[h]);

    int mid = (l+h)/2;

    if(a[l] <= a[mid-1] && a[mid] <= a[mid-1] && a[mid] <= a[h])
        return a[mid];

    else if(a[mid] <= a[h])
        return findMin(a, l, mid-1);

    else
        return findMin(a, mid+1, h);
}

int main()
{
    int arr1[] =  {5, 6, 1, 2, 3, 4};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    printf("The minimum element is %d\n", findMin(arr1, 0, n1-1));

    int arr2[] =  {1, 2, 3, 4};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    printf("The minimum element is %d\n", findMin(arr2, 0, n2-1));

    int arr3[] =  {1};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    printf("The minimum element is %d\n", findMin(arr3, 0, n3-1));

    int arr4[] =  {1, 2};
    int n4 = sizeof(arr4)/sizeof(arr4[0]);
    printf("The minimum element is %d\n", findMin(arr4, 0, n4-1));

    int arr5[] =  {2, 1};
    int n5 = sizeof(arr5)/sizeof(arr5[0]);
    printf("The minimum element is %d\n", findMin(arr5, 0, n5-1));

    int arr6[] =  {5, 6, 7, 1, 2, 3, 4};
    int n6 = sizeof(arr6)/sizeof(arr6[0]);
    printf("The minimum element is %d\n", findMin(arr6, 0, n6-1));

    int arr7[] =  {1, 2, 3, 4, 5, 6, 7};
    int n7 = sizeof(arr7)/sizeof(arr7[0]);
    printf("The minimum element is %d\n", findMin(arr7, 0, n7-1));

    int arr8[] =  {2, 3, 4, 5, 6, 7, 8, 1};
    int n8 = sizeof(arr8)/sizeof(arr8[0]);
    printf("The minimum element is %d\n", findMin(arr8, 0, n8-1));

    int arr9[] =  {3, 4, 5, 1, 2};
    int n9 = sizeof(arr9)/sizeof(arr9[0]);
    printf("The minimum element is %d\n", findMin(arr9, 0, n9-1));

    int arr10[] =  {5, 4, 3, 2, 1};
    int n10 = sizeof(arr10)/sizeof(arr10[0]);
    printf("The minimum element is %d\n", findMin(arr10, 0, n10-1));

    return 0;
}
