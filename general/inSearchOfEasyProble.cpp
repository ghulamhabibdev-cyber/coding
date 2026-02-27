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
bool isEasy(int n)
{
    for(int i=1;i<=n;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    bool easy=isEasy(n);
    if(easy)
    {
        cout << "EASY";
    }
    else{
        cout<<"HARD";
    }
    return 0;
}