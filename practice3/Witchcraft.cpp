#include <stdio.h>

int main()
{
    int ncase;
    scanf("%d", &ncase);
    while(ncase--)
    {
        int desired, a, b, c, ma, mb, mc, i, j, k, ans = 0;
        scanf("%d%d%d%d%d%d%d", &desired, &a, &b, &c, &ma, &mb, &mc);
        for(i = 0; i <= a && ans != 1; i++)  //0 ~ a
            for(j = 0; j <= b && ans != 1; j++)
                for(k = 0; k <= c && ans != 1; k++)
                    if(desired == i * ma + j * mb + k * mc)
                        ans = 1;
        if(ans)
            printf("yes\n");  //\n directly
        else
            printf("no\n");
    }
}
