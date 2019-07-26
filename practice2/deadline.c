#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int time;
    int dline;
}JOB;

int cmp(const void *a, const void *b)
{
    return (((JOB*)a)->dline-((JOB*) b)->dline);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int tcase;
    scanf("%d", &tcase);
    while(tcase--)
    {
        int nJob, all = 0, i, ans = 1;
        scanf("%d", &nJob);
        JOB array[nJob];
        for(i = 0; i< nJob; i++)
        {
            scanf("%d", &array[i].time);
        }
        for(i = 0; i< nJob; i++)
        {
            scanf("%d", &array[i].dline);
        }
        qsort(array, nJob, sizeof(JOB), cmp);
        //for(i = 0; i < nJob; i++)
            //printf("%d %d\n", array[i].time, array[i].dline);
        for(i = 0; i < nJob; i++)
        {
            all += array[i].time;
            if(all > array[i].dline)
            {
                ans = 0;
                break;
            }
        }
        if(ans)
            printf("Yes");
        else
            printf("No");
        if(tcase)
            printf("\n");
    }
}
