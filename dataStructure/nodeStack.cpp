#include <iostream>
using namespace std;

class Stack
{
private:
    class Node
    {
    public:
        int data;
        Node *next;

    public:
        Node(int data)
        {
            this->data = data;
            next = NULL;
        }
    };
    Node *head;
    int n;
    Node *getNode(int data)
    {
        return new Node(data);
    }

public:
    Stack()
    {
        head = nullptr;
        n = 0;
    }
    void push(int data)
    {
        Node *newNode = getNode(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        n++;
    }
    void pop()
    {
        if (head == NULL)
        {
            cout << "Segementation Fault" << endl;
        }
        Node *del = head;
        head = head->next;
        delete del;
    }
    int top()
    {
        if (head)
        {
            return head->data;
        }
        return INT_MIN;
    }
    bool empty()
    {
        return head == NULL;
    }
    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack st;
    st.push(10);
    st.push(12);
    st.push(32);
    st.push(40);
    st.print();
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}