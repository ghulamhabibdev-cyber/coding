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
int fib1(int n)
{
    if(n<=1)
    {
        return n;
    }
    int ans=fib1(n-2)+fib1(n-1);
    return ans;
}
int getNumber()
{
    int number;
    cout<<"Enter A Number "<<endl;
    cin>>number;
    return number;
}
int main() {
    int number=getNumber();
    int ans=fib1(number);
    cout<<"fib ans for "<<number<<" : "<<ans<<endl;
    
    return 0;
}