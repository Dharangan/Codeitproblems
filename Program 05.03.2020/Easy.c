/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checksquare(int x)
{
    float t1=pow(x,1.0/2.0);
    int t2=t1;
    if(t2==t1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int checkcube(int x)
{
    float t1=pow(x,1.0/3.0);
    int t2=t1;
    if(t2==t1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=n;i>=1;i--)
    {
        if(checksquare(i) && checkcube(i))
        {
            printf("%d",i);
            break;
        }
    }

    return 0;
}
