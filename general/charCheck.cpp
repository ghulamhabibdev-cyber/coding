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

int main()
{
    int n;
    cin >> n;
    string str = "codeforces";
    unordered_map<char, int> mp;
    for (char ch : str)
    {
        mp[ch]++;
    }
    for (int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;
        if (mp.find(ch) != mp.end())
        {
            cout << "Yes"<<endl;
        }
        else
        {
            cout << "No"<<endl;
        }
    }
    return 0;
}