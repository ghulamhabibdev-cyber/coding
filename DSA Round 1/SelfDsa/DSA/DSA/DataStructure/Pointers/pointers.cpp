#include<iostream>
using namespace std;
int main()
{
    int num=5;
    //& is address operatro 
    cout<<&num<<endl;
    int *ptr=&num;
    cout<<*ptr<<endl;
    num+=3;
    cout<<*ptr<<endl;
    *ptr+=4;
    cout<<num<<endl;
    cout<<"address of ptr : " << &ptr<<endl;
    int *q=ptr;
    cout<<*q<<endl;
    (*q)++;
    cout<<num<<endl;

}