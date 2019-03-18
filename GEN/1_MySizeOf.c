//https://www.geeksforgeeks.org/implement-your-own-sizeof/

#include "../../COMMON/common.h"
#define MYSIZEOF(x) (char *)(&x + 1) - (char *)&x

struct me
{
    int a;
    int b;
    char c;
}My;

int main()
{
    int x;
    printf("%ld \n", MYSIZEOF(x));
    printf("%ld \n", sizeof(int));
    printf("%ld \n", sizeof(x));
    printf("%ld \n", MYSIZEOF(My));
    printf("%ld \n", sizeof(My));
    printf("%ld \n", sizeof(struct me));
    return 0;
}
