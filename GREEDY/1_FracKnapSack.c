//Fractional Knapsack Problem
//https://www.geeksforgeeks.org/fractional-knapsack-problem/
//Follow greedy approach here
//think in terms of fractions and take first whatever is max and then go for rest

#include "../../COMMON/common.h"
typedef struct item
{   
    int val;
    int wt;
}Item;


int Partition(Item *a, int l, int h)
{   
    int i = l; 
    double p = a[h].val/a[h].wt;
    double temp;
    int index = 0;
    
    while(i < h)
    {   
        temp = a[i].val/a[i].wt;
        if(temp < p)
        {   
            Item b = a[i];
            a[i] = a[index];
            a[index] = b;
            index++;
        }
        i++;
    }
    Item b = a[h];
    a[h] = a[index];
    a[index] = b;
    
    return index;
}
void Sort(Item *a, int l, int h)
{
    if(l < h)
    {
        int p = Partition(a, l, h);
        Sort(a, l, p-1);
        Sort(a, p+1, h);
    }
    return;
}

double maxWt(Item *a, int n, int W)
{
    double final;
    int i = 0;
    int wt =0;//cur wt
    //first sort according the max value per unit wt
    Sort(a, 0, n-1);

    for(i =0 ; i <n ; i++)
    {
        if(wt + a[i].wt <= W)
        {
            wt += a[i].wt;
            final += a[i].val;
        }
        else
        {
            int remainingwt = W - wt;
            final += (a[i].val/a[i].wt)*remainingwt;
        }
    }

    return final;
}

int main()
{
    int W = 50;   //    Weight of knapsack 
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%lf\n", maxWt(arr, n, W));
    return 0;
}
