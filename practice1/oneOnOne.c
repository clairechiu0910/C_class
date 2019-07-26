#include <stdio.h>
#include <stdlib.h>
#define ENEMY 0
#define SOLDIER 1
int cmp(const void *a, const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int npeople;
    while(1)
    {
        scanf("%d",&npeople);
        if(npeople==0)
            break;
        int power[2][npeople];
        int i,j,win=0;
        for(i=0;i<npeople;i++)
            scanf("%d",&power[ENEMY][i]);
        for(i=0;i<npeople;i++)
            scanf("%d",&power[SOLDIER][i]);
        qsort(power[ENEMY],npeople,sizeof(power[ENEMY][0]),cmp);
        qsort(power[SOLDIER],npeople,sizeof(power[SOLDIER][0]),cmp);
        j=0;
        for(i=0;i<npeople;i++)  //enemy
        {
            while(j<npeople)
            {
                if(power[SOLDIER][j]>power[ENEMY][i])
                {
                    win++;
                    j++;
                    break;
                }
                j++;
            }
        }
        printf("%d\n",win);
    }
    return 0;
}
