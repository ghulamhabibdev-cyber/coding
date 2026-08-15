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
char findReplaceChar(vector<vector<char>> arr)
{
    for (int i = 0; i < 3; i++)
    {
        unordered_map<char, bool> mp;
        for (int j = 0; j < 3; j++)
        {
            char ch = arr[i][j];
            if (ch != '?')
            {
                mp[ch] = true;
            }
        }
        char ch = 'A';
        for (int i = 0; i < 3; i++)
        {
            if (mp.find(ch) != mp.end())
            {
                ch++;
            }
            else
            {
                return ch;
            }
                }
    }
    return '0';
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<char>> arr(3, vector<char>(3));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> arr[i][j];
            }
        }
        char ch = findReplaceChar(arr);
        cout << ch << endl;
    }

    return 0;
}