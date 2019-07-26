#include <stdio.h>

int main()
{
    int n, nextline = 0, i, j;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        if(nextline++ != 0)
            printf("\n");

        unsigned int down, right;
        unsigned int value[n][n], walk[n][n];
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
            {
                scanf("%u", &value[i][j]);
                down = 0;
                right = 0;
                if(i > 0)
                    down = walk[i - 1][j];
                if(j > 0)
                    right = walk[i][j - 1];
                walk[i][j] = (right > down) ? right : down;
                walk[i][j] += value[i][j];
            }
        printf("%u", walk[n - 1][n - 1]);

    }
}
