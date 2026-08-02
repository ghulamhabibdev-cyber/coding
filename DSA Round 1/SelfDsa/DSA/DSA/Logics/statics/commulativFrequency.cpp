#include<iostream>
using namespace std;
void CommulativeFrequency()
{
    int dataSet[5]={3,4,5,6,7};
    int commulativeFre[5];
    for(int i=0;i<5;i++)
    {
        if(i==0)
        {
            commulativeFre[i]=dataSet[i];

        }
        else{
            commulativeFre[i]=commulativeFre[i-1]+dataSet[i];
        }


    }
    for(int i=0;i<5;i++)
    {
        cout<<"\t"<<commulativeFre[i];

    }
}
int main(){
    CommulativeFrequency();
}