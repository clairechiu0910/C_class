#include <stdio.h>
int main()
{
    int p,q,line=0;
    while(1)
    {
        scanf("%d%d",&p,&q);
        if(q==0)
            break;
        if(line++!=0)
            printf("\n");
        int i,j,temp;
        int *judge;
        judge=malloc(sizeof(int)*1000100);
        for(i=0;i<1000100;i++)
            judge[i]=0;
        for(i=0;;i++)
        {
            temp=p%q;
            if(temp==0)
            {
                printf("1");
                break;
            }
            if(judge[temp]!=0)
            {
                printf("%d",i-judge[temp]);
                break;
            }
            judge[temp]=i;
            p=temp*10;
        }
    }
    return 0;
}
