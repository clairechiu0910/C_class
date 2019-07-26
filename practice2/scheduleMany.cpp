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
        int njob, mmach, temp, maxx = 0;
        cin >> njob >> mmach;
        int time[njob];
        for(int i=0; i<njob; i++)
            cin >> time[i];
        std::priority_queue <int> total;
        for(int i=0; i<mmach; i++)
            total.push(0);
        for(int i=0; i<njob; i++)
        {
            temp = total.top();
            total.pop();
            temp -= time[i];
            if(temp < maxx)
                maxx = temp;
            total.push(temp);
        }
        cout << maxx * -1;
        if(tcase)
            cout << endl;
    }
    return 0;
}
