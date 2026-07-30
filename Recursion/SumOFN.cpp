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
int sum(int n)
{
    if(n==1)
    {
        return n;
    }
    int ans=sum(n-1);
    return ans+n;
}
int main() {
    cout<<sum(4);
    return 0;
}