#include <iostream>
#include "2doublyList.h"
#include "circularList.h"
using namespace std;
int main()
{
        doublyLinkList list;
        list.insertNode(40);
        list.insertNode(30);
        list.insertNode(40);
        list.insertNode(50);
        list.insertNode(60);
        bool found = list.search(50);
        list.print();

        if (found)
        {
            cout << "Prestni list\n";
        }
        list.deleteNode(480);
        list.print();
    circularList cList;
    cList.insertNode(30);
    cList.insertNode(40);
    cList.insertNode(50);
    cList.insertNode(60);
    cList.print();
    cList.print();

    return 0;
}
