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
bool haveEqualEvenOdd(vector<int>arr)
{
    int evenCount=0;
    int oddCount=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]%2==0)
        {
            evenCount++;
        }
        else{
            oddCount++;
        }
    }
    return evenCount==oddCount;
}
int paityBalancedAray(vector<int>arr)
{
    if(!haveEqualEvenOdd(arr))
    {
        return -1;
    }
    int n=arr.size();
    int swapCount=0;
    int i=0;
    int j=1;
    while(j+2<n)
    {
        if(arr[i]%2==0 && arr[j]%2==1)
        {
            i+=2;
            j+=2;
        }
        else{
            if(arr[i]%2==1 && arr[j]%2==0)
            {
                swapCount++;
                i+=2;
                j+=2;
            }
            
        }

    }
}
int main() {
    
    return 0;
}