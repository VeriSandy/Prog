//Stock Buy Sell to Maximize Profit
//https://www.geeksforgeeks.org/stock-buy-sell/
/*
The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days.
For example, if the given array is {100, 180, 260, 310, 40, 535, 695}, the maximum profit can earned by buying on day 0, selling on day 3.
Again buy on day 4 and sell on day 6. If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.

Idea -
    
1. Find first min and first max, in this time he can earn first time
2. Keep repeating this
3. If there is no max, for exmaple in decrasing array there cant be any profit
*/

#include "../../COMMON/common.h"

void stockBuySell(int *a, int n)
{
    int i = 0, min = 0, max = 0, flag = 0;

    for(i = 1; i < n ; i++)
    {
        while(i < n && a[i] < a[i-1])
            i++;

        if(i == n) //when array is decreasing
            break;

        min = i-1;

        while(i < n && a[i] > a[i-1])
            i++;

        max = i-1;

        if(max > min)
        {
            flag = 1;
            printf("buy at %d day and sell at %d day\n", min +1, max +1);
        }
    }

    if(!flag)
        printf("he can never sell\n");

    return;
}

int main()
{
    //int price[] = {100, 180, 260, 310, 40, 535, 695}; 
    //int price[] = {500, 480, 360, 310, 40, 535, 695}; 
    //int price[] = {500, 480, 360, 350, 340, 335, 335}; 
    //int price[] = {100, 280, 360, 450, 640, 735, 835}; 
   // int price[] = {100, 280}; 
    //int price[] = {100}; 
    int price[] = {100, 280, 360, 450, 440, 345, 335};
    int n = sizeof(price)/sizeof(price[0]);
    stockBuySell(price, n);
    return 0;
}
