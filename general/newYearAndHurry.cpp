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
int problemCount(int n)
{

    int start = 0;
    int end = n;
    int kMint;
    cin >> kMint;
    int mid = start + (end - start) / 2;
    int count = 0;
    while (start <= end)
    {
        int time = 5 * mid;
        if (time + kMint <= 240)
        {
            count = mid;
            kMint += time;
            cout
                << "I am Count " << count << endl;
            start = mid + 1;
        }
        else if (time + kMint > 240)
        {
            end = mid - 1;
        }
        cout << "I Ma Mide : " << mid << endl;
        mid = start + (end - start) / 2;
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    int ans = problemCount(n);
    cout << ans;
    // int remainTime = 240;
    // int noOfProblem;
    // cin >> noOfProblem;
    // int kMinutes;
    // cin >> kMinutes;
    // int solveCount = 0;
    // for (int i = 1; i <= noOfProblem; i++)
    // {
    //     int time = 5 * i;
    //     if (time + kMinutes <= remainTime)
    //     {
    //         kMinutes += time;
    //         solveCount++;
    //     }
    //     else
    //     {
    //         break;
    //     }
    // }
    // cout << solveCount << endl;
    return 0;
}