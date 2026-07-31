#include<iostream>
using namespace std;
void Ref(int &n)
{
    n++;
    cout<<n<<endl;
}
int main()
{
    int n=5;
    Ref(n);
    cout<<n+1<<endl;
}