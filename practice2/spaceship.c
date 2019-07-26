#include <stdio.h>
#include <math.h>

int main()
{
    int ngate, nextline = 0;
    while(1)
    {
        scanf("%d", &ngate);
        if(ngate == 0)
            break;
        if(nextline++ != 0)
            printf("\n");
        int temp[ngate][2];
        int t0, t1, t00, t11, t01, t10, i;
        for(i = 0; i < ngate; i ++)
            scanf("%d%d", &temp[i][0], &temp[i][1]);
        t0 = abs(temp[0][0] - 1000);
        t1 = abs(temp[0][1] - 1000);
        for(i = 1; i < ngate; i++)
        {
            t00 = t0 + abs(temp[i-1][0] - temp[i][0]);
            t10 = t1 + abs(temp[i-1][1] - temp[i][0]);
            t01 = t0 + abs(temp[i-1][0] - temp[i][1]);
            t11 = t1 + abs(temp[i-1][1] - temp[i][1]);
            //printf("0--%d %d\n1--%d% d\n",t00,t10,t01,t11);
            if(t00 < t10)
                t0 = t00;
            else
                t0 = t10;
            if(t01 < t11)
                t1 = t01;
            else
                t1 = t11;
        }
        if(t0 < t1)
            printf("%d", t0);
        else
            printf("%d", t1);
    }
    return 0;
}
