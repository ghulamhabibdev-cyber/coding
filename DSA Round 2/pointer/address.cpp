#include <iostream>
#include<string>
using namespace std;

class A {
};

int main() {
    int a=10;
    int *add=&a;
    string ad=to_string(*add);
    cout<<ad<<endl;
    return 0;
}