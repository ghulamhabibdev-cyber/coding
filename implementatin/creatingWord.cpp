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

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string str;
        string strb;
        cin>>str>>strb;
        swap(str[0],strb[0]);
        cout<<str<<" "<<strb<<endl;
    }
    return 0;
}