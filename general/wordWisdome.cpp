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
int highestQualityResponce(int repsonce)
{
    int maxi = INT_MIN;
    int rep=1;
    for (int i = 1; i <=repsonce; i++)
    {
        int numberOfword;
        int quality;
        cin >> numberOfword >> quality;
        if (quality > maxi && numberOfword <= 10)
        {
            maxi = quality;
            rep=i;
        }
    }
    return rep;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int responce;
        cin >> responce;
        int maxiQualityWord = highestQualityResponce(responce);
        cout << maxiQualityWord << endl;
    }
    return 0;
}