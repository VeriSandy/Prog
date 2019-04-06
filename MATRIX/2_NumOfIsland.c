//Find the number of islands | Set 1 (Using DFS)
//https://www.geeksforgeeks.org/find-number-of-islands/

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

void DFS(int M[R][C], int i, int j, int vis[R][C])
{
    //these are 8 neighbours for M[i][j]
    int row[] = {-1,-1,-1,0,0,1,1,1};
    int col[] = {-1,0,1,-1,1,-1,0,1};

    vis[i][j] = 1;

    int k = 0;

    //look for its possible neighbours
    for(; k < 8; k++)
    {
        if(isSafe(M, i+row[k], j + col[k], vis))
            DFS(M, i+row[k], j+col[k], vis);
    }
}

//it is like find the number of connected components
int NumOfIsland(int M[R][C])
{
    int vis[R][C];
    int i = 0, j = 0;
    int result = 0, count = 0;

    for(i = 0; i < R; i++)
        for(j = 0; j < C; j++)
            vis[i][j] = 0;

    for(i = 0; i < R; i++)
    {
        for(j = 0; j < C; j++)
        {
            if(M[i][j] && !vis[i][j])
            {
                DFS(M, i, j, vis);
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int M[R][C] = {
                     {1, 0, 0, 0, 1},
                     {0, 0, 1, 0, 0},
                     {1, 0, 1, 1, 0},
                     {0, 1, 0, 0, 0}
                    };

    printf("%d\n", NumOfIsland(M));
    return 0;
}
