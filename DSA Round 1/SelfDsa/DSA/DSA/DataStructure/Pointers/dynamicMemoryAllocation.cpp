#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Dynamic memory allocation for a char
    char *pt = new char;
    *pt = 3;
    cout << "Char Value (ASCII 3): " << *pt << endl;

    // Dynamic memory allocation for an array of 50 integers
   int *ptr=new int[5];
   int *start=ptr;
   for(int i=0;i<5;i++)
   {
    cin>>ptr[i];
   }
    for(int i=0;i<5;i++)
   {
    cout<<ptr[i];
   }
//    delete start;

    return 0;
}
