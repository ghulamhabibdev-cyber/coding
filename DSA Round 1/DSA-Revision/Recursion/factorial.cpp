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
long long factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    return n*factorial(n-1);
}
int main() {
    int n;
    cout<<"Enter Number To Find Factorial : "<<endl;
    cin>>n;
    long long facto=factorial(n>=0?n:5);
    cout<<facto<<endl;
    return 0;
}