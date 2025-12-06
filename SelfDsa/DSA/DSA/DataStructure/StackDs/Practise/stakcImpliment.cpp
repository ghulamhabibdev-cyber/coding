#include <bits/stdc++.h>
using namespace std;
// implemnting stack using array
class Stack
{
public:
    int size;
    int top;
    int *arr;
    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new int[size];
    }
    ~Stack()
    {
        delete[] arr;
    }
    void push(int element)
    {
        if (top < size - 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack Overflow\n";
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "Stack Under flow \n";
        }
    }
    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty \n";
            return -1;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        return 0;
    }
    bool isFull()
    {
        if (top == (size - 1))
        {
            return true;
        }
        else
        {
            return 0;
        }
    }
    int getSize()
    {
        return size;
    }
    void clear()
    {
        top = -1;
    }
    void display()
    {
        if (top >= 0)
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Empty Stack \n";
        }
    }
    bool contain(int element)
    {
        for (int i = top; i >= 0; i--)
        {
            if (arr[i] == element)
            {
                return true;
            }
        }
        return false;
    }
    int getBottom()
    {
        if (top >= 0)
        {
            return arr[0];
        }
        else
        {
            cout << "Stack is empty\n";
            return -1;
        }
    }
};
int main()
{
    Stack st(3);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(4);
    st.display();
    // st.pop();
    // st.display();
    // st.clear();
    // st.display();
    cout << st.peek() << endl;
    cout << st.contain(40) << endl;
    cout << st.getBottom() << endl;
    cout << st.isEmpty() << endl;
    cout << st.isFull() << endl;

    return 0;
}