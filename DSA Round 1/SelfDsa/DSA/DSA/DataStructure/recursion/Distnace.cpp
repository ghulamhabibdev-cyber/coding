#include <bits/stdc++.h>
using namespace std;
void ReachHome(int src, int dest)
{
    if (src == dest)
    {
        cout << "Reahced ";
        return;
    }
    src++;
    cout<<"Src : "<<src<<endl;
    ReachHome(src, dest);
}
int main()
{
    ReachHome(10,50);
     return 0;
}