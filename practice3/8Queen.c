#include <stdio.h>

int min, max;
int position[10], chess[10][10];

void queen(int nowRow, int n)
{
    int conflict, tmp = 0, i, j;
    if(nowRow == n)
    {
        for(i = 0; i < n; i++)
            tmp += chess[i][position[i]];
        if(tmp > max)
            max = tmp;
        if(tmp < min)
            min = tmp;
        return;
    }
    for(i = 0; i < n; i++)
    {
        conflict = 0;
        for(j = 0; j < nowRow && !conflict; j++)
        {
            if(position[j] == i || (nowRow - j) == abs(i - position[j]))
                conflict = 1;
        }
        if(!conflict)
        {
            position[nowRow] = i;
            queen(nowRow + 1, n);
        }
    }
    return;
}

int main()
{
    int tcase;
    scanf("%d", &tcase);
    while(tcase--)
    {
        int n, i, j;
        scanf("%d", &n);
        max = -1, min = 1000;
        for(i = 0; i < 10; i++)
        {
            position[i] = -1;
            for(j = 0; j < 10; j++)
                chess[i][j] = -1;
        }

        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                scanf("%d", &chess[i][j]);

        queen(0, n);

        if(max == -1 || min == 1000)
            printf("-1 -1");
        else
            printf("%d %d", max, min);
        if(tcase)
            printf("\n");
    }
}
