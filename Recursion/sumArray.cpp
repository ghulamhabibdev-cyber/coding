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
int sumArray(vector<int>arr,int i)
{
    if(i>=arr.size())
    {
        return 0;
    }
    int sum=sumArray(arr,i+1);
    sum+=arr[i];
    return sum;
}
int main() {
    vector<int>arr={2,2,2,2};
    cout<<sumArray(arr,0);
    
    
    return 0;
}