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

int main()
{
    string borzeCode;
    cin >> borzeCode;
    int n = borzeCode.length();
    string ans = "";
    int i = 0;
    int j = 1;
    while (j <n)
    {
        if (borzeCode[i] == '.')
        {
            ans += '0';
            i = j;
            j++;
        }
        else if (borzeCode[i] == '-' && borzeCode[j] == '.')
        {
            ans += '1';
            i = j + 1;
            j += 2;
        }
        else if (borzeCode[i] == '-' && borzeCode[j] == '-')
        {
            ans += '2';
            i = j + 1;
            j += 2;
        }
        
    }
    if (borzeCode[i] == '.' && i < n)
    {
        ans += '0';
    }
    cout << ans << endl;
    return 0;
}