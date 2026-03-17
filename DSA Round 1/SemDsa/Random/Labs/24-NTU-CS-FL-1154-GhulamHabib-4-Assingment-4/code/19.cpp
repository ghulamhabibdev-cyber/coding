#include <iostream>
using namespace std;
class node
{
private:
    string data;
    node *next;

public:
    void setData(string data);
    string getData();
    void setNext(node *);
    node *getNext();
};
void node::setData(string data)
{
    this->data = data;
}
void node::setNext(node *next)
{
    this->next = next;
}
string node::getData()
{
    return data;
}
node *node::getNext()
{
    return next;
}
class ticketSystem
{
private:
    node *front;
    node *back;
    int count;

public:
    ticketSystem()
    {
        front = NULL;
        back = NULL;
        count = 0;
    }
    void addCustomer(string name);
    void serverCustomer();
    string currentCustomer();
    string lastCustomer();
    bool isEmpty();
    bool isFull();
    int totalCustomer();
};
int ticketSystem::totalCustomer()
{
    if (count <= 0)
    {
        count = 0;
    }
    return count;
}
bool ticketSystem::isFull()
{
    return false;
}
bool ticketSystem::isEmpty()
{
    return front == NULL;
}
string ticketSystem::lastCustomer()
{
    if (back != NULL)
    {
        return back->getData();
    }
    return "-1";
}
string ticketSystem::currentCustomer()
{
    if (front != NULL)
    {
        return front->getData();
    }
    return "-1";
}
void ticketSystem::serverCustomer()
{
    node *curr = front;
    front = front->getNext();
    if (front == NULL)
    {
        back = front = NULL;
    }
    delete curr;
    count--;
}
void ticketSystem::addCustomer(string name)
{
    node *customer = new node();
    customer->setData(name);
    customer->setNext(NULL);
    if (front == NULL)
    {
        front = customer;
        back = customer;
    }
    else
    {
        back->setNext(customer);
        back = customer;
    }
    cout << "customer : " << name << " is Added To System \n";
    count++;
}
int main()
{
    ticketSystem syst;
    syst.addCustomer("Habib");
    syst.addCustomer("Ali");
    cout << syst.currentCustomer() << endl;
    cout << syst.totalCustomer() << endl;
    syst.serverCustomer();
    cout << syst.currentCustomer() << endl;
    return 0;
}
