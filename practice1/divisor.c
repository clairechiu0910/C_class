#include <stdio.h>
int gcd(int a, int b)
{
    if(a%b==0)
        return b;
    else
        return (gcd(b,a%=b));
}
int main()
{
    int ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
        int q1,r1,q2,r2,i,d;
        scanf("%d%d%d%d",&q1,&r1,&q2,&r2);
        q1-=r1;
        q2-=r2;
        d=gcd(q1,q2);
        printf("1");
        for(i=2;i<=d;i++)
            if(d%i==0)
                printf(" %d",i);
        if(ncase)
            printf("\n");
    }
    return 0;
}
