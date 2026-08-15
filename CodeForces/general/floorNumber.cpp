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
int floorNumber(int roomNo, int noAppart)
{
    if (roomNo <= 2)
        return 1;
    int count = 1;
    int room = 2;
    while (room < roomNo)
    {
        room += noAppart;
        count++;
    }

    return count;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int roomNo, noAppart;
        cin >> roomNo >> noAppart;
        int floorNo = floorNumber(roomNo, noAppart);
        cout << floorNo << endl;
    }

    return 0;
}