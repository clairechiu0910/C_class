#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int ncase, line = 0, i, j, k;
    while(1)
    {
        scanf("%d", &ncase);
        if(ncase == 0)
            break;
        if(line++ != 0)
            printf("\n");
        int seg[ncase];
        int ans = 0;
        for(i = 0; i < ncase; i++)
            scanf("%d", &seg[i]);
        qsort(seg, ncase, sizeof(int), cmp);
        //for(i=0; i<ncase; i++)
            //printf("%d ", seg[i]);
        //printf("\n");
        for(i = 2; i < ncase; i++)
        {
            for(j = 0; j < i; j++)
            {
                for(k = j+1; k < i; k++)
                    if(seg[i] < seg[j]+seg[k])
                        ans++;
            }
        }
        printf("%d", ans);

    }
    return 0;
}
