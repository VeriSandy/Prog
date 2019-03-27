//XOR of all subarray XORs | Set 1
//https://www.geeksforgeeks.org/xor-subarray-xors/

/*
Input : arr[] = [3, 5, 2, 4, 6]
Output : 7
Total XOR of all subarray XORs is,
(3) ^ (5) ^ (2) ^ (4) ^ (6)
(3^5) ^ (5^2) ^ (2^4) ^ (4^6)
(3^5^2) ^ (5^2^4) ^ (2^4^6)
(3^5^2^4) ^ (5^2^4^6) ^
(3^5^2^4^6) = 7    

Any element at index i will appear (i+1)*(N-i) times in all sub arrays. Use this concept

*/

#include "../../COMMON/common.h"

int XORSubarrays(int *a, int N)
{
    int i = 0;
    int temp = 0, xor = 0;

    for(i = 0;i < N; i++)
    {
        temp = (i+1)* (N-i);
        if(temp%2)
            xor ^= a[i];
    }
    return xor;
}


int main()
{
    int arr[] = {3, 5, 2, 4, 6, 8};
    int N = sizeof(arr) / sizeof(arr[0]);

    printf("%d \n", XORSubarrays(arr, N));
    return 0;
}
