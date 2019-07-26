#include <stdio.h>
#define POSI 0
#define NEGA 1
int main()
{
    int ncell,mcase,line=0,i,j;
    while(1)
    {
        scanf("%d%d",&ncell,&mcase);
        if(ncell==0||mcase==0)
            break;
        if(line++!=0)//每組最後一個會和下一組第一個連在一起
            printf("\n");
        int line[ncell];
        for(i=0;i<ncell;i++)
            scanf("%d",&line[i]);
        while(mcase--)
        {
            int place,dire;
            int judge[ncell][2];
            for(i=0;i<ncell;i++)
            {
                judge[i][POSI]=0;
                judge[i][NEGA]=0;
            }
            scanf("%d%d",&place,&dire);
            for(i=1;;i++)
            {
                //printf("place=%d dire=%d\n",place,dire);
                if(place>=ncell)
                {
                    printf("Forward");
                    break;
                }
                if(place<0)
                {
                    printf("Backward");
                    break;
                }
                if(dire>0)
                {
                    if(judge[place][POSI]!=0)  //
                    {
                        printf("Cycle %d",i-judge[place][POSI]);
                        break;
                    }
                    if(line[place]<0)
                        dire*=-1;
                    judge[place][POSI]=i;
                    place+=line[place];
                }
                else  //dire<0
                {
                    if(judge[place][NEGA]!=0)  //
                    {
                        printf("Cycle %d",i-judge[place][NEGA]);
                        break;
                    }
                    if(line[place]<0)
                        dire*=-1;
                    judge[place][NEGA]=i;
                    place-=line[place];
                }
                //for(j=0;j<ncell;j++)
                    //printf("%d**%d  ",judge[j][POSI],judge[j][NEGA]);
            }
            if(mcase)
                printf("\n");
        }
    }
    return 0;
}
