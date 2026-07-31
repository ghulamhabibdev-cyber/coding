#include <bits/stdc++.h>
using namespace std;
void update(int **pt)
{
    // pt=pt+1;
    // *pt=*pt+1;
    **pt=**pt+5;
    
}
int main() {
  
    int i=4;
    int * ptr=&i;
    int **pt=&ptr;
    // cout<<i<<endl;
    // cout<<*ptr<<endl;
    // cout<<*(*pt)<<endl;
    // //printing ptr
    // cout<<" i adress : "<<&i<<endl;
    cout<<" at ptr   :"<<ptr<<endl;
    // cout<<" at ptr   :"<<*pt<<endl;
    update(pt);
    cout<<ptr<<endl;
    cout<<" value after update : "<<i<<endl;

    return 0;
}