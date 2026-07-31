#include <iostream>
using namespace std;

class a{

};
bool checkAdult(int age)
{
    if(age>18)
    {
        return 1;
    }
    return false;
}
int main() {
    int age;
    cout<<"Enter your age \n";
    cin>>age;
    if(checkAdult(age))
    {
        cout<<"Your are Adult\n";
    }
    else{
        cout<<"You are Teenage \n";
    }

    return 0;
}