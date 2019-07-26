#include <stdio.h>
#define X 0
#define Y 1
int main()
{
    int ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
        int mpoint,i,j,temp,max=0;
        scanf("%d",&mpoint);
        int coe[mpoint][2];
        for(i=0;i<mpoint;i++)
            scanf("%d%d",&coe[i][X],&coe[i][Y]);
        for(i=0;i<mpoint;i++)
        {
            for(j=i+1;j<mpoint;j++)
            {
                temp=(coe[i][X]-coe[j][X])*(coe[i][Y]-coe[j][Y]);
                if(temp<0)
                    temp*=-1;
                if(temp>max)
                    max=temp;
            }
        }
        printf("%d",max);
        if(ncase)
            printf("\n");
    }
    return 0;
}
