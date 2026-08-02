#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int d)
    {
        this->data = d;
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
void insertNode(node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        node *temp = new node(d);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        node *curr = tail;
        bool found = false;
        do
        {
            if (curr->data == element)
            {
                found = true;
                break;
            }
        } while (curr != tail);
        if (!found)
        {
            cout << "Element " << element << " not found!" << endl;
            return;
        }
        node *temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
        // if (curr == tail)
        // {
        //     tail = temp;
        // }
    }
}
void printNode(node *&tail)
{
    node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
}
void deleteNode(node *&tail, int element)
{
    if (tail == NULL)
    {
        cout << "Empty List..........\n";
        return;
    }
    else
    {
        node *prev = tail;
        node *curr = prev->next;
        bool found = false;
        do
        {
            if (curr->data == element)
            {
                found = true;
                break;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
        if (curr == prev)
        {
            tail = NULL;
        }
        else
        {
            prev->next = curr->next;
            if (curr == tail)
            {
                tail = prev;
            }
        }

        curr->next = NULL;
        delete curr;
    }
}
bool CheckCircularList(node *&head)
{
    bool isCircular = false;
    node *temp = head;
    do
    {
        temp = temp->next;
        isCircular = true;
        if (temp == NULL)
        {
            isCircular = false;
            break;
        }
    } while (temp != head);
    if (isCircular)
    {
        return true;
    }
    return false;
}
bool CheckCircularList2(node *&head)
{
    bool isCircular = false;
    node *temp = head->next;
    while (temp!=NULL&&temp!=head)
    {
        temp=temp->next;
        /* code */
    }
    if(temp==head)
    {
        return true;
    }
    else{
        return false;
    }
    
   
}
int main()
{

    node *tail = NULL;
    insertNode(tail, 5, 1);
    insertNode(tail, 1, 4);
    insertNode(tail, 1, 5);
    insertNode(tail, 1, 100);
    insertNode(tail, 1, 5);
    // printNode(tail);
    deleteNode(tail, 1);
    printNode(tail);
    cout<<endl;
    cout<<CheckCircularList(tail)<<endl;
     cout<<CheckCircularList2(tail)<<endl;
    return 0;
}
