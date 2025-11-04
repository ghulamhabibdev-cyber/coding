#include <iostream>
using namespace std;
long factorial(int n)
{
    if(n==1||n==0)
    {
        return 1;
    }
    long ans=n*factorial(n-1);
    return ans;
}
int main() {
    int n;
    cout<<"Ente the No \n";
    cin>>n;
    long ans=factorial(n);
    cout<<ans<<endl;

    return 0;
}
