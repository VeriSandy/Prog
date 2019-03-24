//A Program to check if strings are rotations of each other or not
//https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

/*
    IDEA --
    let say strings are s1 , s2
    make s1s1 and see if s2 is part of this whole string
*/

#include "../../COMMON/common.h"
int areRotations(char *s1, char *s2)
{
    int l = strlen(s1);
    int temp = 0;
    char *s = malloc(sizeof(char)*2*l);
    memset(s, 0x0, 2*l);

    strcat(s, s1);
    strcat(s, s1);

    if(strstr(s, s2))
        temp = 1;

    free(s);
    s = NULL;
    return temp;
}
int main()
{
    char *str1 = "AACD";
    char *str2 = "ACDA";
    if (areRotations(str1, str2))
       printf("Strings are rotations of each other\n");
    else
       printf("Strings are not rotations of each other\n");
    return 0;
}
