#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;

class a{

};

int main() {
    int a=10;
    char c='b';
    a=c;
    cout<<a++<<endl;
    c=a;
    cout<<c<<endl;
    int nu=10;
    string srt=std::to_string(nu);
    cout<<srt<<endl;
    int n=stoi(srt);
    cout<<n<<endl;
    return 0;
}