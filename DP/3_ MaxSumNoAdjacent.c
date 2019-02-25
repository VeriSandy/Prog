
//Maximum sum such that no two elements are adjacent
//https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/
//take element into account if including this gives max or see if till previous one is max than after including current element
//refer this for explanation
//https://www.geeksforgeeks.org/find-maximum-possible-stolen-value-houses/

#include "../../COMMON/common.h"

int FindMaxSum(int *a, int n)
{
    if(!n) return 0;

    int i = 0;
    int incl = a[0]; //include element
    int excl = 0; //exclude element i.e max till i-2 position
    int maxval = 0;

    for(i = 1; i < n ; i++)
    {
        maxval = incl > excl ? incl : excl;
        incl = excl + a[i];//max till i-2 position and current element
        excl = maxval; //it will have max till i-1 position
    }

    return (incl > excl ? incl : excl);
}

int main()
{
  int arr[] = {5, 5, 10, 100, 10, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
 printf("%d\n", FindMaxSum(arr, n));
  return 0;
}
