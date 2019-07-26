#include <stdio.h>
int cmp(const void *a, const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    int tcase;
    scanf("%d",&tcase);
    while(tcase--)
    {
        int nbox,i;
        scanf("%d",&nbox);
        long long int temp=0,total=0;
        long long int time[nbox];
        for(i=0;i<nbox;i++)
            scanf("%lld",&time[i]);
        qsort(time,nbox,sizeof(time[0]),cmp);
        temp=time[0];
        total+=temp;
        for(i=1;i<nbox;i++)
        {
            temp+=time[i]+time[i-1];
            total+=temp;
        }
        printf("%lld",total);
        if(tcase)
            printf("\n");
    }
    return 0;
}
