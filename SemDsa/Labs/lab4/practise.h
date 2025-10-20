#include <iostream>
#include "node.h"
#ifndef H_DoublyList
#define H_DoublyList
using namespace std;
class doublyLinkList
{
private:
    node *first;
    node *last;
    int count;

public:
    doublyLinkList();
    void InsertNode(int);
    void DeleteNode(int);
    bool isEmpty();
    bool isFull();
    bool Length();
    bool search(int);
    int AtPos(int pos);
    int first();
    int last();
    void destroyList();
    void print();
    void inilizeList();
    void PrintList();
};
#endif

// this is standard form to make header files
