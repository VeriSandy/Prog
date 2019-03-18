//Little and Big Endian Mystery
//https://www.geeksforgeeks.org/little-and-big-endian-mystery/
/*

    Little Endian ==> LSB First
    Big Endian ==> MSB first
    
    in 0x01234567
        
    01 is MSB
    67 is LSB

    in BIG Endian MSB(01) will come first at lower address
    in Little Endian LSB(67) will come first at lower address
    
*/

#include "../../COMMON/common.h"

int main()
{
    int i = 1;
    char *c = (char *)&i;

    if(*c & 1)
        printf("Little Endian\n");
    else
        printf("Big Endian\n");

    return 0;
}
