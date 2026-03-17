#include <bits/stdc++.h>
using namespace std;
class a
{
};

int main()
{
    int *p;
    int *q;
    int num = 10;
    p = &num;
    q = p;
    cout << "Adress of Num : " << &num << endl;
    cout << "Adress of Num via Pointer p : " << p << endl;
    cout << "Adress of num via Pointer q  : " << q << endl;
    cout << "Value of Num via num : " << num << endl;
    cout << "Value of num via p   : " << *p << endl;
    cout << "Value of Num via q   : " << *q << endl;
    *p = 100;
    cout << "Adress of Num : " << &num << endl;
    cout << "Adress of Num via Pointer p : " << p << endl;
    cout << "Adress of num via Pointer q  : " << q << endl;
    cout << "Value of Num via num : " << num << endl;
    cout << "Value of num via p   : " << *p << endl;
    cout << "Value of Num via q   : " << *q << endl;
    *q=104343400;
    cout << "Adress of Num : " << &num << endl;
    cout << "Adress of Num via Pointer p : " << p << endl;
    cout << "Adress of num via Pointer q  : " << q << endl;
    cout << "Value of Num via num : " << num << endl;
    cout << "Value of num via p   : " << *p << endl;
    cout << "Value of Num via q   : " << *q << endl;

    //    dynamic vaiable and memory allocation in c++
    // int *ptr_number=new int;
    // *ptr_number=10;
    // cout<<*ptr_number<<endl;
    // delete ptr_number;
    // ptr_number=NULL;
    // cout<<*ptr_number<<endl;

    return 0;
}
