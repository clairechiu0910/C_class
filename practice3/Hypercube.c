#include <stdio.h>
#include <stdlib.h>

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

        int node = 1 << n, tmp;
        int *w, *max;
        w = malloc(sizeof(int) * node);
        max = malloc(sizeof(int) * node);
        for(i = 0; i < node; i++)
        {
            scanf("%d", &w[i]);
            max[i] = 0;
        }

        for(i = 0; i < node; i++)
        {
            for(j = 0; ; j++)
            {
                if((1 << j) >= node)
                    break;
                if(((1 << j) & i) == 0)
                {
                    tmp = i | (1 << j);
                    if((w[i] + max[i]) > max[tmp])
                        max[tmp] = max[i] + w[i];
                }
            }
        }
        printf("%d", max[node - 1] + w[node - 1]);
    }
    return 0;
}
