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
int findMaxBlankSpace(int n)
{
    int curr = 0;
    int prev = 0;
    for (int i = 0; i < n; i++)
    {
        int bit;
        cin >> bit;
        if (bit == 0)
        {
            curr++;
        }
        else
        {
            if (curr > prev)
            {
                prev = curr;
            }
            curr = 0;
        }
    }
    return max(prev,curr);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int size;
        cin >> size;

        int blankLength = findMaxBlankSpace(size);
        cout << blankLength << endl;
    }

    return 0;
}