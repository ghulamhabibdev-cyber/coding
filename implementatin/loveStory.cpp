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
    string comp = "codeforces";
    string str;
    int n;
    cin >> n;

    for (int j = 0; j < n; j++)
    {
        int count = 0;
        cin >> str;
        for (int i = 0; i < comp.length(); i++)
        {
            if (comp[i] != str[i])
            {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}