#include<iostream>
using namespace std;
int  MySqrt(float num)
{
    for(float i=1;i<num;i++)
    {
        if(num/i==i)
        {
           
            return i;
        }

    }
    return 0;
}
int main()
{
    float num;
    cout<<"Enter a Number :\t";
    cin>>num;
  
    float sqrtNum=MySqrt(num);
    cout<<"squre root: "<<sqrtNum<<endl;
}

