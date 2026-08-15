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
int findLength(string str)
{
    unordered_map<char, int> counter;
    int n = str.length();
    int low = 0;
    int res = 0;
    for (int high = 0; high < n; high++)
    {
        counter[str[high]]++;
        while (counter[str[high]] > 2)
        {
            counter[str[low]]--;
            low++;
        }
        res = max(res, (high - low + 1));
    }
    return res;
}
int main()
{
    string str = "bcbbbcba";
    int ans = findLength(str);
    cout << "ans Length : " << ans << endl;
    return 0;
}