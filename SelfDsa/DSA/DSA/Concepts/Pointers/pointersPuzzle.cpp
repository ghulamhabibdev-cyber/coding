// more pointers
#include <iostream>
using namespace std;

int main()
{
    int firstvalue = 5, secondvalue = 15;
    int *p1, *p2;

    p1 = &firstvalue;  // p1 = address of firstvalue
    p2 = &secondvalue; // p2 = address of secondvalue
    *p1 = 10;          // value pointed to by p1 = 10
    *p2 = *p1;
    cout << "value : *P1 : " << (*p1) << endl;
    cout << "value : *P2 : " << (*p2) << endl;
    cout << "firstvalue is " << firstvalue << '\n';
    cout << "secondvalue is " << secondvalue << '\n\n';
    // value pointed to by p2 = value pointed to by p1
    p1 = p2; // p1 = p2 (ghghhghghgghhghghg of pointer is copied)
    cout << "\nfirstvalue is " << firstvalue << '\n';
    cout << "secondvalue is " << secondvalue << '\n';
    *p1 = 20; // value pointed to by p1 = 20

    cout << "firstvalue is " << firstvalue << '\n';
    cout << "value : *P1 : " << (*p1) << endl;
    cout << "secondvalue is " << secondvalue << '\n';
    *p1 += 200;
    cout << "firstvalue is " << firstvalue << '\n';
    cout << "value : *P1 : " << (*p1) << endl;
    cout << "secondvalue is " << secondvalue << '\n';
    return 0;
}