https://www.youtube.com/watch?v=MHNTl_NvOj0
//Median of two sorted arrays of same size
//https://www.geeksforgeeks.org/median-of-two-sorted-arrays/

/*
    a[] = {a1, a2}
    b[] = {b1, b2};

    Sort(a+b) = min(a1, b1){max(a1, b1), min(a2, b2)}, max(a2, b2)
    So median = (max(a1, b1) + min(a2, b2))/2


same way
    a[] = {a1, a2, m1, a4, a5}
    b[] = {b1, b2, m2, b4, b5}

    if(m2 > m1)
        Sort(a + b) = a1, a2,{     m1.... m2    }, b4, b5 
        ==> Elements inside { } are not in order but can help to reduce the search area like binary search
            here we do not need to search a1, a2, b4, b5. Can be discarded from further search 
    if(m1> m2)
        Sort(a+b) = b1, b2 {  m2.... m1 }   a4, a5
*/

#include "../../COMMON/common.h"


int max(int a, int b)
{
    return (a > b ? a: b);
}

int min(int a, int b)
{
    return (a > b ? b: a);
}

int median(int *a, int n)
{
    if(n%2 == 0)
        return (a[n/2] + a[n/2 - 1])/2;
    else
        return a[n/2];

}


int getMedian(int *a, int *b, int n)
{
    if(!n) return -1;

    if(n == 1) return (a[0] + b[0])/2;

    if(n == 2)
        return (max(a[0], b[0]) + min(a[1], b[1]))/2;


    int m1 = median(a, n);
    int m2 = median(b, n);

    if(m1 == m2)
        return m1;

    else if(m1< m2)
    {
        printf("m1 < m2 \n");
        if(n%2 == 0)
            return getMedian(a + n/2 -1, b, n - (n/2 -1));
        return getMedian(a + n/2, b, n/2 +1);
    }

    else
    {
        if(n%2 == 0)
            return getMedian(a, b + n/2 -1, n - (n/2 -1));
        return getMedian(a, b+n/2,n/2+1);
    }

}



int main()
{
    int ar2[] = {1, 2, 3, 6};
    int ar1[] = {4, 6, 8, 10};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
        printf("Median is %d \n", getMedian(ar1, ar2, n1));
    else
        printf("Doesn't work for arrays of unequal size \n");
    return 0;
}
