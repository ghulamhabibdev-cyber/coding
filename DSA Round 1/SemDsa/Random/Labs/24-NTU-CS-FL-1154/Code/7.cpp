#include <iostream>
using namespace std;
int sumOfnNumbers(int n)
{
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=i;
    }
    return ans;
}
int main() {
    int n;
    cout<<"Enter the No \n";
    cin>>n;
    int ans=sumOfnNumbers(n);
    cout<<ans<<endl;

    return 0;
}
