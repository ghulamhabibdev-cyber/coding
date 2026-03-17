#include<bits/stdc++.h>
using namespace std;
class  a
{

};

int main()
{

    int arr[4]={1,2,4,5};
    int arr3[4];
    copy(arr,arr+4,arr3);
    for(int i=0;i<4;i++)
    {
        cout<<arr3[i]<<" ";
    }
    // copy the element of array into vec;
    vector<int>v(10);
    copy(arr3,arr3+4,v.begin());
    cout<<endl;
    cout<<"Printing the data after the copying \n";
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

    return 0;
}
