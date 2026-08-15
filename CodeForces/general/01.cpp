#include<iostream>
#include<string>
using namespace std;

int checkLength(string str)
{
    return str.length();
}

string abbrevateString(string str)
{
    int len = checkLength(str);
    if (len <= 10)
    {
        return str;
    }

    string ans = "";
    ans += str[0];

    int noOfLetters = len - 2;
    string ch = to_string(noOfLetters);
    ans += ch;

    ans += str[len - 1];
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string ans;
        cin >> ans;
        ans = abbrevateString(ans);
        cout << ans << endl;
    }
}
