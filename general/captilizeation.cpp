#include <iostream>
using namespace std;

class A
{
};
string captilization(string str)
{
    char ch = str[0];
    if (ch >= 97 && ch <= 'z')
    {
        ch = 'A' + (ch - 'a');
    }
    string ans = "";
    ans += ch;
    int n = str.length();
    for (int i = 1; i < n; i++)
    {
        ans += str[i];
    }
    return ans;
}
int main()
{
    string name;
    cin >> name;
    cout << captilization(name);

    return 0;
}