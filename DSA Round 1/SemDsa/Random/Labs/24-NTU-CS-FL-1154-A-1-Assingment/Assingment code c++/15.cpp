// Write a program to dynamically allocate memory for an array of n integers using malloc(),
// input values, and display them.
#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array\n";
    cin>>n;
    int *ptr = (int *)malloc(n * sizeof(int));
    for(int i=0;i<n;i++)
    {
        cout<<"Enter a number \n";
        cin>>ptr[i];
    }
    cout<<"===========Printing value=============\n";
    for(int i=0;i<n;i++)
    {
        cout<<ptr[i]<<" ";
    }
    free(ptr);
    return 0;
}
