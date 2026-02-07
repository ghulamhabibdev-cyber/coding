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
bool isCorrectSpell(string str)
{
    if (str.length() != 5)
        return false;

    sort(str.begin(), str.end());
    return str == "Timru";
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int len;
        string str;
        cin >> len >> str;

        bool isCorrect = isCorrectSpell(str);
        if (isCorrect)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO"<<endl;
        }
    }

    return 0;
}