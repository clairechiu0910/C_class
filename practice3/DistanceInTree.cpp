#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

typedef struct
{
    int parent, len, child, outdegree;
}point;

int main()
{
    int tcase;
    scanf("%d", &tcase);
    while(tcase--)
    {
        int nnode, tmp, ans = 0, i;
        scanf("%d", &nnode);

        point v[nnode + 1];
        for(i = 0; i <= nnode; i++)
            v[i].child = v[i].outdegree = 0;
        for(i = 2; i <= nnode; i++)
        {
            scanf("%d", &v[i].parent);
            v[v[i].parent].outdegree++;
        }
        for(i = 2; i <= nnode; i++)
            scanf("%d", &v[i].len);

        queue <int> leave;
        for(i = 2; i <= nnode; i++)
            if(v[i].outdegree == 0)
                leave.push(i);

        while(!leave.empty())
        {
            tmp = leave.front();
            leave.pop();

            ans += (v[tmp].child + 1) * (nnode - v[tmp].child - 1) * v[tmp].len * 2;

            v[v[tmp].parent].child += v[tmp].child + 1;
            v[v[tmp].parent].outdegree--;
            if(v[v[tmp].parent].outdegree == 0 && v[tmp].parent != 1)
                leave.push(v[tmp].parent);
        }

        printf("%d", ans);
        if(tcase)
            printf("\n");
    }
}
