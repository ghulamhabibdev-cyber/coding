#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
pair<int, int> maxScore(int n)
{
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int st = 0;
    int end = n - 1;
    int serajScore = 0;
    int dimaScore = 0;
    bool searajTurn = true;
    bool dimaTrun = false;
    int count = 0;
    while (st <= end)
    {
    //     cout << "St : " << st << endl;
    //     cout << "end : " << end << endl;
    //     cout << "Dima Turn : " << dimaTrun << endl;
    //     cout << "Seraj Turn : " << searajTurn << endl;
        if (arr[st] > arr[end])
        {
            if (searajTurn)
            {
                serajScore += arr[st];

                if (count == 0)
                {
                    dimaTrun = !dimaTrun;
                    count++;
                }
            }
            else
            {
                dimaScore += arr[st];
            }
            searajTurn = !searajTurn;
            dimaTrun = !dimaTrun;
            st++;
        }
        else
        {
            if (searajTurn)
            {
                serajScore += arr[end];
            }
            else
            {
                dimaScore += arr[end];
            }
            searajTurn = !searajTurn;
            dimaTrun = !dimaTrun;
            end--;
        }
    }
    pair<int, int> ans = make_pair(serajScore, dimaScore);

    return ans;
}
int main()
{
    int n;
    cin >> n;
    pair<int, int> p = maxScore(n);
    cout << p.first << " " << p.second << endl;
    return 0;
}