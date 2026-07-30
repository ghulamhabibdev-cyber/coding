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
int codeBestPerformance(int n)
{

    int score;
    cin >> score;
    int best = score;
    int worst = score;
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> score;
        if (score > best)
        {
            count++;
            best = score;
        }
        else if (score < worst)
        {
            worst = score;
            count++;
        }
    }

    return count;
}
int main()
{
    int n;
    cin >> n;
    int coderBestPerformance = codeBestPerformance(n);
    cout << coderBestPerformance << endl;

    return 0;
}