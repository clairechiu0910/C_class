#include <stdio.h>
int main()
{
    int p,q,i,line=0;
    while(1)
    {
        scanf("%d%d",&p,&q);
        if(q==0)  //p¥i¥H=0
            break;
        if(line++!=0)
            printf("\n");
        int *judge;
        judge=malloc(sizeof(int)*1000100);
        for(i=0;i<1000100;i++)
            judge[i]=0;
        for(i=0;;i++)
        {
            p%=q;
            if(p==0)
            {
                printf("1");
                break;
            }
            if(judge[p]!=0)
            {
                printf("%d",i-judge[p]);
                break;
            }
            judge[p]=i;
            p*=10;
        }
        free(judge);
    }
    return 0;
}
