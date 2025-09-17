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
    bool containe(int d)
    {
        node *temp = this;
        while (temp != NULL)
        {
            if (temp->data == d)
            {
                return true;
            }
            temp = temp->next;
            /* code */
        }
        return false;
    }
    int indexOf(int d)
    {

        node *temp = this;
        int count = 0;
        while (temp != NULL)
        {
            if (temp->data == d)
            {
                return count;
            }

            count++;
            temp = temp->next;
        }
        return -1;
    }
    int lastIndexOf(int d)
    {
        node *temp = new node(0);
        temp = this;
        int index = 0;
        int count = 0;
        while (temp != NULL)
        {
            if (temp->data == d)
            {
                index = count;
            }
            temp = temp->next;
            count++;
        }
        return index;
    }
    node *reverse()
    {
        node *temp = this;
        node *prev = NULL;
        node *curr = this;
        node *nextNode = NULL;
        while (curr != NULL)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};

// printiing linke list
void printLinkList(node *head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    cout << "\n--------------------------------------------------------------------------------------\n";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        /* code */
    }
    cout << endl
         << endl;
    cout << "\n--------------------------------------------------------------------------------------\n";
}
int getLength(node *&head)
{
    if (head == NULL)
    {
        return 0;
    }
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count += 1;
    }
    return count;
}
bool isEmpty(node *head)
{
    if (head != NULL)
    {
        return false;
    }
    return 1;
}
node *peek(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *temp = head;
    return temp;
}
void clear(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        node *next = temp->next;
        delete temp;
        temp = next;
        /* code */
    }
    head = NULL;
}
// bool contains(node * &head,int data)
// {
//     node *temp = head;

// }

// inserting at head each node we add will come at start
void insertAtHead(node *&head, int data)
{
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}
// each node we add go at end of list
void insertAtTail(node *&tail, int data)
{
    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}
// insert at any position at any palce
void insertNodeAtPos(node *&head, node *&tail, int pos, int data)
{
    if (pos == 0)
    {
        insertAtHead(head, data);
    }
    int count = 0;
    node *temp = head;
    while (count < pos)
    {
        temp = temp->next;
        count += 1;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
    }
    // logic to insert at any pos
    node *nodeToinsert = new node(data);
    nodeToinsert->next = temp->next;
    temp->next = nodeToinsert;
}

// revers in kGroups
node *kRevserGroups(node *&head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *nextNode = NULL;
    node *curr = head;
    node *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }
    if (nextNode != NULL)
    {
        head->next = kRevserGroups(nextNode, k);
    }
    return prev;
}
void creteAcyele(node *&head, node *&tail, int pos)
{
    if (head == NULL || pos < 0)
    {
        return;
    }
    int count = 0;
    node *temp = head;
    while (count < pos && temp != NULL)
    {
        temp = temp->next;
        count += 1;
    }
    if (temp != NULL)
    {
        tail->next = temp;
    }
}
bool detectCycle(node *&head)
{
    if (head == NULL)
    {
        return false;
    }
    map<node *, bool> visisted;
    node *temp = head;
    while (temp != NULL)
    {
        if (visisted[temp] == true)
        {
            return 1;
        }
        visisted[temp] = true;
        temp = temp->next;
    }
    return 0;
}
bool floydCyleDetect(node *&head)
{
    node *fast = head;
    node *slow = head;
    node *temp = head;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
        if (slow == fast)
        {
            return 1;
        }
        /* code */
    }
    return 0;
}
pair<node *, int> getStartedNode(node *&head)
{
    node *temp = head;
    pair<node *, int> location;
    map<node *, bool> visisted;
    int count = 0;
    while (temp != NULL)
    {
        if (visisted[temp] == true)
        {
            location.first = temp;
            location.second = count;
            return location;
        }
        visisted[temp] = true;
        temp = temp->next;
        count++;

        /* code */
    }
    pair<node *, int> nuli;
    nuli.first = NULL;
    nuli.second = 0;
    return nuli;
}
void MakeCircular(node *&head, node *&tail)
{
    node *temp = head;
    tail->next = temp;
}
bool isCircular(node *&head)
{
    node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;

        /* code */
    }
    return temp == head;
}
void deleteDuplicates(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *curr = head;
    node *nextNode = NULL;
    while (curr != NULL)
    {
        if ((curr->next != NULL) && (curr->data == curr->next->data))
        {
            node *nex = curr->next->next;
            node *todel = curr->next;
            delete todel;
            curr->next = nex;
        }
        else
        {
            curr = curr->next;
        }
        /* code */
    }
}
int main()
{
    // createing a node this is create at heap not on stack because we allocate it a memory

    node *node1 = new node(10);

    node *head = node1;
    // inserting at head
    // insertAtHead(head, 20);
    // insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtHead(head, 50);

    // inserting at tail
    node *tail = node1;
    // insertAtTail(tail, 60);
    // insertAtTail(tail, 70);
    // insertAtTail(tail, 80);
    insertAtTail(tail, 90);
    insertAtTail(tail, 100);
    insertAtTail(tail, 60);

    // insert a node at any postition
    insertNodeAtPos(head, tail, 0, 60);
    insertNodeAtPos(head, tail, 5, 70);
    insertNodeAtPos(head, tail, 2, 170);

    // getlength of function only work till there is not cycle if cycle then it go to infinite loop
    //  cout<<"Len : " << getLength(head)<<endl;

    // check either a given list is empty or not
    //  node *test=NULL;
    //  cout<<isEmpty(head)<<endl;
    //  cout<<"empty : "<<isEmpty(test)<<endl;

    // implementing Peek fucntion of stack so that we get head or first element
    // cout << peek(head)->data << endl;

    // testing clear function
    // clear(head);

    // testing my contains method
    // cout << "Yes sixty is present : " << head->containe(12003) << endl;
    // cout << "Index of  " << head->indexOf(50) << endl;
    // cout << "Last Index of : " << head->lastIndexOf(50) << endl;
    // printLinkList(head);
    // node *rev = head->reverse();
    // printing reverse link list
    // printLinkList(rev);

    // kGroups ALogorhims
    // node *Krev = kRevserGroups(head, 2);
    // printLinkList(Krev);

    // cycle and circle
    // creteAcyele(head, tail, 0);
    // cout << "Has Cycle : " << detectCycle(head) << endl;
    // cout << "Has Floyd Cycle : " << floydCyleDetect(head) << endl;
    // pair<node *, int> posOfCycle = getStartedNode(head);
    // cout << "Loaction IS : " << posOfCycle.second << endl;
    // cout << "Node Is : " << posOfCycle.first->data << endl;

    // making ciruclar list from single linked list
    // MakeCircular(head,tail);
    // cout << "Is circular : " << isCircular(head) << endl;

    // remove duplicates from sorted link list
    node *sortlist = new node(2);
    node *sortHead = sortlist;
    node *sorttail = sortlist;
    insertAtTail(sorttail, 3);

    insertAtTail(sorttail, 3);
    insertAtTail(sorttail, 3);
    insertAtTail(sorttail, 4);
    insertAtTail(sorttail, 5);
    insertAtTail(sorttail, 6);
    insertAtTail(sorttail, 6);
    insertAtTail(sorttail, 6);
    printLinkList(sortHead);
    deleteDuplicates(sortHead);
    printLinkList(sortHead);

    return 0;
}