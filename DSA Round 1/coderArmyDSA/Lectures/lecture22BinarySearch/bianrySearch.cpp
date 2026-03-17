#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class A {
};
int binarySearch(vector<int>vec,int key)
{
    int start=0;
    int end=vec.size()-1;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if(vec[mid]==key)
        {
            return mid;
        }
        else if(vec[mid]<key)
        {
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        /* code */
    }
    return -1;
}
int main() {
//     vector<int>vec={300,200,100,50,40,35,30,20,15,10,9,8,5,1};
//     int key;
//     cout<<"Enter searching element \n";
//     cin>>key;
//    int index=binarySearch(vec,key);
//    if(index<0)
//    {
//     return 0;
//    }
//     cout<<vec[index]<<endl;
cout<<(1/2);
    return 0;
}