#include <iostream>
#include <vector>
using namespace std;

class A
{
};
int getSize(vector<int> arr)
{
    return arr.size();
}
int oddNumberCount(vector<int> arr)
{
    int n = getSize(arr);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 != 0)
        {
            count++;
        }
    }
    return count;
}
int evenNumberCount(vector<int> arr)
{
    int n = getSize(arr);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}
int subArrayCount(vector<int> arr, int a, int b)
{
    int evenCount = evenNumberCount(arr);
    int oddCount = oddNumberCount(arr);
    if (oddCount == 0)
    {
        return 0;
    }

    int x = 0;
    int count = 0;
    // int y = 1;
    for (int i = 0; i < evenCount; i++)
    {
        int y = 1;
        while (x / y <= a / b && y <= oddCount)
        {
            y++;
            count++;
        }
        x++;
        // y++;
    }
    x = 0;
    int y = 1;
    for (int i = 0; i < oddCount; i++)
    {
        int x = 1;
        while (x / y <= a / b && x <= evenCount)
        {
            x++;
            count++;
        }
        y++;
    }
    return count;
}
int main()
{
    vector<int> arr = {1, 2, 2, 1};

    int ans = subArrayCount(arr, 3, 2);
    cout << "Sub Arry count : " << ans << endl;
    return 0;
}