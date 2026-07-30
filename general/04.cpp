#include<iostream>
using namespace std;
int noOfStones(int len,int wid,int side)
{
    int recArea=len*wid;
    int ans=0;
    int sq=side*side;
    int count=0;
    while(ans<=recArea)
    {
        ans+=side*side;
        count++;
    }
    count--;
    //  cout<<count<<endl;
    // cout<<ans<<endl;
    ans-=sq;
    if(ans<recArea)
    {
        count*=2;
    }
    // cout<<count<<endl;
    return count;

}
int main()
{
    int n,m,a;
    cin>>n>>m>>a;
    cout<<noOfStones(n,m,a);
}