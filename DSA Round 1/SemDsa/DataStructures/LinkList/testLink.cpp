// #include<bits/stdc++.h>
#include <iostream>
#include "ImplementGenericLinkList.h"
// #include "UnoredLinkList.h"
#include "orderedLinkListImp.h"
using namespace std;
int main()
{
    
    // UnorderedLinkList<int> *list = new UnorderedLinkList<int>();
    // list->insertFirst(10);
    // list->insertFirst(12);
    // list->insertFirst(13);
    // list->insertFirst(14);
    // list->print();
    // // list->destroyList();
    // // list->print();
    // bool found=list->search(10);
    // if(found)
    // {
    //     cout<<"Work\n";
    // }
    // list->destroyList();
    // list->print();
    // list->deleteNode(10);
    // list->deleteNode(12);
    // list->print();
    // cout<<"Is Empty : "<<list->isEmpty();
    orderedLinkList<int>*listy=new orderedLinkList<int>();
    listy->insertFirst(10);
    listy->insert(100);
    listy->insert(132);
    listy->insert(23);
    listy->insert(134);
    listy->print();
    
    

    return 0;
}
