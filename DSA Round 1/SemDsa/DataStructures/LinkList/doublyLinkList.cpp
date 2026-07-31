#include <bits/stdc++.h>
#include "doubleyLinkList2.h"
using namespace std;

int main()
{
    doublyLinkList<int> listy;
    listy.inlizeList();
    listy.insert(12);
    listy.insert(1434);
    listy.insert(-14);
    listy.insert(13);
    listy.insert(14);
    listy.print();
    listy.deleteNode(12);
    listy.print();

    return 0;
}
