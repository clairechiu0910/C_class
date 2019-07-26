#include <stdio.h>
#include <stdlib.h>
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
        int n_item,m_pelple,i,j,pay=0;
        scanf("%d%d",&n_item,&m_pelple);
        int weight[n_item],power[m_pelple];
        for(i=0;i<n_item;i++)
            scanf("%d",&weight[i]);
        for(i=0;i<m_pelple;i++)
            scanf("%d",&power[i]);
        qsort(weight,n_item,sizeof(weight[0]),cmp);
        qsort(power,m_pelple,sizeof(power[0]),cmp);
        for(i=0,j=0;i<n_item;i++)  //i>item  j>people
        {
            while(j<m_pelple)
            {
                if(power[j]>=weight[i])
                {
                    pay+=power[j];
                    weight[i]=-1;
                    j++;
                    break;
                }
                else
                    j++;
            }
            if(weight[i]!=-1)  //判斷是不是有人扛
            {
                printf("-1");
                pay=0;
                break;
            }
        }
        if(pay)
            printf("%d",pay);
        if(tcase)
            printf("\n");
    }
    return 0;
}
