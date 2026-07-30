#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
bool isVowel(char ch)
{
    ch = tolower(ch);
    return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='y';
}
char makeCharSmall(char ch)
{
    char newChar = ch;
    if (ch >= 'A' && ch <= 'Z')
    {
        newChar = ch - 'A' + 'a';
    }
    // cout <<ch<<endl;
    return newChar;
;
}
string stringMani(string str)
{
    int n = str.length();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];

        if (!isVowel(ch))
        {
            if (i!=n)
            {
                ans += ".";
            }

            ch = makeCharSmall(ch);
            ans += ch;
        }
    }
    return ans;
}
int main()
{
    string str;
    cin >> str;
    cout << stringMani(str);
    return 0;
}