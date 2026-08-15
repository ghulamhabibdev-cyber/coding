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
bool showReorderForMihai(int n)
{
    int evenCont=0;
    int oddCount=0;
    int evenSum=0;
    int oddSum=0;
    for(int i=0;i<n;i++)
    {
        int nBagCandy;
        cin>>nBagCandy;
        if(nBagCandy%2==0)
        {
            evenSum+=nBagCandy;
        }
        else{
            oddSum+=nBagCandy;
        }
    }
    return evenSum>oddSum;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        bool possibleToReorder=showReorderForMihai(n);
        if(possibleToReorder)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}