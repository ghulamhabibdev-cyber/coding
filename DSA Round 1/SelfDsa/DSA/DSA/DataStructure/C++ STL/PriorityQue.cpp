#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int> maxi;
    maxi.push(1);
    maxi.push(43);
    maxi.push(34);
    maxi.push(5);
    maxi.push(134);
    maxi.push(1);
    cout<<maxi.top();
    cout<<endl;
    priority_queue<int,vector<int>,greater<int>> mini;
    mini.push(-1);
    mini.push(-2323);
    cout<<mini.top();
}