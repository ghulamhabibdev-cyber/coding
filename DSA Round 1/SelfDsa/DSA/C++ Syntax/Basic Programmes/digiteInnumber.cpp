#include<iostream> 
using namespace std;
void NumberOfDigiteInNumber()
{
    int number;
    int counter=0;
    cout<<"Enter A Number "<<endl;
    cin>>number;
    while (number>0)
    {
        number=number/10;
        counter++;
    }
    cout<<counter<<endl;
    
}
int main()
{
    NumberOfDigiteInNumber();
    return 0;
}