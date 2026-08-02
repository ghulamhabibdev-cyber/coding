#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<string> v;
    v.push("ahbib");
    v.push("ali");
    v.push("Ayesha");
    // for(string x:v)
    // {
    //     cout<<x<<endl;
    // }
     while (!v.empty()) {
        cout << v.top() << endl;  // Access top
        v.pop();                  // Remove top
    }
    cout<<v.top();
}