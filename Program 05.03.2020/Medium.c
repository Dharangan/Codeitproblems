/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Did for two cases
int main()
{
    int n,s,p,k,i,j,a=1,b,c,f=0;
    scanf("%d %d %d",&s,&p,&k);
    
    switch(k)
    {
        case 1:
            if(s==p)
            {
                printf("%d",s);
            }
            break;
        case 2:
            for(i=1;i<=s;i++)
            {
                n=s-i;
                if(n*i==p)
                {
                    printf("%d %d",i,n);
                    break;
                }
            }
            break;
        case 3:
            for(i=1;i<=s;i++)
            {
                b=s-i;
                for(j=1;j<=s;j++)
                {
                    b=s-i-j;
                    if(b*i*j==p)
                    {
                        printf("%d %d %d",i,j,b);
                        f=1;
                        break;
                    }
                }
                if(f)
                {
                    break;
                }
            }
            break;
            
    }

    return 0;
}
