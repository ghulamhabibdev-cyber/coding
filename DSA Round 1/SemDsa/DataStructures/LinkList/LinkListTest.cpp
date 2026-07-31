// #include<bits/std++.h>
#include <iostream>
#include "LinkList.h"
using namespace std;
int main()
{
    // linkList<int>lisy();
    // unorederedLinkList<int> listy;
    // listy.insertFirst(10);
    // listy.insertFirst(11);
    // listy.insertFirst(12);
    // listy.insertFirst(13);
    // listy.insertFirst(14);
    // listy.insertLast(32);
    // listy.insertLast(32);
    // listy.insertLast(32);
    // listy.print();
    // listy.deleteNode(12);
    // listy.print();
    // cout<<listy.search(32)<<endl;
    orderedLinkList<int> orList;
    orList.insertFirst(120);
    orList.insertFirst(392010);
    orList.insertFirst(397890);
    orList.insertFirst(345350);
    orList.insertFirst(390);
    orList.insertFirst(3550);
    orList.insertFirst(39024);
    orList.print();
    orList.deleteNode(3550);
    orList.print();
}
