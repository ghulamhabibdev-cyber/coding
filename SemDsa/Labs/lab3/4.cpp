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
// implementing the class Node method
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
class List
{
private:
    Node *currentLocation;

public:
    List();
    void Print();
    void Insert(int);
    void Delete(int);
    void addbetween(int);
    // a
    int findMin();
    // b
    int findMax();
    // c
    bool search(int data);
    // d
    void insertAtLocation(int data, int loc);
    // e
    void swap(int loc1, int loc2);
};
void List::swap(int loc1,int loc2)
{
   if(loc1<0 ||loc2<0)
   {
    cout<<"Negtive Index \n";
    return ;
   }
   else{
        
   }
}
void List::insertAtLocation(int data,int loc)
{
    int pos=0;
    if(loc<0)
    {
        return;
    }
    Node *temp = new Node();
    temp->setData(data);
    if(loc==1||loc==0)
    {

        if(currentLocation==NULL)
        {
            currentLocation=temp;
        }
        else{
            temp->setNext(currentLocation);
            currentLocation=temp;
        }

    }
    else{
        Node * curr=currentLocation;
        Node *prev;
        while(pos!=loc)
        {
            prev=curr;
            curr=curr->getNext();
            pos++;
        }
        prev->setNext(temp);
        temp->setNext(curr);
    }

}
bool List::search(int data)
{
    bool found;
    if (this->currentLocation == NULL)
    {
        found = false;
    }
    else
    {
        Node *curr = currentLocation;
        while (curr != NULL && !found)
        {
            if (curr->getData() == data)
            {
                found = true;
            }
            else
            {
                curr = curr->getNext();
            }
        }
    }
    if (found)
    {
        return found;
    }
    return found;
}
int List::findMin()
{
    int maxi = INT_MAX;

    if (this->currentLocation == NULL)
    {
        maxi = -1;
    }
    if (currentLocation->getNext() == NULL)
    {
        maxi = currentLocation->getData();
    }
    else
    {
        Node *curr = currentLocation;
        while (curr != NULL)
        {
            if (curr->getData() < maxi)
            {
                maxi = curr->getData();
            }
            else
            {
                curr = curr->getNext();
            }
        }
    }
    return maxi;
}
int List::findMax()
{
    int maxi = INT_MIN;

    if (this->currentLocation == NULL)
    {
        maxi = -1;
    }
    if (currentLocation->getNext() == NULL)
    {
        maxi = currentLocation->getData();
    }
    else
    {
        Node *curr = currentLocation;
        while (curr != NULL)
        {
            if (curr->getData() > maxi)
            {
                maxi = curr->getData();
            }
            else
            {
                curr = curr->getNext();
            }
        }
    }
    return maxi;
}
List::List()
{
    this->currentLocation = NULL;
}
void List::addbetween(int data)
{
    Node *temp = new Node();
    temp->setData(data);
    if (currentLocation == NULL)
    {
        currentLocation = temp;
        return;
    }
    if (currentLocation->getNext() == NULL)
    {
        currentLocation->setNext(temp);
    }
    else
    {
        Node *nexy = currentLocation->getNext();
        temp->setNext(nexy);
        currentLocation->setNext(temp);
    }
}
void List::Insert(int data)
{
    Node *temp = new Node();
    temp->setData(data);

    if (this->currentLocation == NULL)
    {
        currentLocation = temp;
    }
    else
    {
        temp->setNext(this->currentLocation);
        currentLocation = temp;
    }
}
void List::Print()
{
    Node *temp = currentLocation;
    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}
void List::Delete(int data)
{
    Node *curr = currentLocation;
    Node *prev;
    bool found = false;
    if (currentLocation->getData() == data)
    {
        Node *temp = currentLocation;
        currentLocation = currentLocation->getNext();
        return;
    }
    else
    {
        while (curr != NULL && !found)
        {
            if (curr->getData() == data)
            {
                found = true;
            }
            else
            {
                prev = curr;
                curr = curr->getNext();
            }
        }
        if (curr == NULL)
        {
            cout << "Not Presnt In List \n";
        }
        else
        {
            if (found)
            {
                prev->setNext(curr->getNext());
                delete curr;
            }
        }
    }
}
class orderList
{
private:
    Node *first;
    Node *last;

public:
    orderList();
    void insert(int data);
    void Delete(int data);
    void print();
    int findMax();
    int findMin();
    bool searching(int data);
};
// implementin the orderLinkList
orderList::orderList()
{
    this->first = NULL;
    this->last = NULL;
}
void orderList::Delete(int data)
{
    Node *prev;
    Node *curr;
    bool found = false;
    if (first == NULL)
    {
        return;
    }
    else
    {
        if (first->getData() == data)
        {
            Node *temp = first;
            first = first->getNext();
            delete temp;
            if (first == NULL)
            {
                last = NULL;
            }
        }
        else
        {
            curr = first;
            while (curr != NULL && !found)
            {
                if (curr->getData() >= data)
                {
                    found = true;
                }
                else
                {
                    prev = curr;
                    curr = curr->getNext();
                }
            }
            if (curr == NULL)
            {
                cout << "Not Present in List \n";
            }
            if (found)
            {
                prev->setNext(curr->getNext());
                delete curr;
                if (prev->getNext() == NULL)
                {
                    last = prev;
                }
            }
            else
            {
                cout << "Not Present in List\n";
            }
        }
    }
}
int orderList::findMin()
{
    int maxi;
    if (first == NULL)
    {
        maxi = -1;
    }
    else
    {
        maxi = first->getData();
    }
    return maxi;
}

int orderList::findMax()
{
    int maxi;
    if (first == NULL)
    {
        maxi = -1;
    }
    if (first->getNext() == NULL)
    {
        maxi = this->first->getData();
    }
    if (this->last != NULL)
    {
        maxi = this->last->getData();
    }
    return maxi;
}

void orderList::print()
{
    Node *temp = this->first;
    while (temp != NULL)
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

void orderList::insert(int data)
{
    Node *temp = new Node();
    Node *curr = first;
    Node *prev;
    temp->setData(data);
    bool found = false;
    if (this->first == NULL)
    {
        this->first = temp;
        this->last = temp;
    }
    else
    {
        if (first->getData() >= data)
        {
            temp->setNext(first);
            first = temp;
        }
        else
        {

            while (curr != NULL && !found)
            {
                if (curr->getData() >= data)
                {
                    found = true;
                }
                else
                {
                    prev = curr;
                    curr = curr->getNext();
                }
            }
            if (curr == NULL)
            {
                this->last->setNext(temp);
                this->last = temp;
            }
            if (found)
            {
                prev->setNext(temp);
                temp->setNext(curr);
            }
        }
    }
}
int main()
{
    // implementin order Link List to insert in order link List
    cout << "===================================================================Order Link List ===========================================\n";
    orderList od;
    od.insert(10);
    od.insert(11);
    od.insert(120);
    od.insert(230);
    od.insert(20);
    od.insert(30);
    od.insert(9);
    od.print();
    od.Delete(230);
    od.Delete(9);
    cout << "Max Of List : " << od.findMax() << endl;
    cout << "Min Of List : " << od.findMin() << endl;

    cout << "=====================================Unorder Link List ====================================================\n";
    List l;
    cout << "Inserting the Data i List \n";

    l.Insert(31);
    l.Insert(32);
    l.Insert(33);
    l.Insert(34);
    l.Insert(35);
    l.Insert(-10);
    l.Insert(36);
    l.Insert(37);
    l.Insert(39);
    l.Insert(40);
    l.Insert(400);
    l.Insert(41);
    l.Insert(42);
    l.Insert(43);
    l.Insert(44);


    cout << "Finding max in unordered Link List \n";
    cout << l.findMax() << endl;
    cout << "Finddint Min Unordered Link  List \n";
    cout << l.findMin() << endl;
    cout << "Searching \n";
    cout << (l.search(4400) ? "Present in List\n" : "Not Prenst IN List \n");

    cout<<"Inserting at Pos \n";
    l.Print();
    l.insertAtLocation(2001,4);
    l.Print();
}
