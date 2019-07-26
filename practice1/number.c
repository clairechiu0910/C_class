#include <stdio.h>
int main()
{
    int nshort,mlong,line=0;
    while(scanf("%d%d",&nshort,&mlong)!=EOF)
    {
        if(line++!=0)
            printf("\n");
        int count=0;
        while(mlong>9)
        {
            if(mlong%100==nshort)
                count++;
            mlong/=10;
        }
        printf("%d",count);
    }
    return 0;
}
