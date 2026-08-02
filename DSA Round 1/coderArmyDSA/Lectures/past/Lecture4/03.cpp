#include <iostream>
using namespace std;

class a{

};

int main() {
    int n=1;
    if(n>4)
    {
        cout<<"big then 4\n";
    }
    if(n>5)
    {
        cout<<"Big then 5 \n";
    }
    if(n>6)
    {
        cout<<"big then 6\n";
    }
    if(n>6)
    {
        cout<<"BIg 3 then 6\n";
    }
    else if(n>7)
    {
        cout<<"NOt run \n";
    }
    else if(n>8)
    {
        cout<<"Not run \n";
    }
    else {
        cout<<"I am winner \n";
    }

    return 0;
}