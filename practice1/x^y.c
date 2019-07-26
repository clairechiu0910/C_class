#include <stdio.h>
int main()
{
    int ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
        long long int x,y,p,ans=1,i=1;
        scanf("%lld%lld%lld",&x,&y,&p);
        x%=p;
        if(y&i)
            ans=x;
        for(i=2;i<=y;i*=2)
        {
            x=x*x%p;
            if(y&i)
                ans=ans*x%p;
        }
        printf("%lld",ans);
        if(ncase)
            printf("\n");
    }
    return 0;
}
