#include <iostream>
using namespace std;

class a
{
};

int main()
{
    cout << "=============== Understanding data Types ======================\n";
    // int a;  // decalaraion
    // a = 10; // define
    // cout << a << endl;
    int a=10,b=10;
    cout<<a<<endl<<b<<endl;
    char ch='c';
    // character take memory of 1byte or 8 bit its universal
    cout<<ch<<endl;
    double d=43.34;//double take memory of 8 byte 64 bit
    cout<<d<<endl;
    bool isPassed=1;//bool take 1 bit memory 
    cout<<isPassed<<endl;
    cout << "=====================================\n";

    return 0;
}