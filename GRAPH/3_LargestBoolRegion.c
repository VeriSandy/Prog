
//Find length of the largest region in Boolean Matrix
//https://www.geeksforgeeks.org/find-length-largest-region-boolean-matrix/

/*
Use DFS funda and look for connected components kind of things
*/

#include "../../COMMON/common.h"

#define R 4
#define C 5

int isSafe(int M[R][C], int i, int j , int vis[R][C])
{
    return (i >=0) && (i < R) && (j >=0 ) && (j < C) && (M[i][j] && !vis[i][j]);
}

void DFS(int M[R][C], int i, int j, int vis[R][C], int *count)
{
    //these are 8 neighbours for M[i][j]
    int row[] = {-1,-1,-1,0,0,1,1,1};
    int col[] = {-1,0,1,-1,1,-1,0,1};
    /*static int row[] = {-1, -1, -1, 0, 0, 1,1, 1};
    static int col[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    */
    vis[i][j] = 1;

    int k = 0;

    //look for its possible neighbours
    for(; k<8; k++)
    {
        if(isSafe(M, i+row[k], j + col[k], vis))
        {
            *count = *count +1;
            DFS(M, i+row[k], j+col[k], vis, count);
        }
    }
}

int largestRegion(int M[R][C])
{   
    int vis[R][C]; 
    int i = 0, j = 0;
    int result = 0, count = 0;
    
    for(i = 0; i < R; i++)
        for(j = 0; j < C; j++)
            vis[i][j] = 0;
    
    /*
    for(i = 0; i < R; i++)
    {
        for(j = 0; j < C; j++)
        {
            printf("%d ", M[i][j]); 
        }
        printf("\n");
    }
    
    */
    
    for(i = 0; i < R; i++)
    {   
        for(j = 0; j < C; j++)
        {   
            if(M[i][j] && !vis[i][j])
            {   
                count = 1;
                DFS(M, i, j, vis, &count); 
                result  = result > count ? result :count;
            }
        }
    }
    
    return result;
}

int main()
{
    int M[R][C] = {
                     {0, 0, 0, 0, 0},
                     {0, 0, 1, 1, 0},
                     {1, 0, 1, 1, 0},
                     {0, 1, 0, 0, 0}
                    };

    printf("%d\n", largestRegion(M));
    return 0;
}
