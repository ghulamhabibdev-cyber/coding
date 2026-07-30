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

class numberRest
{

    int a;
    int b;
    int c;
    int ab;
    int ac;
    int bc;
    int abc;

public:
    numberRest()
    {
        this->a = 0;
        this->b = 0;
        this->c = 0;
        this->ab = 0;
        this->ac = 0;
        this->bc = 0;
        this->abc = 0;
    }
    void getNumber(int ab, int ac, int bc, int abc)
    {
        this->ab = ab;
        this->ac = ac;
        this->bc = bc;
        this->abc = abc;
    }

    void restoreMethod()
    {
        this->b = abc - ac;
        this->a = ab - b;
        this->c = ac - a;
    }
    void print()
    {
        cout << a << " " << b << " " << c << endl;
    }
};
class solution
{
public:
    void restoreNumber(int ab, int ac, int bc, int abc)
    {
        numberRest n = numberRest();
        n.getNumber(ab, ac, bc, abc);
        n.restoreMethod();
        n.print();
    }
};
void solutionFun(int x, int x2, int x3, int x4)
{
    vector<int> arr;
    arr.push_back(x);
    arr.push_back(x2);
    arr.push_back(x3);
    arr.push_back(x4);
    sort(arr.begin(), arr.end());
    int abc = arr[3];
    int a = abc - arr[0];
    int b = arr[1] - a;
    int c = arr[0] - b;
    cout << a << " " << b << " " << c << endl
         << endl;
}
int main()
{
    int ab;
    int ac;
    int bc;
    int abc;
    cin >> ab >> ac >> bc >> abc;
    solutionFun(ab, ac, bc, abc);
    //     solution sol = solution();
    // sol.restoreNumber(ab, ac, bc, abc);

    return 0;
}