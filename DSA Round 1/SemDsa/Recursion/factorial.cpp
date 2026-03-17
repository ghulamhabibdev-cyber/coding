#include <iostream>
using namespace std;

class A {
};
int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
   return n*fact(n-1);
   
}
int main() {
     int n;

    cout << "Enter a Number \n";
    cin >> n;
  cout<<  fact(n);
    
    return 0;
}