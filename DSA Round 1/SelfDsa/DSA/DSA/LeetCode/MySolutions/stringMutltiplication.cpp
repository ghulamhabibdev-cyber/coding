#include <bits/stdc++.h>
using namespace std;
string reverseString(string str)
{
    string ans = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        ans += str[i];
    }
    return ans;
}
string multiply(string num1, string num2)
{
    int n = num1.size();
    int m = num2.size();
    vector<int> result(n + m, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int mul = (num1[i] - '0') * (num2[j]-'0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    string res = "";
    for (int num : result)
    {
        if (!(res.empty() && num == 0)) // skip leading zeros
            res += (num + '0');
    }

    return res.empty() ? "0" : res;
}
int main()
{
    // string hel = "134";
    // int digit=hel[2]-'0';
    // int zero='0';
    // cout<<"zero : "<<zero<<endl;
    // cout<<"digit : " <<digit<<endl;
    // cout<<"num L; :"<<(3)<<endl;
    // char one=49-48;
    // cout<<"one " <<one<<endl;
    // int sev = 7;
    // char ch = sev + '0';
    // cout << ch << endl;
    // cout << reverseString("123") << endl;
    string ans = multiply("123", "456");
    // string ans = multiply("123456789", "987654321");
    cout << "At last correct ans : " << ans << endl;

    return 0;
}