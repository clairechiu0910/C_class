#include <stdio.h>
int main()
{
    int mcase;
    scanf("%d",&mcase);
    while(mcase--)
    {
        int d_power,before=0,after=1,temp,i,j;
        int in[3],poly[2][30]={0};
        for(i=2;i>=0;i--)  //輸入的順序
            scanf("%d",&in[i]);
        scanf("%d",&d_power);
        poly[before][0]=1;  //第一次只要X1
        while(d_power--)
        {
            for(i=0;i<3;i++) //in
            {
                for(j=0;j<30;j++)  //poly
                {
                    poly[after][i+j]+=poly[before][j]*in[i];
                }
            }
            for(i=0;i<30;i++)
                poly[before][i]=0;
            temp=before;
            before=after;
            after=temp;
        }
        for(i=29;i>0;i--)
            if(poly[before][i]!=0)
                printf("%d ",poly[before][i]);
        printf("%d",poly[before][0]);
        if(mcase)
            printf("\n");
    }
}
