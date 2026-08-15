#include <iostream>
using namespace std;

class A
{
};

enum oddEven
{
    even = 1,
    odd = 0
};

bool isEven(int n)
{
    if (n & 1)
    {
        return odd; 
    }
    return even; 
}

int main()
{
    // Example usage
    if (isEven(4))
    {
        cout << "4 is even" << endl;
    }
    return 0;
}
