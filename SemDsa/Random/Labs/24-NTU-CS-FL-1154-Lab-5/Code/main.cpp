#include <iostream>
// #include "stack.h"
#include "stackLink.h"
using namespace std;

int main()
{
        stack st;
        cout << "Testing the stack \n";
        if (st.isEmpty())
        {
            cout << "Stack is empty \n";
        }
        else
        {
            cout << "Stack is not Empty \n";
        }
        st.push(10);
       cout<< st.top()<<endl;
    st.push(20);
    cout << st.top() << "\n";
    st.push(30);
    st.push(40);
    st.display();
    st.pop();
    st.display();
    if (st.isFull())
    {
        cout << "Stack is full \n";
    }
    else
    {
        cout << "Stack is not pull \n";
    }
    cout << st.size() << endl;
    system("pause");

    stack stLink;
    cout << stLink.isEmpty() << endl;
    stLink.push(10);
    stLink.push(20);
    stLink.display();
    cout << stLink.top() << endl;
    cout << stLink.size() << endl;
    cout<<stLink.isFull()<<endl;
    cout<<stLink.isEmpty()<<endl;
    return 0;
}
