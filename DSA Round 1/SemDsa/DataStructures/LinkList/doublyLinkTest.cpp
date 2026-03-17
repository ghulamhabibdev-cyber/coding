#include<bits/stdc++.h>
#include "doublyLinkList.h"
using namespace std;
class  a
{

};

int main()
{
    doublyLinkList<int>*list=new doublyLinkList<int>();
    list->insert(10);
    list->insert(12);
    list->insert(13);
    list->insert(14);
    list->insert(40);
    list->insert(1);
    list->insert(102);
    
    list->print();
    bool work=list->search(10);
    if(work)
    {
        cout<<"test Pass \n";
    }
    cout<<"Hello World\n";
    list->makeCircular();
    list->makeStraight();
    list->insert(130);
    list->insert(114);
    list->insert(140);
    list->makeStraight();
    list->print();
    return 0;
}
