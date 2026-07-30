#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;
bool isCorrectTranslated(string s, string t)
{
    if (s.length() != t.length())
        return false;

    int n = s.length();
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == t[j])
            j--;
        else
            return false;
    }
    return true;
}

class A
{
};

int main()
{
    string s;
    cin >> s;
    string t;
    cin >> t;
    bool isCorrect = isCorrectTranslated(s, t);
    if (isCorrect)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}