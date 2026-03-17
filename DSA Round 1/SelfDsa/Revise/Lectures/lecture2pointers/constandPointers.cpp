#include <iostream>
using namespace std;

int main()
{
    // const int * mean you can not modify the value of that variable using pojnter
    // but you can point this pointer to another variable
    int c = 90;
    const int *ptr = &c;
    cout << *ptr << endl;
    // *ptr=40;
    cout << *ptr << endl;
    int cat = 43;
    ptr = &cat;
    cout << *ptr << endl;
    int age = 34;
    int const *ptr2 = &age;

    cout << *ptr2 << endl;
    // *ptr2=4;
    cout << *ptr2 << endl;
    ptr2 = &c;
    cout << *ptr2 << endl;

    return 0;
}
