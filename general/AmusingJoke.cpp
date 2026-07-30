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
bool isToRecoverName(string host, string guest, string letterPile)
{
    // metaData
    unordered_map<char, int> mp;
    unordered_map<char, int> pileMp;
    int pLen = letterPile.length();
    int i = 0;
    int j = 0;
    int hLen = host.length();
    int gLen = guest.length();
    // code
    while (i != hLen)
    {
        mp[host[i++]]++;
    }
    while (j != gLen)
    {
        mp[guest[j++]]++;
    }
    i = 0;
    while (i != pLen)
    {
        pileMp[letterPile[i++]]++;
    }
    return mp==pileMp;
}
int main()
{
    string hostName, guestName, letterPile;
    cin >> hostName >> guestName >> letterPile;
    bool isPossible = isToRecoverName(hostName, guestName, letterPile);
    if (isPossible)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}