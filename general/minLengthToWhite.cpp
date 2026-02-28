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

class A {
};
int minLengthToWhite(string str)
{
    int start=0;
    int end=str.length()-1;
    while(start<=end)
    {
        if(str[start]=='W')
        {
            start++;
        }
        if(str[end]=='W')
        {
            end--;
        }
        if(str[start]=='B'&&str[end]=='B')
        {
            return end-start+1;
        }
    }
    return 0;
}
int main() {
    int testCases;
    cin>>testCases;
    while(testCases--)
    {
        string str;
        int n;
        cin>>n;
        cin>>str;
        int ans=minLengthToWhite(str);
        cout<<ans<<endl;
    }
    return 0;
}