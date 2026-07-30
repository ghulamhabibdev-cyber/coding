#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
#include <cstdlib>
#include <ctime>
#include <unordered_set>
using namespace std;

class A
{
};

int main()
{
    // int n;
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     int a, b;
    //     cin >> a >> b;
    //     int count = abs(a - b);
    //     count = (count + 9) / 10;
    //     cout << count << endl;
    // }
    unordered_set<int> st;
    st.insert(40);
    // cut << st.

    srand(time(NULL)); // once only

    for (int i = 0; i < 5; i++)
    {
        cout << rand() << "\n";
    }
    cout << (4 % 1) << endl;
    return 0;
}