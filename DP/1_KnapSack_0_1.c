//https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
//Have basic strategy here, either include element or not

#include "../../COMMON/common.h"
int max(int a, int b)
{   
    return (a>b?a:b);
}

int KnapSack(int W, int *wt, int *val, int n)
{
    if(!W || !n) return 0;
   

    if(wt[n-1] > W)
        return KnapSack(W, wt, val, n-1);

    return max(KnapSack(W, wt, val, n-1), val[n-1]+ KnapSack(W-wt[n-1], wt, val, n-1));
}

int KnapSackUsingDP(int W, int *wt, int *val, int n)
{
    int k[n+1][W+1];
    int i = 0, w = 0;

    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W ; w++)
        {
            if(i == 0 || w == 0)
                k[i][w] = 0;

            else if(wt[i-1] <= w)
                k[i][w] = max(val[i-1] + k[i-1][w -wt[i-1]], k[i-1][w]);

            else
                k[i][w] = k[i-1][w];
        }
    }

    return k[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d\n", KnapSack(W, wt, val, n));
    printf("%d\n", KnapSackUsingDP(W, wt, val, n));
    return 0;
}
