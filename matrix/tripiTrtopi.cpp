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
string abrevate(string str, string str2, string str3)
{
    string ans = "";
    ans += str[0];
    ans += str2[0];
    ans += str3[0];
    return ans;
}
int main()

{
    int t;
    cin >> t;
    while (t--)
    {
        string str1, str2, str3;
        cin >> str1 >> str2 >> str3;
        string ans = abrevate(str1, str2, str3);
        cout << ans << endl;
    }
    return 0;
}