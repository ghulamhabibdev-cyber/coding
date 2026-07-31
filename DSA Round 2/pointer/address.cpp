#include <iostream>
#include <string>
using namespace std;

class A
{
};

int main()
{
    int a = 10;
    int *add = &a;
    string ad = to_string(*add);
    cout << ad << endl;
    cout << "Address of a: " << add << endl;
    float price = 100.3;
    float *pr = &price;
    cout << (*pr) << endl;
    cout << "Address of price: " << pr << endl;
    cout << "Address of Pointers : " << &pr << endl;
    cout << "Address of add : " << (&add) << endl;

    // double pointer or pointer to pointer
    int abs = 100;
    int *ptr = &abs;
    int **pptr = &ptr;
    cout<<(*pptr)<<endl;
    cout << (**pptr) << endl;
    return 0;
}