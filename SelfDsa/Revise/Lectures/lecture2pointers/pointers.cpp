#include<iostream>
using namespace std;
int *getPointer()
{
    int x = 10;

    // returning address of local variable
    return &x;
}

int main()
{
    // int *x,q;
    // q=10;
    // x=&q;
    // cout<<*x<<endl;
    int x = 42;

    // void pointer holding address of an int
    // void *ptr = &x;

    // Error: cannot dereference void pointer
    // cout << *ptr;

    // Typecast before dereferencing
    // cout << "Value pointed by void pointer: " << *(static_cast<int *>(ptr)) << endl;
    int *ptr = getPointer();

    // Undefined behavior
    cout << *ptr;
    return 0;
}
