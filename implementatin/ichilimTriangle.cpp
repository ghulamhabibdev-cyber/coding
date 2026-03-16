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
vector<int> findDigit(int a,int b,int c,int d)
{
    vector<int>ans;
    ans.push_back(b);
    if(b-c==0)
    {
        ans.push_back(b);
    }else{
        ans.push_back(b+1);
    }
    ans.push_back(c);
    return ans;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int a,b, c,d ;
        cin>>a>>b>>c>>d;
        vector<int>ans=findDigit(a,b,c,d);
        for(int num:ans)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}