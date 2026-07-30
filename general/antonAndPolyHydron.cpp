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
int totalFacesOfPolyHydrons(int n)
{
    unordered_map<string, int> mp;

    mp["Tetrahedron"] = 4;
    mp["Cube"] = 6;
    mp["Octahedron"] = 8;
    mp["Dodecahedron"] = 12;
    mp["Icosahedron"] = 20;
    int totalFaces = 0;
    for (int i = 0; i < n; i++)
    {
        string currentPolyHydron;
        cin >> currentPolyHydron;
        totalFaces += mp[currentPolyHydron];
    }
    return totalFaces;
}
int main()
{
    int n;
    cin >> n;
    int ans = totalFacesOfPolyHydrons(n);
    cout << ans << endl;
    return 0;
}