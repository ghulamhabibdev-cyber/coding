// #include<bits/std++.h>
#include <iostream>
#include "LinkList.h"
using namespace std;
int main()
{
    // linkList<int>lisy();
    unorederedLinkList<int> listy;
    listy.insertFirst(10);
    listy.insertFirst(11);
    listy.insertFirst(12);
    listy.insertFirst(13);
    listy.insertFirst(14);
    listy.insertLast(32);
    listy.insertLast(32);
    listy.insertLast(32);
    listy.print();
    listy.deleteNode(12);
    listy.print();
    cout<<listy.search(32)<<endl;
}
