#include <iostream>
using namespace std;
void changeValue(int *ptr)
{
    cout << "I have change the value of the user enter data\n";
    *ptr = 100;
}
void passByReference(int &x)
{
    cout << "I have change the value of the user enter data\n";
    x=200;
}
void passByValue(int x)
{
    x=434;
}
int main()
{
    // int arr[4]={43,343,343};
    // int * p=arr;
    // for(int i=0;i<4;i++)
    // {
    //     cout<<(*p)<<" ";
    //     p++;
    // }

    int x;
    cout << "Enter a value  :  \n";
    cin >> x;
    int *ptr = &x;
    changeValue(ptr);
    cout << x << endl;
    // how to pass by value and pass by refrence work
    passByValue(x);
    cout << x << endl;
    passByReference(x);
    cout << x << endl;
    return 0;
}
