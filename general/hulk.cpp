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
string hulkFeeling(int n)
{
    string hate="I hate ";
    string love="I love ";
    string that="that ";
    string it=" it";
    string ans="";
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            ans+=hate;
            if(i!=n)
            {
                ans+=that;
            }
        }
        else{
            ans+=love;
            if (i != n)
            {
                ans += that;
            }
        }
        
    }
    ans+=it;
    return ans;
}
int main() {
    int n;
    cin>>n;
    string ans=hulkFeeling(n);
    cout<<ans<<endl;
    return 0;
}