#include <stdio.h>

int main()
{
    int tcase;
    scanf("%d", &tcase);
    while(tcase--)
    {
        int njob, mmach, i, j, index, max = 0;
        scanf("%d%d", &njob, &mmach);
        int time[njob], now[mmach];
        for(i = 0; i < njob; i++)
            scanf("%d", &time[i]);
        for(i = 0; i < mmach; i++)
            now[i] = 0;
        for(i = 0; i < njob; i++)
        {
            index = 0;
            for(j = 1; j < mmach; j++)
                if(now[j] < now[index])
                    index = j;
            now[index] += time[i];
        }
        for(j = 0; j < mmach; j++)
            if(now[j] > max)
                max = now[j];
        printf("%d", max);
        if(tcase)
            printf("\n");
    }
}
