#include <iostream>
#include "12.h"
using namespace std;

int main()
{
    linkyQueue qt;
    qt.enqueue(10);
    qt.enqueue(20);
    qt.enqueue(30);
    qt.enqueue(40);
    qt.enqueue(50);
    qt.enqueue(60);
    qt.enqueue(70);
    qt.print();
    cout << "Dequing the elements \n";
    qt.dequeue();
    qt.dequeue();
    qt.print();

    return 0;
}
