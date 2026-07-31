#include <bits/stdc++.h>
using namespace std;
class MyStack {
public:
   
    deque<int>q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push_front(x);
        
    }
    
    int pop() {
        int val=q.front();
         q.pop_front();
         return val;
        
    }
    
    int top() {
        int val=q.front();
         return val;
        
    }
    
    bool empty() {
        if(q.empty()){
            return true;
        }
        return false;
    }
};
int main()
{
    MyStack st;
    cout<<st.empty()<<endl;
    st.push(32);
    st.push(20);
    cout<<st.top()<<endl;
     cout<<st.empty()<<endl;
    cout<<st.pop()<<endl;
    cout<<st.pop()<<endl;
    
    return 0;
}