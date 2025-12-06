#include <bits/stdc++.h>
using namespace std;
// pointers and function and pointer arithmatic
void PrintPtr(int *ptr,int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<*(ptr+i);
    }
}
int main()
{
    // int number1 = 12;
    // int number2 = 23;
    // int *ptr1 = &number1;
    // int *ptr2 = &number2;

    // //
    // //
    //     cout << " Adress of Pointer1 : " << (ptr1) << endl;
    // cout << " Adress of Pointer2 : " << (ptr2) << endl;
    // cout << " Adress of Number1 : " << (&number1) << endl;
    // cout << " Adress of Number12 : " << (&number2) << endl;
    // cout << " value of Pointer1 : " << (*ptr1) << endl;
    // cout << " value of Pointer2 : " << (*ptr2) << endl;
    // cout << " value of Number1 : " << (number1) << endl;
    // cout << " value of Number12 : " << (number2) << endl;
    // ///
    // //

    // for (int i = 0; i < 10; i++)
    // {
    //     int temp = i;
    //     int num = 23;
    //     i = i + num;
    //     *ptr1 += i;
    //     *ptr2 += i;
    //     i = temp;
    // }
    // cout << " Adress of Pointer1 : " << (ptr2) << endl;
    // cout << " Adress of Pointer2 : " << (ptr2) << endl;
    // cout << " Adress of Number1 : " << (&number1) << endl;
    // cout << " Adress of Number12 : " << (&number2) << endl;
    // cout << " value of Pointer1 : " << (*ptr1) << endl;
    // cout << " value of Pointer1 : " << (*ptr2) << endl;
    // cout << " value of Number1 : " << (number1) << endl;
    // cout << " value of Number12 : " << (number2) << endl;
    
    //arrays and pointers 

    // int arr[5];
    // int *ptr=arr;
    // *ptr=10;
    // ++ptr;*ptr=20;
    // ++ptr;*ptr=30;
    // ++ptr;*ptr=40;
    // ++ptr;*ptr=50;
    // for(int i=0;i<5;i++)
    // {
    //     cout<<arr[i]<<" , ";
    //     cout<<*(arr+i)<<" | ";
    //     cout<<(arr+i)<<endl;
    // }
    
    // int num=3;
    // int *p=&num;
    // PrintPtr(p,1);
    // int arr2[4]={1,4,5,7};
    // p=arr2;
    // PrintPtr(p,4);
    

    // const ptr
    int num2=3;
    const int *p=&num2;
    cout<<*p<<endl;
    num2+=3;
    cout<<*p<<endl;

      int num3=5;
    const int* const p2=&num3;
    cout<<*p2<<endl;
    num3+=3;
    cout<<*p2<<endl;
    return 0;
  
}