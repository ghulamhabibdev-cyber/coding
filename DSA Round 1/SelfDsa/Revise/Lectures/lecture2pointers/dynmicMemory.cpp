#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int *p = new int;
    *p = 45;
    cout << *p << endl;
    char *name = new char[6];
    strcpy(name, "Ali");
    cout << name << endl;
    string * str=new string;
    *str="What a beautiful day ";
    int arr[]={3,4,5};
    // for(int i=0;i<100;i++)
    // {
    //     if(i>=4)
    //     {
    //         int *p=&arr[i];
    //         *p=32;
    //     }
    //     cout<<arr[i]<<" ";
    // }
    // cout<<*str<<endl;
    free(name);
    return 0;
}
