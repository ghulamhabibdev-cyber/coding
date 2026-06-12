#include <iostream>
using namespace std;
template <typename T>
class Vector
{
    int capa;
    int n;
    T *arr;
    void copy(const Vector &v)
    {
        n = v.n;
        capa = v.capa;
        arr = new T[capa];
        for (int i = 0; i < n; i++)
        {
            arr[i] = v.arr[i];
        }
    }
    void merge(const Vector &v)
    {
        int new_n = n + v.n;
        int new_capa = std::max(capa, v.capa);
        T *newArr = new T[new_capa];
        for (int i = 0; i < n; i++)
        {
            newArr[i] = arr[i];
        }
        for (int i = 0; i < v.n; i++)
        {
            newArr[n + i] = v.arr[i];
        }
        delete[] arr;
        arr = newArr;
        n = new_n;
        capa = new_capa;
    }
    void copyArray()
    {
        if (n == capa)
        {
            capa *= 2;
            T *newArr = new T[capa];
            for (int i = 0; i < n; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
        }
    }

public:
    Vector()
    {
        n = 0;
        capa = 1;
        arr = new T[capa];
    }
    Vector(int n, T value)
    {
        this->n = n;
        capa = n;
        arr = new T[capa];
        for (int i = 0; i < n; i++)
        {
            arr[i] = value;
        }
    }
    Vector(const Vector &v)
    {
        copy(v);
    }
    void push_back(T value)
    {
        if (n == capa)
        {
            copyArray();
        }
        arr[this->n++] = value;
    }
    void pop_back()
    {
        if (n > 0)
        {
            n--;
        }
        // return -1; // or throw an exception
    }
    int capacity()
    {
        return capa;
    }
    int size()
    {
        return n;
    }
    int operator[](int index)
    {
        if (index >= 0 && index < n)
        {
            return arr[index];
        }
        return -1;
    }
};
int main()
{
    Vector<int> v;
    v.push_back(5);
    v.push_back(10);
    cout << v[0] << " " << v[1] << endl;
    return 0;
}