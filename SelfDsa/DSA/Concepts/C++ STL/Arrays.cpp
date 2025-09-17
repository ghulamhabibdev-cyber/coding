#include <iostream>
#include <array>
using namespace std;
int main()
{
    int basic[3] = {1, 2, 4};
    array<int, 5> arr = {1, 2, 45, 6, 4};
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << "\t";
    }

    cout << endl;

    cout << arr.at(3);
    cout << endl;
    cout << arr.empty();
    cout << endl;
    cout << arr.front();
    cout << endl;
    cout << arr.back();
    cout << endl;
}