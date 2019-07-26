#include <stdio.h>
#define POSI 0
#define NEGA 1
int main()
{
    int ncell, mcase, i, line=0;
    while(1)
    {
        if(line++!=0)
            printf("\n");
        scanf("%d%d", &ncell, &mcase);
        if(ncell==0)
            break;
        int cell[ncell], test[ncell][2];
        for(i=0;i<ncell;i++)
            scanf("%d", &cell[i]);
        while(mcase--)
        {
            int place, direc;
            scanf("%d%d", &place, &direc);
            for(i=0;i<ncell;i++)
            {
                test[i][POSI]=0;
                test[i][NEGA]=0;
            }
            for(i=1;;i++)
            {
                //printf("place=%d dire=%d\n", place, direc);
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
                if(direc>0)
                {
                    if(test[place][POSI]!=0)
                    {
                        printf("Cycle %d", i-test[place][POSI]);
                        break;
                    }
                    test[place][POSI]=i;
                    if(cell[place]<0)
                        direc*=-1;
                    place+=cell[place];
                }
                else
                {
                    if(test[place][NEGA]!=0)
                    {
                        printf("Cycle %d", i-test[place][NEGA]);
                        break;
                    }
                    test[place][NEGA]=i;
                    if(cell[place]<0)
                        direc*=-1;
                    place-=cell[place];
                }
            }
            if(mcase)
                printf("\n");
        }
    }
    return 0;
}
