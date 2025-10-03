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
void insertAtHead(node *&head, node *&tail, int data)
{
    node *insert = new node(data);
    if (head == NULL & tail == NULL)
    {
        head = insert;
        tail = insert;
        return;
    }
    insert->next = head;
    head = insert;
}
void insertAtTail(node *&head, node *&tail, int data)
{
    node *insert = new node(data);
    if (head == NULL & tail == NULL)
    {
        head = insert;
        tail = insert;
        return;
    }
    tail->next = insert;
    tail = tail->next;
}
void insertANodeAtTail(node *&head, node *&tail, node *nod)
{
    if (head == NULL & tail == NULL)
    {
        head = nod;
        tail = nod;
        return;
    }
    tail->next = nod;
    tail = tail->next;
}
node *reversAList(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *curr = head;
    node *prev = NULL;
    node *next = NULL;
    node *temp = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
void printALinkList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *addTwoNumbers(node *l1, node *l2)
{
    if (l1 == NULL && l2 == NULL)
    {
        return l1;
    }

    l1 = reversAList(l1);
    l2 = reversAList(l2);
    int num1 = 0;
    int num2 = 0;
    int ten = 1;
    // making first no from first list
    node *temp = l1;
    while (temp != NULL)
    {
        num1 = num1 * 10 + temp->data;
        temp = temp->next;
    }
    temp = l2;
    // making second no from second link list
    while (temp != NULL)
    {
        num2 = num2 * 10 + temp->data;
        temp = temp->next;
    }
    cout << "firs num1 : " << num1 << endl;
    cout << "Seconr number : " << num2 << endl;
    int sum = num1 + num2;
    // makig linke list of sum
    node *newList = NULL;
    node *newListTail = NULL;
    while (sum != 0)
    {
        int digit = sum % 10;
        sum = sum / 10;
        insertAtTail(newList, newListTail, digit);
        /* code */
    }
    // newList=reversAList(newList);
    printALinkList(newList);
    return newList;
}
int getLengthOfList(node *head)
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
node *addTwoNumbersTwo(node *l1, node *l2)
{
    int len1 = getLengthOfList(l1);
    int len2 = getLengthOfList(l2);
    int carry = 0;
    node *newListHead = NULL;
    node *newListTail = NULL;
    int newDigit = 0;
    if (len1 > len2)
    {
        int diff = len1 - len2;
        int data = 0;
        int rem = 0;
        node *temp2 = l2;
        node *temp1 = l1;

        while (temp2 != NULL)
        {
            data = temp1->data + temp2->data;
            rem = data % 10;
            newDigit = rem + carry;
            insertAtTail(newListHead, newListTail, newDigit);
            temp1 = temp1->next;
            temp2 = temp2->next;
            carry = data / 10;
        }
        while (temp1 != NULL)
        {
            data = temp1->data + carry;
            rem = data % 10;
            newDigit = rem + carry;
            insertAtTail(newListHead, newListTail, newDigit);
            temp1 = temp1->next;
            carry = data / 10;
        }
        newListHead = reversAList(newListHead);

        printALinkList(newListHead);
        return newListHead;
    }
    else if (len1 == len2)
    {

        int diff = len1 - len2;
        node *temp2 = l2;
        node *temp1 = l1;
        int data = 0;
        int rem;
        while (temp2 != NULL)
        {
            data = temp1->data + temp2->data;
            rem = data % 10;
            newDigit = rem + carry;
            insertAtTail(newListHead, newListTail, newDigit);
            temp1 = temp1->next;
            temp2 = temp2->next;
            carry = data / 10;
        }
        newListHead = reversAList(newListHead);
        printALinkList(newListHead);
        return newListHead;
    }
    else
    {

        int data = 0;
        int rem = 0;
        node *temp2 = l2;
        node *temp1 = l1;

        while (temp1 != NULL)
        {
            data = temp1->data + temp2->data;
            rem = data % 10;
            newDigit = rem + carry;
            insertAtTail(newListHead, newListTail, newDigit);
            temp1 = temp1->next;
            temp2 = temp2->next;
            carry = data / 10;
        }
        while (temp2 != NULL)
        {
            data = temp2->data + carry;
            rem = data % 10;
            newDigit = rem + carry;
            insertAtTail(newListHead, newListTail, newDigit);
            temp2 = temp2->next;
            carry = data / 10;
        }
        newListHead = reversAList(newListHead);

        printALinkList(newListHead);
        return newListHead;
    }
    return NULL;
}
int main()
{
    node *l1 = new node(2);
    node *head = l1;
    node *tail = l1;
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 3);
    // insertAtTail(head, tail, 1);

    // list two
    node *l2 = new node(5);
    node *head2 = l2;
    node *tail2 = l2;
    insertAtTail(head2, tail2, 6);
    insertAtTail(head2, tail2, 4);
    insertAtTail(head2, tail2, 2);
    cout << "l1 \n";
    printALinkList(l1);
    cout << "L2 \n";
    printALinkList(l2);

    // call ing add funcuion;
    node *zero1 = new node(0);
    node *zero2 = new node(0);
    // addTwoNumbers(l1, l2);
    // addTwoNumbers(zero1, zero2);
    addTwoNumbersTwo(l1, l2);
    return 0;
}
