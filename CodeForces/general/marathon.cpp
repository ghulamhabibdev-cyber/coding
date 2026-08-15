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

class A {
};

int main() {
    int n;
    cin>>n;
    int temur;
   
   
    for(int i=0;i<n;i++)
    {
        cin >> temur;
        int count = 0;
        for(int i=0;i<3;i++)
        {
            int distance;

            cin >> distance;
            if (temur < distance)
            {
                count++;
            }
        }
        cout<<count<<endl;
        
    }
    return 0;
}