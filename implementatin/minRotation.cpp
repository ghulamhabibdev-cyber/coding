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
int minRotaion(string str)
{
    unordered_map<char, int> mp;
    char ch = 'a';
    int n = str.length();
    int prev = 1;
    int clockWise = 0;
    int antiClockWise = 0;
    int ans = 0;
    for (int i = 1; i <= 26; i++)
    {
        mp[ch] = i;
        ch++;
    }
    for (int i = 0; i < n; i++)
    {
        char chy = str[i];
        int curr = mp[chy];

        if (prev < curr)
        {
            // cout << "clock I am in prev<curr" << endl;
            clockWise = curr - prev;
        }
        else if (prev == curr)
        {
            clockWise = 0;
        }
        else
        {
            // cout << "clock I am in prev>curr" << endl;

            clockWise = 26 - prev + curr;
        }
        if (prev > curr)
        {
            // cout << "ansclock I am in prev>curr" << endl;

            antiClockWise = prev - curr;
        }
        else if (curr == prev)
        {
            antiClockWise = 0;
        }
        else
        {
            // cout << "anti clock I am in prev<curr" << endl;

            antiClockWise = prev + 26 - curr;
        }
        prev = curr;
        ans += min(clockWise, antiClockWise);
    }
    return ans;
}
int main()
{
    string str;
    cin >> str;
    int ans = minRotaion(str);
    cout << ans << endl;
    return 0;
}