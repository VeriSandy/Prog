//Median of two sorted arrays of different sizes
//https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/


//Idea -- use array merging approach of merge sort.
//No need to merge actually, just keep track of middle element(s)
//if sizes are m and n, if one is even another is odd, total will be odd otherwise will be even


//O(m+n)

#include "../../COMMON/common.h"

int getMedian(int *a1, int *a2, int n1, int n2)
{   
    int i = 0, j = 0, k = 0;
    int m1 = -1, m2 = -1;
    
    if((n1+n2)%2)
    {   
        for(k = 0; k <= (n1+n2)/2; k++)
        {   
            if(i != n1 && j != n2) 
                m1 = a1[i] < a2[j] ? a1[i++] : a2[j++];
            
            else if(i < n1)
                m1 = a1[i++];
            
            else     
                m1 = a2[j++];
        }
        return m1;
    }
    else
    {   
        for(k = 0; k <= (n1+n2)/2; k++)
        {   
            m2 = m1;
            if(i != n1 && j != n2) 
                m1 = a1[i] < a2[j] ? a1[i++] : a2[j++];
                 
            else if(i < n1)
                m1 = a1[i++];
            
            else
                m1 = a2[j++];
        }
        
        return (m1+m2)/2;
    }
    return 0;
}

int main()
{
    //int ar1[] = {900};  
    int ar1[] = {900, 1000};
    int ar2[] = {5, 8, 10, 20};

    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    printf("Median %d\n", getMedian(ar1, ar2, n1, n2));

    return 0;
}

