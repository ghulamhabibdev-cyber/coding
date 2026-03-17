#include <bits/stdc++.h>
#include "ArrayBaseList.h"
using namespace std;
class polyNomial : public arrayListType<double>
{
    friend ostream &operator<<(ostream &os, const polyNomial &);
    friend istream &operator>>(istream &is, polyNomial &p);

public:
    polyNomial operator+(const polyNomial &);
    polyNomial operator-(const polyNomial &);
    polyNomial operator*(const polyNomial &);
    double operator()(double x);
    polyNomial(int size = 100);
    int min(int x, int y);
    int max(int x, int y);
    polyNomial() : arrayListType<double>(100) // or 0
    {
        length = 100;
        for (int i = 0; i < length; i++)
            list[i] = 0;
    }
    polyNomial& operator=(const polyNomial& other) {
        if (this != &other) {
            length = other.length;
            maxSize = other.maxSize;
            if (list != nullptr) delete[] list;   // cleanup old
            list = new double[maxSize];           // allocate new
            for (int i = 0; i < length; i++) {
                list[i] = other.list[i];          // deep copy
            }
        }
        return *this;
    }
    
};
istream &operator>>(istream &is, polyNomial &p)
{
    cout << "Enter the degree of polynomial (" << p.length << " terms)" << endl;
    for (int i = 0; i < p.length; i++)
    {
        cout << "Enter the coefficient of x^" << i << " : ";
        is >> p.list[i];
    }
    return is;
}

ostream &operator<<(ostream &os, const polyNomial &p)
{
    bool first = true;
    for (int i = 0; i < p.length; i++)
    {
        if (p.list[i] != 0.0)
        {
            if (!first && p.list[i] > 0) os << "+ ";
            if (p.list[i] < 0) os << "- ";
            os<< fabs(p.list[i]);
            if (i > 0) os << "x^" << i;
            os << " ";
            first = false;
        }
    }
    if (first) os << "0"; // case when all coefficients are 0
    return os;
}
int polyNomial::min(int x, int y)
{
    if (x <= y)
    {
        return x;
    }
    return y;
}
int polyNomial::max(int x, int y)
{
    if (x >= y)
    {
        return x;
    }
    return y;
}
polyNomial polyNomial::operator-(const polyNomial &right)
{
    int size = max(length, right.length);
    polyNomial temp(size);
    for (int i = 0; i < min(length, right.length); i++)
    {
        temp.list[i] = list[i] - right.list[i];
    }
    if (size == length)
    {
        for (int i = min(length, right.length); i < length; i++)
        {
            temp.list[i] = list[i];
        }
    }
    else
    {
        for (int i = min(length, right.length); i < right.length; i++)
        {
            temp.list[i] = -right.list[i];
        }
    }
    return temp;
}
polyNomial polyNomial::operator+(const polyNomial &right)
{
    int size = max(length, right.length);
    polyNomial temp(size);
    for (int i = 0; i < min(length, right.length); i++)
    {
        temp.list[i] = list[i] + right.list[i];
    }
    if (size == length)
    {
        for (int i = min(length, right.length); i < length; i++)
        {
            temp.list[i] = list[i];
        }
    }
    else
    {
        for (int i = min(length, right.length); i < right.length; i++)
        {
            temp.list[i] = right.list[i];
        }
    }
    return temp;
}
double polyNomial::operator()(double x)
{
    double value = 0.0;
    for (int i = 0; i < length; i++)
    {
        if (list[i] != 0.0)
        {
            value += list[i] * pow(x, i);
        }
    }
    return value;
}

polyNomial::polyNomial(int size) : arrayListType(size)
{
    length = size;
    for (int i = 0; i < size; i++)
    {
        list[i] = 0;
    }
}
int main()
{
    polyNomial p(8);
    polyNomial q(4);
    polyNomial t(8);
    cin >> p;
    cout << "p(x) : " << p << endl;
    cin >> q;
    cout << "q(x) : " << q << endl;
    t = p - q;
    cout<<t<<endl;

}