#include<iostream>
#include "12.h"
using namespace std;

int main()
{
    linkyQueue qt;
    if(qt.isEmpty())
    {
        cout<<"Empty Queue \n";
    }
    else{
        cout<<"Not Empty \n";
    }

    qt.enqueue(10);
    qt.enqueue(20);
    qt.enqueue(30);
    qt.enqueue(40);
    qt.enqueue(50);
    qt.enqueue(60);
    if (qt.isEmpty())
    {
        cout << "Empty Queue \n";
    }
    else
    {
        cout << "Not Empty \n";
    }
    if(qt.isFull())
    {
        cout << "queue is FUll  \n";
    }
    else
    {
        cout << "Not Full \n";
    }
    qt.enqueue(70);
    qt.print();
   

    return 0;
}
