#include <iostream>
using namespace std;

class a{

};

int main() {
    int a=0;
    int b=1;
    int n;
   
    cout<<"Enter a number \n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
       int curr=a;
       cout<<curr<<" ";
       a=b;
       b=a+curr;
      
    }
    

    return 0;
}