#include<iostream>
#include<vector>
using namespace std;
bool isPrime(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int countPrime(int n)
{
    vector<int> prime(n+1,true);
    prime[0]=prime[1]=false;
    int count=0;
    for(int i=2;i<n;i++)
    {
        if(isPrime(i))
        {
            prime[i]=true;
            count++;
            for(int j=i*2;j<n;j=j+i)
            {
                prime[j]=0;
            }
        }
    }
    return count;
}
int main()
{
    cout<<isPrime(7)<<endl;
    cout<<countPrime(50);
    return 0;
}