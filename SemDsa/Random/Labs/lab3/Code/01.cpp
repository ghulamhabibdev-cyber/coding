#include <bits/stdc++.h>
using namespace std;
// class defination
class Node
{
private:
    int data;
    Node *next;

public:
    int getData();
    Node *getNext();
    void setData(int);
    void setNext(Node *);
};
// implementing the class method
// setter
void Node::setData(int data)
{
    this->data = data;
}
void Node::setNext(Node *next)
{
    this->next = next;
}
// getter
int Node::getData()
{
    return this->data;
}
Node *Node::getNext()
{
    return this->next;
}
int main()
{
    cout << "========setter getter method=======\n";
    Node *node1 = new Node();
    node1->setData(12);
    cout << node1->getData() << endl;
    Node *node2 = new Node();
    node2->setData(30);
    node1->setNext(node2);
    cout << "Next Data : " << node1->getNext()->getData();

    return 0;
}
