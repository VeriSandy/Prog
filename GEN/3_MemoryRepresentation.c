//https://www.geeksforgeeks.org/little-and-big-endian-mystery/
  
#include "../../COMMON/common.h"

void PrintMemoryLayout(char *s, int n)
{
    int i = 0;

    for(; i < n ; i++)
        printf("%.2x ", s[i]);

    printf("\n");
    return;
}


int main()
{
    int i = 0x01234567;

    PrintMemoryLayout((char *)&i, sizeof(i));
    return 0;
}
