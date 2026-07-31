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
void reverse(node *&head, node *curr, node *prev)
{
    if (curr == NULL)
    {
        head = prev;
        return;
    }
    node *forward = curr->next;
    reverse(head, forward, curr);
    curr->next = prev;
}
node *revserlinkList(node *head)
{
    node *curr = head;
    node *prev = NULL;
    reverse(head, curr, prev);

    return head;
}
void printLinkList(node *&head)
{
    int cont = 0;

    node *temp = head;
    while (temp != NULL && cont < 30)
    {
        cout << temp->data << " ";
        temp = temp->next;
        cont++;

        /* code */
    }
    cout << endl;
}
node *kRevers(node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    node *next = NULL;
    node *curr = head;
    node *prev = NULL;
    int cont = 0;
    while (curr != NULL && cont < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cont++;
    }
    if (next != NULL)
    {
        head->next = kRevers(next, k);
    }
    return prev;
}
bool CheckCircularList(node *&head)
{
    bool isCircular = false;
    node *temp = head->next;
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
        /* code */
    }
    if (temp == head)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool detectLoop(node *head)
{
    if (head == NULL)
    {
        return false;
    }
    map<node *, bool> visited;
    node *temp = head;
    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return 1;

            break;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return 0;
}
void createCycle(node *&head, int pos)
{
    node *temp = head;
    node *startNode = NULL;
    int count = 1;

    while (temp->next != NULL)
    {
        if (count == pos)
            startNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = startNode; // Creating the cycle
}
bool floydDetectLOOP(node *head)
{
    if (head == NULL)
    {
        return false;
    }
    node *fast = head;
    node *slow = head;
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
    }
    return 0;
}
node *getstartingOfCycle(node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
}
node *floydDetectLOOP2(node *head)
{
    if (head == NULL)
        return NULL;

    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return slow; // return the meeting point inside the cycle
        }
    }

    return NULL; // No cycle
}
node* getStartPointofCycyle(node* head)
{
    if (head == NULL)
        return NULL;

    node* intersection = floydDetectLOOP2(head);

    // If no cycle
    if (intersection == NULL)
        return NULL;

    node* ptr1 = head;
    node* ptr2 = intersection;

    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr1; // This is the start node of the cycle
}
void removeCycle(node * head)
{
    if(head==NULL)
    {
        return;
    }
    node * start=getStartPointofCycyle(head);
    node * temp =start;
    while (temp->next==start)
    {
        temp=temp->next;

        /* code */
    }
    temp->next=NULL;
}
int main()
{
    node *node1 = new node(10);
    node *head = node1;
    inserNodeAtHead(head, 20);
    inserNodeAtHead(head, 30);
    inserNodeAtHead(head, 40);
    inserNodeAtHead(head, 50);
    printLinkList(head);
    node *tail = node1;
    insertNodeAtTail(tail, 30000);
    insertNodeAtTail(tail, 40000);
    insertNodeAtTail(tail, 50000);
    printLinkList(head);
    insertAtAnyPostion(head, tail, 1, 45000);
    insertAtAnyPostion(head, tail, 1, 55000);
    insertAtAnyPostion(head, tail, 3, 666);
    insertAtAnyPostion(head, tail, 3, 777);
    // printLinkList(head);
    cout << "length is : " << getLengthfoLinkedList(head) << endl;
    // deleteNodeAtPos(head, 1);
    // deleteNodeAtPos(head, 3);
    cout << "length is : " << getLengthfoLinkedList(head) << endl;
    // node * get=revserlinkList(head);
    printLinkList(head);
    node *krev = kRevers(head, 4);
    printLinkList(krev);
    cout << endl;
    cout << CheckCircularList(head);
    createCycle(head, 5);
    printLinkList(head);
    cout << endl;
    cout << detectLoop(head);
    // cout<<floydDetectLOOP(head)<<endl;
    // cout<<floydDetectLOOP(krev)<<endl;
    node *pointCye = getStartPointofCycyle(head);
    cout << endl;
    cout << endl;
    // printLinkList(pointCye);
    cout << "start at : " << pointCye->data << endl;
    removeCycle(head);
    cout<<floydDetectLOOP(head)<<endl;
    return 0;
}
