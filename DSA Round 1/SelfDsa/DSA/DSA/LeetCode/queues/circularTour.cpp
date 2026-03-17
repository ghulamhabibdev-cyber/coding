#include <bits/stdc++.h>
using namespace std;
struct petrolPump
{
    int pertrol;
    int distance;
};
int circularTour(petrolPump p[],int n)
{
    int defeicit=0;
    int balance=0;
    int start=0;
    for(int i=0;i<n;i++)
    {
        balance+=p[i].pertrol-p[i].distance;
        if(balance<0)
        {
            defeicit+=balance;
            start=i+1;
            balance=0;
        }
    }
    if(defeicit+balance>=0)
    {
        return start;
    }
    else{
        return -1;
    }

}
int main()
{
    petrolPump s[]={{6,5},{7,6},{4,7},{10,8},{6,6},{5,4}};
    cout<< circularTour(s,6)<<endl;
    return 0;
}