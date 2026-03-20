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
int minSteptoErase(string str, int n, int k)
{
    int s = 0;
    int e = n - 1;
    int count = 0;
    while (s <= e)
    {
        if (str[s] == 'W' && str[e] == 'W')
        {
            s++;
            e--;
        }
        else if (str[s] == 'B')
        {
            for (int i = 0; i < k; i++)
            {
                s++;
            }
            count++;
        }
        else if (str[e] == 'B')
        {
            for (int i = 0; i < k; i++)
            {
                e--;
            }
            count++;
        }
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t != 0)
    {
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        int minStep = minSteptoErase(str, n, k);
        cout << minStep << endl;
        t -= 1;
    }

    return 0;
}