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
void prepareCount(unordered_map<char, int> &mp, string problem)
{
    for (char ch : problem)
    {
        mp[ch]++;
    }
}
int minNumberOfProblemGeneration(string problem, int round)
{
    unordered_map<char, int> mp;
    prepareCount(mp, problem);
    int count = 0;
    for (char ch = 'A'; ch <= 'G'; ch++)
    {
        if (mp.find(ch) != mp.end())
        {
            if (mp[ch] < round)
            {
                // cout << mp[ch] << endl;
                count += round - mp[ch];
                // cout << "I am Count : " << count << endl;
            }
        }
        else
        {
            count += round;
            // cout << "Count Not found : " << ch << count << endl;
        }
    }
    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, round;
        cin >> n >> round;
        string problemList;
        cin >> problemList;
        int minProblem = minNumberOfProblemGeneration(problemList, round);
        cout << minProblem << endl;
    }
    return 0;
}