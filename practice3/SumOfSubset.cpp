#include <stdio.h>

int main()
{
    int tcase;
    scanf("%d", &tcase);
    while(tcase--)
    {
        int nweight, mitem, now, sum = 0, ans = 0, i, j;
        int can[201000] = {0};
        scanf("%d%d", &nweight, &mitem);

        for(i = 0; i < nweight; i++)
        {
            scanf("%d", &now);
            for(j = sum; j >= 0; j--)
                if(can[j])
                    can[j + now] = 1;
            sum += now;
            can[now] = 1;
        }
        for(i = 0; i < mitem; i++)
        {
            scanf("%d", &now);
            if(can[now])
            {
                ans++;
            }
        }

        printf("%d", ans);
        if(tcase)
            printf("\n");
    }
}
