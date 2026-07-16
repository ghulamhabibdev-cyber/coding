#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
using namespace std;

class A
{
};
bool getBit(int num, int i)
{
    return ((num & (1 << i)) != 0);
}
int setBit(int num, int i)
{
    return num | (1 << i);
}
int clearBit(int num, int i)
{
    int mask = ~(1 << i);
    return num & mask;
}
int clearBitMsThroughI(int num, int i)
{
    int mask = (1 << i) - 1;
    return num & mask;
}
int main()
{
    int num = 20;
    cout << getBit(num, 3) << endl;
    cout << setBit(num, 3) << endl;
    cout << clearBit(num, 3) << endl;
    int number = 147;
    cout << clearBitMsThroughI(number, 2) << endl;
    return 0;
}