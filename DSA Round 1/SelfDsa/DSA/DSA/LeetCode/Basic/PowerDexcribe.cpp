#include<iostream>
using namespace std;
int PowerNum(int n)
{
    int result=1;
    int power=2;
    for(int i=0;i<=n;i++)
    {
        result=result*power;
        if(result==n)
        {
        cout<<"yes : "<<result<<endl;
        break;
        }
    }
    if(result==n)
    {
        return result;
    }
    return result;
}
int main()
{
    PowerNum(8);
}