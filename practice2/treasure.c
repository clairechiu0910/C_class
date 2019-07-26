#include <stdio.h>
#define MAXC 200
#define DONE 1

int line[MAXC][MAXC];

int DFS(int value[MAXC], int judge[MAXC], int nCity, int now)
{
    judge[now] = DONE;
    int max = value[now], tmp, i;
    for(i = 0; i < nCity; i++)
    {
        if(line[now][i] && judge[i] != DONE)
        {
            tmp = DFS(value, judge, nCity, i);
            if(tmp > max)
                max = tmp;
        }
    }
    return max;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int nextline = 0, nCity, mRoad, tStart;
    while(1)
    {
        scanf("%d%d%d", &nCity, &mRoad, &tStart);
        if(nCity == 0 && mRoad == 0 && tStart == 0)
            break;
        if(nextline++ != 0)
            printf("\n");
        int max = 0, tmp, uFrom, vTo, i, j;
        int scity[tStart], value[MAXC], judge[MAXC] = {0};
        for(i = 0; i < tStart; i++)
            scanf("%d", &scity[i]);
        for(i = 0; i < nCity; i++)
            scanf("%d", &value[i]);
        for(i = 0; i < MAXC; i++)
            for(j = 0; j < MAXC; j++)
                line[i][j] = 0;
        for(i = 0; i < mRoad; i++)
        {
            scanf("%d%d", &uFrom, &vTo);
            line[uFrom][vTo] = 1;
        }
        for(i = 0; i < tStart; i++)
        {
            if(judge[scity[i]] != DONE)
            {
                tmp = DFS(value, judge, nCity, scity[i]);
                if(tmp > max)
                    max = tmp;
            }
        }
        printf("%d", max);
    }
    return 0;
}
