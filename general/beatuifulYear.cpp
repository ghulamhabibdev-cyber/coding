#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A {
};
bool hasDistinctDigist(int n)
{
    bool arr[100]={false};
    while(n>0)
    {
        int dig=n%10;
        if(arr[dig])
        {
            return false;
        }
         n/=10;
        arr[dig]=true;
    }
    return true;
   

}
int findBeautifullYear(int n)
{
    for(int i=n+1;;i++)
    {
        if(hasDistinctDigist(i))
        {
            return i;
        }
    }
}

int main() {
    int n;
    cin>>n;
    int ans=findBeautifullYear(n);
    cout<<ans<<endl;
    return 0;
}