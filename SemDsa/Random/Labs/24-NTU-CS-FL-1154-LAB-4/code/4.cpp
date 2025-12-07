#include<iostream>
#include "circularList.h"
using namespace std;

int main()
{
    circularList cList;
    int n = 7;
    int k = 3;

    for (int i = 1; i <= n; i++)
    {
        cList.insertNode(i);
    }

    cout << "Circular List: ";
    cList.print();

    int survivor = cList.josephus(k);
    cout << "Josephus Survivor = " << survivor << endl;
}
