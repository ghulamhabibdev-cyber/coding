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
int findMaxSumArray(int n,int m)
{
    if(n<=2)
    {
        return m;
    }
    if(n%2==0){
        int num = m / 2;
        int secondNum = 0;
        if(m%2==1)
        {
            secondNum=num+1;
        }
    }
}
int main() {
    
    return 0;
}