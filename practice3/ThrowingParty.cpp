#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

typedef struct
{
    int parent, value, choice, no, outdegree;
}vertex;

int main()
{
    int tcase;
    cin >> tcase;
    while(tcase--)
    {
        int nnode, tmp;
        cin >> nnode;
        vertex v[nnode + 1];
        for(int i = 0; i <= nnode; i++)
            v[i].outdegree = v[i].no = 0;

        cin >> v[1].value;
        v[1].choice = v[1].value;  //the initial value of choice
        for(int i = 2; i <= nnode; i++)
        {
            cin >> v[i].parent >> v[i].value;
            v[i].choice = v[i].value;
            v[v[i].parent].outdegree++;
        }

        std::queue<int> leave;

        for(int i = 2; i <= nnode; i++)
        {
            if(v[i].outdegree == 0)
                leave.push(i);
        }

        while(!leave.empty())
        {
            tmp = leave.front();
            leave.pop();

            v[v[tmp].parent].choice += v[tmp].no;
            v[v[tmp].parent].no += max(v[tmp].choice, v[tmp].no);

            v[v[tmp].parent].outdegree--;
            if(v[v[tmp].parent].outdegree == 0 && v[tmp].parent != 1)
                leave.push(v[tmp].parent);
        }

        cout << max(v[1].choice, v[1].no) << endl;
    }
}
