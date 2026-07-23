#include <iostream>
using namespace std;

class A
{
};
bool helper(string s, int st, int end)
{
    if (st >= end)
    {
        return true;
    }
    if (s[st] != s[end])
    {
        return false;
    }
    bool ans = helper(s, st + 1, end - 1);
    return ans;
}
bool isPalindrome(string s)
{
    int n = s.length() - 1;
    return helper(s, 0, n);
}
int main()
{
    string str = "malayalaz";
    if (isPalindrome(str))
    {
        cout << str << " is palindrome " << endl;
    }
    else
    {
        cout << str << " is Not palindrom " << endl;
    }
    return 0;
}