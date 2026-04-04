#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A {
};
int linearSearch(vector<int>arr,int key)
{
    int n=arr.size();
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        { 
            return i;
        }
    }
    return -1;
}
int main() {
    vector<int>arr={1,2,34,34,4234,343,6535,33,23,43};
    int index=linearSearch(arr,34);
    if(index!=-1)
    {
        cout<<arr[index]<<endl;
    }
    else{
        cout<<"Nout found"<<endl;
    }
    
    return 0;
}