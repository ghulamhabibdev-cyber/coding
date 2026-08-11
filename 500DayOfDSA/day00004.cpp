#include <iostream>
using namespace std;

class A {
};
bool isMadeFromConsective(int n)
{
    if(n==1)
    {
        return false;
    }
    if(n&(n-1)==0)
    {
        return false;
    }
    return true;
}
int main() {
    
    return 0;
}