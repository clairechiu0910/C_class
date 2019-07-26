#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int right;
    int left;
}interval;

int cmp(const void *a, const void *b)
{
    if(((interval*)a)->left != ((interval*)b)->left)
        return ((interval*)a)->left - ((interval*)b)->left;
    else
        return ((interval*)a)->right - ((interval*)b)->right;
}

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while(ncase--)
    {
        int mSeg, tmp, sum = 0, end, i;
        scanf("%d", &mSeg);
        interval inter[mSeg];
        for(i = 0; i < mSeg; i++)
        {
            scanf("%d%d", &inter[i].left, &inter[i].right);
            if(inter[i].left > inter[i].right)
            {
                tmp = inter[i].left;
                inter[i].left = inter[i].right;
                inter[i].right = tmp;
            }
        }
        qsort(inter, mSeg, sizeof(interval), cmp);
        sum += inter[0].right - inter[0].left;
        end = inter[0].right;
        for(i = 1; i < mSeg; i++)
        {
            if(inter[i].left < end)
            {
                if(inter[i].right > end)
                    sum += inter[i].right - end;
            }
            if(inter[i].left > end)
            {
                sum += inter[i].right - inter[i].left;
            }
            if(inter[i].right > end)
                end = inter[i].right;
        }
        printf("%d", sum);
        if(ncase)
            printf("\n");
    }
    return 0;
}
