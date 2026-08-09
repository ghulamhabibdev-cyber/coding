#include <iostream>
using namespace std;
template <typename T>
class vector
{
    int cap;
    T *arr;
    int index = -1;

public:
    vector(int n)
    {
        arr = new T[n];
        cap = n;
    }
    vector()
    {
        arr = new T[1];
        cap = 1;
    }
    void push_back(T val)
    {
        if (index >= cap)
        {
            T *temp = new T[cap * 2];
            for (int i = 0; i < cap; i++)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
            cap = cap * 2;
        }
        if (index == -1)
        {
            index++;
        }
        arr[index] = val;
        index++;
    }
    void pop_back()
    {
        if (index >= 0)
        {
            index--;
        }
    }
    int size()
    {
        return index;
    }
    int capacity()
    {
        return cap;
    }
    T &operator[](int i)
    {
        return arr[i];
    }
    const T &operator[](int i) const
    {
        return arr[i];
    }
    ~vector()
    {
        delete[] arr;
    }
};
int main()
{
    vector<int> intVec;
    intVec.push_back(10);
    intVec.push_back(20);
    for (int i = 0; i < intVec.size(); i++)
    {
        cout << intVec[i] << " ";
    }
    return 0;
}
