#include <bits/stdc++.h>
#include "ArrayBaseList.h"
using namespace std;
class a
{
};

int main()
{
    int size;
    cout<<"Enter Size of List\n";
    cin>>size;
    arrayListType<int> list(size);
    for(int i=0;i<size;i++)
    {
        int number;
        cout<<"enter a number \n";
        cin>>number;
        list.insertAt(i,number);
    }
    list.print();
    list.removeAt(3);
    list.print();

    return 0;
}
