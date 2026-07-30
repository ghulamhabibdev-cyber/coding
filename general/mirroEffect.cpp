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
string mirrorEffect(string str)
{
    int start = 0;
    int end = str.length() - 1;
    while (start <= end)
    {
        
        swap(str[start], str[end]);
        start++;
        end--;
    }
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        if(str[i]=='p')
        {
            str[i]='q';
        }else if(str[i]=='q')
        {
            str[i]='p';
        }
    }
    return str;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        str = mirrorEffect(str);
        cout << str << endl;
    }

    return 0;
}