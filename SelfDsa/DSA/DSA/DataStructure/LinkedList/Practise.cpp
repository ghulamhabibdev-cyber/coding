#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
    }
};
void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = tail->next;
}
void insertAtPosition(node *&tail, node *&head, int pos, int d)
{
    // inseting at head
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }
    node *temp = head;

    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    if(temp->next==NULL)
    {
        insertAtTail(tail,d);
        return;
    }
    node *nodeToInset = new node(d);
    nodeToInset->next = temp->next;
    temp->next = nodeToInset;
}
void deleteNodeByPos(int pos, node *&head)
{
    if (head == NULL)
        return;

    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *curr = head;
        node *prev = NULL;
        int cnt = 1;

        while (cnt < pos && curr != NULL)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr == NULL)
            return;

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
void printLinkedList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    node *node1 = new node(10);
    node *head = node1;
    insertAtHead(head, 15);
    insertAtHead(head, 20);
    node *tail = node1;
    insertAtTail(tail, 25);
    insertAtPosition(tail, head, 5, 30);
    printLinkedList(head);
    cout << "Head data : " << head->data << endl;
    cout << "Tail data : " << tail->data << endl;
    deleteNodeByPos(2, head);
    printLinkedList(head);
    return 0;
}