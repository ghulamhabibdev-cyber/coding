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
int maxAlphaBetSize(string str, int n)
{
    int size = 0;
    for (int i = 0; i < n; i++)
    {
        char ch = str[i];
        if (ch - 'a' >= size)
        {
            size = ch - 'a';
        }
    }
    return (size += 1);
}
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        int minSize=maxAlphaBetSize(str,n);
        cout<<minSize<<endl;
    }
    return 0;
}