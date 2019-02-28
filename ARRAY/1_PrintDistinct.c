//Print All Distinct Elements of a given integer array
//https://www.geeksforgeeks.org/print-distinct-elements-given-integer-array/
//Use hash table. If elment is not presen in hash table print and add it. If element is present in hash table dont print it. 

#include "../../COMMON/common.h"

void printDistinct(int *a, int n)
{
    int min = a[0], max = a[0], i = 0;

    for(i = 1; i < n ; i++)
    {
        if(min > a[i])
            min = a[i];
        if(max < a[i])
            max = a[i];
    }

    int hash[max - min +1];
   
    for(i = 0; i <= max - min  ; i++)
        hash[i] = 0;
    for(i = 0; i < n ; i++)
    {
        if(!hash[a[i] - min])
        {
            printf("%d ", a[i]);
            hash[a[i] - min]++;
        }
    }
    printf("\n");

    return ;
}

int main()
{
    //int arr[] = {6, 10, 5, 4, 9, 120, 4, 6, 10}; 
        int arr[] = {10, 5, 3, 4, 3, 5, 6};

    int n = sizeof(arr)/sizeof(arr[0]);
    printDistinct(arr, n);
    return 0;
}
