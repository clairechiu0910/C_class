#include <stdio.h>

int main()
{
    int tcase;
    scanf("%d", &tcase);
    while(tcase--)
    {
        int nspy, sum = 0, i;
        scanf("%d", &nspy);
        int moti[nspy], parent[nspy];
        moti[0] = 0;
        parent[0] = 0;
        for(i = 1; i < nspy; i++)
        {
            scanf("%d", & parent[i]);
            moti[i] = 0;
        }
        for(i = nspy-1; i > 0; i--)
        {
            if(moti[i] == 0)
            {
                //printf("i = %d\n", parent[i]);
                moti[parent[i]] = 1;
            }
        }
        for(i = 0; i < nspy; i++)
            if(moti[i] != 0)
                sum++;
        printf("%d", sum);
        if(tcase)
            printf("\n");
    }
    return 0;
}
