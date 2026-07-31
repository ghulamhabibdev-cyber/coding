#include <bits/stdc++.h>
using namespace std;
void smallStr(string &str)
{
    int i = 0;
    int j = str.length();
    while (i < j)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
        i++;
    }
}
string alphabetStr(string &str)
{
    smallStr(str);
    string newStr = "";
    int i = 0;
    int j = str.length();
    while (i < j)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            newStr += str[i];
        }
        i++;
        // else
        // {
        //     i++;
        // }
    }
    return newStr;
}
bool validPalindrome(string str)
{
    // smallStr(str);
    // str=alphabetStr(str);
    int j = str.length() - 1;
    int i = 0;
    while (i < j)
    {
        if (str[i]!= str[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}
int main()
{
    cout << char(65) << endl;
    cout << char(90) << endl;
    cout << char(97) << endl;
    cout << char(122) << endl;
    cout << int('I') << endl;
    cout << char(105) << endl;
    cout<<char(0)<<endl;
    string name = "P";
    smallStr(name);
    name = alphabetStr(name);
    cout << name << endl;
    cout << validPalindrome(name);
    return 0;
}