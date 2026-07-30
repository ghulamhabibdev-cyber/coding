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
string getPularNoun(string str)
{

    int n = str.length();
    string ans = str.substr(0, n - 2);
    return ans + 'i';
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string noun;
        cin >> noun;
        string popNoun = getPularNoun(noun);
        cout << popNoun << endl;
    }
    return 0;
}