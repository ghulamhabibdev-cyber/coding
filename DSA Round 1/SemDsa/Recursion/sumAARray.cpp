#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A {
};
int sumArray( vector<int>arr,int n)
{
    if(n<=0)
    {
        return 0;
    }
    return arr[n-1]+sumArray(arr,n-1);
}
int main() {
     vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};
    int n = arr.size();
    int sum=sumArray(arr,n);
    cout<<sum<<endl;
    
    return 0;
}