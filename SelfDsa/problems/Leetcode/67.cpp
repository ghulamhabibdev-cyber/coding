#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b)
{
    stack<char> sta;
    stack<char> stb;
    string ans = "";
    for (char ab:a)
    {

        sta.push(ab);
    }
    for (char c:b)
    {

        stb.push(c);
    }
    int carry = 0;
    while (!sta.empty() || !stb.empty() || carry != 0)
    {
        // cout << "Tes tlop";
        int ast=0;
        int bst=0;
        if (!sta.empty())
        {
            ast = sta.top()-'0';
            sta.pop();
        }
        if (!stb.empty())
        {
            bst = stb.top() - '0';
            stb.pop();
        }
       int sum=ast+bst+carry;
       ans += (sum % 2) + '0';
       carry = sum / 2;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    cout << addBinary("11", "1");
    return 0;
}
