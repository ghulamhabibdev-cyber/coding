#include <bits/stdc++.h>
using namespace std;
class CustomStack
{
public:
    int size;
    int top;
    int *arr;
    int totalCount;
    CustomStack(int maxSize)
    {
        top = -1;
        size = maxSize;
        arr = new int[size];
        totalCount=0;
    }

    void push(int x)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = x;
            totalCount++;
            return;
        }
        return;
    }

    int pop()
    {
        cout<<"Top value : "<<top <<endl;
        if (top >= 0)
        {
            
            int val = arr[top];
            top--;
            totalCount--;
            return val;
        }
        return -1;
    }

    void increment(int k, int val)
    {
        if(totalCount>0)
        {
            
            if(totalCount<k)
            {
                
                for(int i=0;i<totalCount;i++)
                {
                    arr[i]=arr[i]*val;
                }
            }
            else{
                for(int i=0;i<k;i++)
                {
                    arr[i]=arr[i]*val;
                }
            }

        }
        return;
    }
   
};

int main()
{
    CustomStack st(10);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.increment(5,10);
    st.print();

    // cout << st.pop() << endl;
    // cout << st.pop() << endl;
    return 0;
}