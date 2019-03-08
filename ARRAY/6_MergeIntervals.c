//Merge Overlapping Intervals
//https://www.geeksforgeeks.org/merging-intervals/

/*
For example, let the given set of intervals be {{1,3}, {2,4}, {5,7}, {6,8} }. The intervals {1,3} and {2,4} overlap with each other, so they should be merged and become {1, 4}. Similarly {5, 7} and {6, 8} should be merged and become {5, 8}
*/
/*
Idea - 
1. Very general approach -- Take one interval and see if there is any other interval it can be merged with. If it can merge it or move on. O(n2).
2. Sort the intervals as per the start of the interval. One it is sorted see it ith interval can be merged with (i+1)th interval and if it can then keep merging else  print it and move on.
*/
#include "../../COMMON/common.h"


typedef struct interval
{   
    int s;
    int e;
}Interval;

int part(Interval *a, int l, int h)
{   
    int p = a[h].s;
    int i = l;
    int index = l;
    Interval temp;
    
    while(i < h)
    {   
        if(a[i].s < p)
        {   
            temp = a[index];
            a[index] = a[i];
            a[i] = temp;
            index++;
        }
        i++;
    }
    
    temp = a[h];
    a[h] = a[index];
    a[index] = temp;
    return index;
}

void Sort(Interval *a, int l, int h)
{
    if(l < h)
    {
        int p = part(a, l, h);
        Sort(a, l, p-1);
        Sort(a, p+1, h);
    }
    return;
}

void mergeIntervals(Interval *a, int n)
{
    int i = 0;
    printf("input \n");
    for(i = 0; i < n ; i++)
        printf("(%d,%d) ", a[i].s, a[i].e);
    printf("\n");

    printf("Sorted Input \n");
    Sort(a, 0, n-1);
    for(i = 0; i < n ; i++)
        printf("(%d,%d) ", a[i].s, a[i].e);
    printf("\n");

    i = 1;
    Interval temp = a[0];
    while(i < n)
    {
        if(temp.e < a[i].s)
        {
            printf("[%d,%d] ", temp.s, temp.e);
            temp = a[i];
        }
        else
        {
            if(temp.e < a[i]. e)
                temp.e = a[i]. e;
        }
        i++;
    }

    printf("[%d,%d]", temp.s, temp.e);
    printf("\n");

    return;
}

int main()
{
    Interval arr[] =  { {1, 2}, {6,8}, {3,9}, {4,5}, {4,7} };
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}
