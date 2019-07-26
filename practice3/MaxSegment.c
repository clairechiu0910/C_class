#include <stdio.h>

int main()
{
    int tcase;
    scanf("%d", &tcase);
    while(tcase--)
    {
        int n, in, max = 0, i;
        scanf("%d", &n);
        int sum[n];
        for(i = 0; i < n; i++)
        {
            scanf("%d", &in);
            if(i == 0)
                sum[i] = in;
            else
                sum[i] = (sum[i - 1] > 0) ? sum[i - 1] + in : in;  //sum[i] = the largest segment to array i
            if(sum[i] > max)
                max = sum[i];
        }
        printf("%d\n", max);
    }
    return 0;
}
