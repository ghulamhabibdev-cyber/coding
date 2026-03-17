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
    if (head == NULL)
    {
        return;
    }
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

        /* code */
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    node *nodeToInsert = new node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
void deleteAtPost(node *&head, int pos)
{

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
        node *prev = NULL;
        node *cur = head;
        int cnt = 1;
        while (cnt < pos && cur != NULL)
        {
            prev = cur;
            cur = cur->next;
            cnt++;
            /* code */
        }
        if (cur == NULL)
        {
            return;
        }
        prev->next = cur->next;
        cur->next = NULL;
        delete cur;
    }
}
void printLinkedList(node *&head)
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
int getLin(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
node *tailNode(node *&head)
{

    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *tailNode = temp->next;
    temp->next = NULL;
    return tailNode;
}
bool isPresent(node *head, int target)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == target)
        {
            return true;
            break;
        }
        temp = temp->next;
    }
    return false;
}
node *newList(node *head, int target)
{
    //
    if (isPresent(head, target))
    {
        if (head->data == target)
        {

            // head->next = NULL;
            return head;
        }
        int cnt = 0;
        node *temp = head;
        node *newlist = new node(-1);
        node *tail = newlist;
        while (temp->data != target)
        {
            insertAtTail(tail, temp->data);
            temp = temp->next;
            cnt++;
        }
        newlist = newlist->next;
        // insertAtTail(tail, temp->data);
        return newlist;
    }
    else
    {
        return NULL;
    }
}
// make a list after target
node *solve(node *head, int target)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (isPresent(head, target))
    {
        if (head->next == NULL)
        {
            return head;
        }
        cout << " Print ting list : \n";
        printLinkedList(head);
        node *beforeLsit = newList(head, target);
        cout << " Printing new List get by fucntion  : " << endl;
        printLinkedList(beforeLsit);
        node *temp = head;
        // find insertion
        node *insertionPoint;
        int count = 0;
        // bool found=;
        while (temp != NULL)
        {
            if (temp->data >= target)
            {
                insertionPoint = temp;
                break;
            }
            count++;
            temp = temp->next;
        }
        //  temp = temp->next;
        // temp = temp->next;
        cout << "Insertion point : " << insertionPoint->data << endl;
        // insertionPoint->next=NULL;
        // printLinkedList(insertionPoint);
        node *targetnode = new node(insertionPoint->data);
        // insertionPoint->next=NULL;
        temp = head;
        // while(temp->data!=target)
        // cout << "temp : " << temp->data << endl;
        temp = head;
        // count = 0;
        while (temp->data != target)
        {
            temp = temp->next;
        }

        cout << "temp : " << temp->data << endl;
        node *getTarget = new node(temp->data);
        node *newlistNode = new node(-1);
        node *taileListNode = newlistNode;
        node *next = NULL;
        node *biglist = new node(-1);
        node *bigtail = biglist;
        cout << "beofre cal  Print ting list : \n";
        printLinkedList(temp);
        while (temp != NULL && temp->next != NULL)
        {
            if (temp->next->data < target)
            {
                // cout<<"Inserting temp data in to new lsit : "<<temp->data << endl;
                insertAtTail(taileListNode, temp->next->data);
            }
            else if (temp->next->data > target)
            {
                insertAtTail(bigtail, temp->next->data);
            }
            temp = temp->next;
        }
        cout << " Count : " << count << endl;
        if (count == 0)
        {
            node *tempy = newlistNode;

            while (tempy->next != NULL)
            {
                tempy = tempy->next;
                /* code */
            }
            biglist = biglist->next;
            tempy->next = targetnode;
            tempy = newlistNode;
            while (tempy->next != NULL)
            {
                tempy = tempy->next;
            }
            tempy->next = biglist;
        }
        else
        {

            temp = beforeLsit;
            node *curr = NULL;
            while (temp != NULL)
            {
                if (temp->next->data == insertionPoint->data)
                {
                    curr = temp->next;
                    newlistNode = newlistNode->next;
                    temp->next = newlistNode;
                    break;
                }
                temp = temp->next;
            }
            temp = beforeLsit;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = curr;
            cout << "Printing modified list :  " << endl;
            biglist = biglist->next;
            temp = beforeLsit;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            getTarget->next = biglist;
            temp->next = getTarget;

            cout << "Print new list of beforeList : " << endl;
            printLinkedList(beforeLsit);

            // printLinkedList(targetnode);
        }

        cout << "Samll lsit : \n";
        printLinkedList(newlistNode->next);
        // cout << "big list : \n";
        // printLinkedList(biglist->next);
        return NULL;
    }
    else
    {
        return nullptr;
    }
}
void insertAtTail(node *&head, node *&tail, node *nd)
{
    if (tail == NULL && head == nullptr)
    {
        head = nd;
        tail = nd;
        return;
    }
    tail->next = nd;
    tail = tail->next;
}
node *partitionList(node *head, int x)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    if (isPresent(head, x))
    {
        node *remainList = NULL;
        node *prevHead = NULL;
        node *prevTail = NULL;
        node *next = NULL;
        node *curr = NULL;
        node *small = NULL;
        node *insertion = NULL;

        // fint insertion point
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data >= x)
            {
                insertion = temp;
                break;
            }
            else
            {
                next = temp->next;
                temp->next = NULL;
                insertAtTail(prevHead, prevTail, temp);
                printLinkedList(prevHead);
                temp = next;
            }
        }
        temp = insertion;
        next = NULL;
        node *bigHead = NULL;
        node *bigtail = NULL;
        node *bignext = NULL;
        curr = NULL;
        node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->data < x)
            {
                next = temp->next;
                temp->next = nullptr;
                insertAtTail(prevHead, prevTail, temp);
                printLinkedList(prevHead);
                temp = next;
            }
            else
            {
                cout << "I am insertion \n";
                bignext = temp->next;
                temp->next = NULL;
                insertAtTail(bigHead, bigtail, temp);

                temp = bignext;
            }

            /* code */
        }

        printLinkedList(bigHead);
        cout << "Before node : " << endl;
        insertAtTail(prevHead, prevTail, bigHead);
        printLinkedList(prevHead);
        return prevHead;
    }
    return NULL;
}
node *reversetwoByNew(node *head)
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
void merge(node *&head, node *&tail, node *nod)
{

    if (head == NULL && tail == NULL)
    {
        head = nod;
        tail = nod;
        // printLinkedList(tail);
        return;
    }
    node *temp = tail;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp;
    temp->next = nod;
}
node *swapPairs(node *head)
{
    // cout << "Enter : \n";
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *prev = head;
    node *curr = head->next;
    node *nextNode = NULL;
    node *newListHead = NULL;
    node *newListTail = NULL;
    node *nully = NULL;
    int count = 0;

    while ((prev != NULL && prev->next != NULL))
    {
        nextNode = curr->next;
        curr->next = prev;
        prev->next = NULL;
        merge(newListHead, newListTail, curr);
        // printLinkedList(curr);
        prev = nextNode;
        curr=nextNode->next;    
    }
    if (prev != NULL)
    {
        newListTail->next->next->next= prev;
    }
    
    return newListHead;
}
int main()
{
    cout << "=================================== Main ================================\n";

    node *list = new node(1);
    node *head = list;
    node *tail = list;
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    insertAtTail(tail, 7);
    insertAtTail(tail, 8);
    insertAtTail(tail, 9);
    insertAtTail(tail, 10);
    insertAtTail(tail, 11);
    insertAtTail(tail, 12);
    insertAtTail(tail, 13);
    node *res = swapPairs(head);
    printLinkedList(res);
    return 0;
}