#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num = 10;
    int *num_ptr = &num;
    int value=390;
    cout << "Ptr value : " << *(num_ptr) << endl;
    cout << "Number values : " << num << endl;
    cout << "Variable Address : " << &num << endl;
    cout << "Having address of varible : " << num_ptr << endl;
    cout << "Pointer address : " << &num_ptr << endl;
    int *nully;
    nully=&num;
    *nully=320;
    nully=&value;
    cout<<"Nully has value of : "<<*(nully)<<endl; 
    int *test1;
    for(int i=0;i<40;i++)
    {
        if(i==1)
        {
            test1=&i;
        }
    }
    cout<<"is values die : "<<*test1<<endl;
    cout<<"Size of pointer : "<<sizeof(test1)<<endl;
    cout<<"size of vari : "<<sizeof(num)<<endl;
    return 0;
}
