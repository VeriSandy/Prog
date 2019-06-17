//median of two sorted array, of same size
//https://www.geeksforgeeks.org/median-of-two-sorted-arrays/

//Idea -- Use merge method of two sorted arrays and then find out the median
//here median would be avg of two middle elements after merging
//O(n+n) where n is size of array.

//no need to merge arrays here just keep track of n-1th and nth element, as total size after merging would be 2n

#include "../../COMMON/common.h"

int getMedian(int *a, int *b, int n)
{   
    if(!n) return 0;
    
    if(n == 1) return (a[0] + b[0])/2;
    
    int i = 0, j = 0, k = 0;
    int m1 = -1, m2 = -1;
    while(k <= n)
    {   
        if(i == n)
        {   
            m1 = m2;
            m2 = b[0];
            break;
        }
        if(j == n)
        {   
            m1 = m2;
            m2 = a[0];
            break;
        }
        if(a[i] < b[j])
        {   
            m1 = m2;
            m2 = a[i];
            i++;
            k++;
        }
        else
        {   
            m1 = m2;
            m2 = b[j];
            j++;
            k++;
        }
    }

    
    return (m1+m2)/2;
}


int main()
{
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};

    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    printf("Median is %d\n", getMedian(ar1, ar2, n1));
    return 0;
}
