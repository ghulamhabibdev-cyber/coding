#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class A {
};

int main() {
    char ch;
    cin>>ch;
    // int big=ch-'a'+'A';
    // char bigCh=big;
    // cout<<bigCh;
    int mask=223;//11011111
    int val=ch;
    int big=mask&val;
    char newCh=big;
    cout<<newCh<<endl;
    return 0;
}