#include <iostream>

using namespace std;

class A {
};
int wrongSubStaction(int num,int k)
{
    for(int i=1;i<=k;i++)
    {
        if(num%10==0)
        {
            num=num/10;
        }
        else{
            num--;
        }
    }
    // cout<<num<<endl;
    return num;
}
int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    int ans=wrongSubStaction(n,k);
    cout<<ans;
    
    return 0;
}