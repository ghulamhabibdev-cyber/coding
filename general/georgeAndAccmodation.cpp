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
int totalRoomCount(int n)
{
    int roomCount=0;
    for(int i=1;i<=n;i++)
    {
        int pLiving;
        int qCap;
        cin>>pLiving;
        cin>>qCap;
        if(pLiving==qCap)
        {
            continue;
        }
        if(qCap-pLiving>=2)
        {
            roomCount++;
        }
    }
    return roomCount;
}
int main() {
    int n;
    cin>>n;
    int ans=totalRoomCount(n);
    cout<<ans<<endl;
    
    return 0;
}