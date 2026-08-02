#include<iostream>
using namespace std;
void SumOfNumberToN()
{
    int n;
    cout<<"Enter Number : "<<endl;
    cin>>n;
    int sum=0;
    sum+=n;
    while(n!=0)
    {
        sum+=n-1;
        n--;
    }
    cout<<sum<<endl;
    int number;
    int numberSum=0;
    cout<<"Enter Number : "<<endl;
    cin>>number;
    for(int i=1;i<=number;i++)
    {
        numberSum+=i;
        
    }
    cout<<numberSum<<endl;
    int interger;
    int sumTillInteger=0;
    cout<<"Enter Number  "<<endl;
    cin>>interger;
    sumTillInteger+=interger;
    do{
        sumTillInteger+=interger-1;
        interger--;
    }while(interger!=0);  
    cout<<"Sum : "<<sumTillInteger<<endl;
    
}
int main()
{
    SumOfNumberToN();
    return 0;
}