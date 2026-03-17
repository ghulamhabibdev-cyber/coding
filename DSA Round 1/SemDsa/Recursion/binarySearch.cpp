#include <iostream>
#include<vector>
using namespace std;
int binarySearchSolver(vector<int>arr,int st,int end,int key)
{
    if(st<=end)
    {
        int mid=st+(end-st)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            return binarySearchSolver(arr,mid+1,end,key);
        }
        else if(arr[mid]>key){
            return binarySearchSolver(arr,st,mid-1,key);
        }


    }
    return -1;
}
int binarySearcy(vector<int>arr,int n,int key)
{

    
    return binarySearchSolver(arr,0,arr.size(),key);
}
class A {
};

int main() {
    vector<int>arr={10,30,35,46,47,48,55,59,60,67,69};
    int n=arr.size();
  cout<<  binarySearcy(arr,n,46);
    
    return 0;
}