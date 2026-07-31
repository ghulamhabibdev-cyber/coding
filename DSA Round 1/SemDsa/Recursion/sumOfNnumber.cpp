#include <iostream>
using namespace std;

class A {
};
int sum(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n+sum(n-1);
}
int main() {
       int n;

    cout << "Enter a Number \n";
    cin >> n;
    cout<<sum(n);
    return 0;
}