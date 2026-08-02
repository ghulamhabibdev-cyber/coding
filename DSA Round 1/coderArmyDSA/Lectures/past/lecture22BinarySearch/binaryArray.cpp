#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class A {
};
int binarySearch(vector<int>v,int key)
{
    int s=0;
    int e=v.size()-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(v[mid]==key)
        {
            return mid;
        }
        if(v[mid]<key)
        {
            s=mid+1;
        }
        if(v[mid]>key)
        {
            e=mid-1;
        }
    }
  return  -1;
}
int main() {
    vector<int>v={1,2,3,4,5,6,10,12,34,45,67,89,678,4567,789088};
    int index=binarySearch(v,45);
    if(index<0)
    {
        return 0;
    }
    cout<<v[index];
    return 0;
}