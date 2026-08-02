#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <random>
#include <list>
#include "linkList.h"
using namespace std;

class A
{
};

int main()
{
    LinkList *list = new LinkList();
    cout << "length is :  " << list->length() << endl;
    int sum = 0;
    // for (int i = 0; i < 10; i++)
    // {
    //     sum += i;
    //     list->addHead(sum);
    // }
    // sum = 0;
    // for (int i = 0; i < 4; i++)
    // {
    //     sum += (i * 3 + 1);
    //     list-> addTail(sum);
    // }
    // srand(time(nullptr));
    // int n = rand() % 100 + 1;
    // cout << number << endl;
    for (int i = 0; i < 5 ;i++)
    {
        
        Node *node = new Node(i+(i%3)+(i%2)+(i%4));
        list->addHead(node);
        // cout << number << endl;
    }
    for (int i = 0; i < 5; i++)
    {

        Node *node = new Node(i + (i % 3) + (i % 2) + (i % 4));
        list->addTail(node);
    }
    list->printLinkList();
    list->printHead();
    list->printTail();
    // Node *node = new Node(23);/
    // list->printLinkList();
    cout << endl;
    cout << "Current Size : " << list->length() << endl;
    for (int i = 0; i < 3; i++)
    {
        list->deleteHead();
    }

    cout << "Size After Delete : " << list->length() << endl;

    return 0;
}