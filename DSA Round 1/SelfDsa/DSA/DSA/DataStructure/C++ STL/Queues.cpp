#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<bool> b;
    b.push(true);
    b.push(false);
    b.push(true);
    b.push(false);
    b.push(false);
    b.push(false);
    b.push(false);
    queue<bool> temp = b; // make a copy to preserve original

    while (!temp.empty())
    {
        cout << temp.front() << endl;
        temp.pop();
    }
}