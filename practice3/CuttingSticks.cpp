#include <stdio.h>

int table[1000][1000], place[50];

int cost(int a, int b, int cut, int len)
{
    if(table[a][b] != -1)
        return table[a][b];
    int tmp, min = 1000000, i;
    for(i = 0; i < cut; i++)
    {
        if(place[i] <= a)
            continue;
        if(place[i] >= b)
            break;
        tmp = cost(a, place[i], cut, len) + cost(place[i], b, cut, len);
        if(tmp < min)
            min = tmp;
    }
    if(min == 1000000)
    {
        table[a][b] = 0;
        return 0;
    }
    table[a][b] = min + b - a;
    return min + b - a;
}

int main()
{
    int nextline = 0, len, cut, i, j;
    while(1)
    {
        scanf("%d", &len);
        if(len == 0)
            break;
        if(nextline++ != 0)
            printf("\n");

        scanf("%d", &cut);
        for(i = 0; i < 1000; i++)
            for(j = 0; j < 1000; j++)
                table[i][j] = -1;
        for(i = 0; i < cut; i++)
            scanf("%d", &place[i]);

        printf("The minimum cutting is %d.", cost(0, len, cut, len));
    }
}
