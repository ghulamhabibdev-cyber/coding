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

void change(int *a) {
    *a = 10;
    return;
}
void changeb(int &n) {
    n = 10;
    return;
}


int main() {
    int a=5;
    int *p=&a;
    int **ptr=&p;
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<(*p)<<endl;
    cout<<(*ptr)<<endl;
    cout<<(**ptr)<<endl;
    int b=20;
    change(&b);
    cout<<b<<endl;
    int n=100;
    cout<<n<<endl;
    changeb(n);
    cout<<n<<endl;

    return 0;
}