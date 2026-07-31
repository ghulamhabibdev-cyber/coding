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
        next = NULL;
    }
    ~node()
    {
        
    }
};
class Stack
{
public:
    int val;
    node *head;
    int count;
    Stack()
    {
        head = NULL;
        count = 0;
    }
    ~Stack()
    {
        clear();
    }

    void push(int value)
    {
        node *temp = new node(value);
        node *take = head;
        head = temp;
        head->next = take;
        count++;
    }
    void pop()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            node *headNext = head->next;
            node *temp = head;
            delete temp;
            head = headNext;
            count--;
        }
    }
    int peek()
    {
        if (head != NULL)
        {
            int val = head->data;
            return val;
        }
        else
        {
            cout << "Stack is empty \n";
            return -1;
        }
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int getSize()
    {
        return count;
        
    }
    void clear()
    {
        while (head != NULL)
        {
            node *temp = head;
            head = head->next;
            delete temp;

            /* code */
        }
        count = 0;

        // head=NULL;
    }
    void display()
    {
        node *temp = head;
        if (temp == NULL)
        {
            cout << "Stack is Empty\n";
            return;
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    Stack st;
    st.push(1);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.pop();
    st.pop();
    cout << st.peek() << endl;
    if (st.isEmpty())
    {
        cout << "Stack is Empty\n";
    }
    else
    {
        cout << "Stack has data \n";
    }
    st.clear();
    st.push(1);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.display();
    cout << "Size of Stack : " << st.getSize();

    return 0;
}