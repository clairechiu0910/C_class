#include <stdio.h>

int main()
{
    int set, n;
    for(set = 1;; set++)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        int total = 0, ave, k = 0, i;
        int height[n];
        for(i = 0; i < n; i++)
        {
            scanf("%d", &height[i]);
            total += height[i];
        }
        ave = total / n;
        for(i = 0; i < n; i++)
            if(height[i] > ave)
                k += (height[i] - ave);

        printf("Set #%d\nThe minimum number of moves is %d.\n\n", set, k);  //notice \n\n
    }
    return 0;
}
