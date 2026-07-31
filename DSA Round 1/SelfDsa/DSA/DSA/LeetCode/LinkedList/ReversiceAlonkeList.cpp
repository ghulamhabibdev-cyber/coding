#include <bits/stdc++.h>
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
void inserNodeAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void insertNodeAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = tail->next;
}
void insertAtAnyPostion(node *&head, node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        inserNodeAtHead(head, d);
        return;
    }
    node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp == NULL)
    {
        insertNodeAtTail(tail, d);
        return;
    }
    node *nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
int getLengthfoLinkedList(node *&head)
{
    node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
void deleteNodeAtPos(node *&head, int pos)
{

    if (head == NULL)
    {
        return;
    }
    if (pos == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        int cnt = 1;
        node *prev = NULL;
        node *curr = head;

        while (cnt < pos)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
            /* code */
        }
        if (curr == NULL)
        {
            return;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
node *RevserLinkList(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *prev = NULL;
    node *curr = head;
    node *forward = NULL;
    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;

        /* code */
    }
    return prev;
}
// node *revtwoByNew(node *head)
// {
//     node *temp = head;
//     node *curr = head;
//     node *prev = NULL;
//     node *next = NULL;
//     while (curr != NULL)
//     {
//         next = curr->next;

//         curr->next = prev;
//         prev = curr;
//         curr = next;
//         /* code */
//     }
//     return prev;
// }
void printLinkList(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;

        /* code */
    }
    cout << endl;
}

/////
node *revtwoByNew(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *temp = head;
    node *curr = head;
    node *prev = NULL;
    node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        /* code */
    }
    return prev;
}
void insertAtTail(node *&head, node *&tail, node *nod)
{
    if (head == NULL && tail == NULL)
    {
        head = nod;
        tail = nod;
        return;
    }
    tail->next = nod;
    tail = tail->next;
}
// void printLinkList(ListNode *&head)
// {
//     ListNode *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->val << " ";
//         temp = temp->next;

//         /* code */
//     }
//     cout << endl;
// }
node *reverseBetween(node *head, int left, int right)
{
    if (head == NULL || head->next == NULL || left == right)
    {
        return head;
    }
    node *temp = head;
    node *beginHead = NULL;
    node *beginTail = NULL;
    node *endHead = NULL;
    node *endtail = NULL;
    node *next = NULL;
    int cnt = 1;
    while (cnt < left)
    {
        next = temp->next;
        temp->next = NULL;
        insertAtTail(beginHead, beginTail, temp);
        temp = next;
        cnt++;
    }

    while (cnt <= right)
    {
        next = temp->next;
        temp->next = NULL;
        insertAtTail(endHead, endtail, temp);
        temp = next;
        cnt++;
    }

    endHead = revtwoByNew(endHead);
    node *revTemp = endHead;
    while (revTemp->next != NULL)
    {
        revTemp = revTemp->next;
    }

    if (right - left == 1)
    {

        if (temp == NULL)
        {

            if (beginHead == NULL)
            {

                beginHead = endHead;
                printLinkList(beginHead);
                return beginHead;
            }
            else
            {
                beginTail->next = endHead;
                printLinkList(beginHead);
                return beginHead;
            }

            return NULL;
        }
        else
        {

            if (beginHead == NULL)
            {

                revTemp->next = temp;
                printLinkList(endHead);
                return endHead;
            }
            else
            {

                revTemp->next = temp;
                printLinkList(endHead);
                insertAtTail(beginHead, beginTail, endHead);
                printLinkList(beginHead);
                return beginHead;
            }
            return NULL;
        }
        return NULL;
    }
    else
    {
        if (beginHead == NULL)
        {
            cout << "Beginhead ios nulll \n";
            printLinkList(endHead);
            revTemp->next = temp;
            printLinkList(endHead);
            return endHead;
        }
        else
        {

            revTemp->next = temp;
            printLinkList(endHead);
            insertAtTail(beginHead, beginTail, endHead);
            printLinkList(beginHead);
            return beginHead;
        }
        return nullptr;
    }
    // printLinkList(endHead);
    // cout<<"Printing temp \n";
    // printLinkList(temp);
}
int main()
{
    // node *node1 = new node(10);
    //   node *tail = node1;
    // node *head = node1;
    // inserNodeAtHead(head, 20);
    // inserNodeAtHead(head, 30);
    // inserNodeAtHead(head, 40);
    // inserNodeAtHead(head, 50);
    // printLinkList(head);

    // insertNodeAtTail(tail, 30000);
    // insertNodeAtTail(tail, 40000);
    // insertNodeAtTail(tail, 50000);
    // printLinkList(head);
    // insertAtAnyPostion(head, tail, 1, 45000);
    // insertAtAnyPostion(head, tail, 1, 55000);
    // insertAtAnyPostion(head, tail, 3, 666);
    // insertAtAnyPostion(head, tail, 3, 777);
    // printLinkList(head);
    // cout<<endl;
    // cout << "length is : " << getLengthfoLinkedList(head) << endl;
    // // deleteNodeAtPos(head, 1);
    // // deleteNodeAtPos(head, 3);
    // cout << "length is : " << getLengthfoLinkedList(head) << endl;
    // node* get= RevserLinkList(head);
    // cout<<endl;
    // node *get = revtwoByNew(head);
    // printLinkList(get);

    node *node33 = new node(1); // renamed to node3
    node *head = node33;
    node *tail = node33;
    insertNodeAtTail(tail, 2);
    insertNodeAtTail(tail, 6);

    insertNodeAtTail(tail, 3);
    insertNodeAtTail(tail, 4);
    insertNodeAtTail(tail, 5);
    insertNodeAtTail(tail, 10);
    node *twoList = new node(3);
    node *twoHead = twoList;
    node *twoTail = twoList;
    insertNodeAtTail(twoTail, 5);
    reverseBetween(twoHead, 1, 2);
    // cout << " # and 4 \n";
    reverseBetween(head, 3, 4);
    node *node3 = new node(1);
    node *tail3 = node3;

    insertNodeAtTail(tail3, 2);
    insertNodeAtTail(tail3, 3);
    insertNodeAtTail(tail3, 4);
    insertNodeAtTail(tail3, 5);
    reverseBetween(node3, 1, 4);

    return 0;
}
