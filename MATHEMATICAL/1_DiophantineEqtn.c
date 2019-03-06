//Linear Diophantine Equations
//https://www.geeksforgeeks.org/linear-diophantine-equations/
/*
A Diophantine equation is a polynomial equation, usually in two or more unknowns, such that only the integral solutions are required. An Integral solution is a solution such that all the unknown variables take only integer values.

Given three integers a, b, c representing a linear equation of the form : ax + by = c. Determine if the equation has a solution such that x and y are both integral values.

Examples :

Input : a = 3, b = 6, c = 9
Output: Possible
Explanation : The Equation turns out to be, 
3x + 6y = 9 one integral solution would be 
x = 1 , y = 1

Input : a = 3, b = 6, c = 8
Output : Not Possible
Explanation : o integral values of x and y 
exists that can satisfy the equation 3x + 6y = 8

Input : a = 2, b = 5, c = 1
Output : Possible
Explanation : Various integral solutions
possible are, (-2,1) , (3,-1) etc.

<<<<===================================>>>>>
For linear Diophantine equation equations, integral solutions exist if and only if, the GCD of coefficients of the two variables divides the constant term perfectly. In other words the integral solution exists if, GCD(a ,b) divides c.

Thus the algorithm to determine if an equation has integral solution is pretty straightforward.

Find GCD of a and b
Check if c % GCD(a ,b) ==0
If yes then print Possible
Else print Not Possible
*/


#include "../../COMMON/common.h"

int GCD(int a, int b)
{
    if(!b)  return a;

    return GCD(b, a%b);
}

int isPossible(int a, int b, int c)
{
    return (!(c%GCD(a,b))?1:0);
}

int main()
{
    int a = 3, b = 6, c = 9;
    printf("%s\n", isPossible(a, b, c)?"Possible":"Not Possible");

    a = 3, b = 6, c = 8;
    printf("%s\n", isPossible(a, b, c)?"Possible":"Not Possible");

    a = 2, b = 5, c = 1;
    printf("%s\n", isPossible(a, b, c)?"Possible":"Not Possible");

    return 0;
}
