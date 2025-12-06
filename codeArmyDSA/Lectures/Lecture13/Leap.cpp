#include <iostream>
using namespace std;

class a{

};

int main() {
    int year;
    cout<<"Enter  Year \n";
    cin>>year;
    if((year%4==0)&&(year%100!=0)||(year%400==0))
    {
        cout<<"Leap Year \n";
    }
    else{
        cout<<"Not Leap Year\n";
    }

    return 0;
}