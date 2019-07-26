#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int main()
{
    int tcase;
    scanf("%d", &tcase);
    while(tcase--)
    {
        int node, a, b, tmp, ans = 0, i;
        scanf("%d", &node);

        int parent[node], outdegree[node], height[node];
        for(i = 0; i < node; i++)
        {
            parent[i] = -1;
            outdegree[i] = 0;
            height[i] = 0;
        }
        for(i = 0; i < node - 1; i++)
        {
            scanf("%d%d", &a, &b);  //(a, b) = (parent, child)
            parent[b] = a;
            outdegree[a]++;
        }

        std::queue<int> leave;
        for(i = 0; i < node; i++)
            if(outdegree[i] == 0)
                leave.push(i);

        while(!leave.empty())
        {
            tmp = leave.front();
            leave.pop();

            //printf("tmp = %d\n", tmp);

            if(height[parent[tmp]] <= height[tmp] + 1 )
            {
                if(ans < height[parent[tmp]] + height[tmp] + 1)
                    ans = height[parent[tmp]] + height[tmp] + 1;
                height[parent[tmp]] = height[tmp] + 1;
            }

            /*for(i = 0; i < node; i++)
                printf("-%d ", height[i]);
            printf("\n");*/

            outdegree[parent[tmp]]--;
            if(outdegree[parent[tmp]] == 0 && parent[parent[tmp]] != -1)
                leave.push(parent[tmp]);
        }

        printf("%d", ans);
        if(tcase)
            printf("\n");
    }
    return 0;
}
