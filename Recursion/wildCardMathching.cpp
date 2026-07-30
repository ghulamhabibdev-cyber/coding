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

bool wildCard(string s, string p, int indexS, int indexP)
{
    if (indexS >= s.length() && indexP >= p.length())
    {
        return true;
    }
    if (s[indexS] == p[indexP])
    {
        bool ans = wildCard(s, p, indexS + 1, indexP + 1);
        if (ans)
        {
            return ans;
        }
        return wildCard(s, p, indexS + 1, indexP);
    }
    else if (p[indexP] == '*')
    {
        bool ans = wildCard(s, p, indexS + 1, indexP + 1);
        if (ans)
        {
            return ans;
        }
        return wildCard(s, p, indexS + 1, indexP);
    }

    else if (p[indexP] == '?')
    {
        return wildCard(s, p, indexS + 1, indexP + 1);
    }
    else
    {
        return false;
    }
}

int main()
{
    string s = "papa";
    string p = "p*a";
    bool ans = wildCard(s, p, 0, 0);
    if (ans)
    {
        cout << "Algo Working" << endl;
    }
    else
    {
        cout << "Debug the code" << endl;
    }

    return 0;
}