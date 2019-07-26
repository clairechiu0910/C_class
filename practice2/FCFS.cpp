#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

int main()
{
    int tcase;
    cin >> tcase;
    while(tcase--)
    {
        int nJob, dline, sum = 0, up, down, tmp, judge, buffer, ans = 1;
        cin >> nJob >> dline;
        int time[nJob];
        for(int i=0; i<nJob; i++)
        {
            cin >> time[i];
            sum += time[i];
            if(time[i] > dline)
            {
                cout <<-1;
                ans = 0;
            }
        }
        if(ans)
        {
            down = sum / dline + 1;
            up = nJob;
            while(down < up)
            {
                cout << up << "  "<< down << endl;
                tmp = (down + up)/2;
                judge = 1;
                std::priority_queue <int> total;
                for(int i = 0; i < tmp; i++)
                    total.push(0);
                for(int i = 0; i < nJob; i++)
                {
                    buffer = total.top();
                    total.pop();
                    buffer -= time[i];
                    if(buffer < dline * -1)
                    {
                        judge = 0;
                        break;
                    }
                    total.push(buffer);
                }
                if(judge)
                    up = tmp;
                else
                    down = tmp + 1;
            }
            cout << up;
        }
        if(tcase)
            cout << endl;
    }
    return 0;
}
