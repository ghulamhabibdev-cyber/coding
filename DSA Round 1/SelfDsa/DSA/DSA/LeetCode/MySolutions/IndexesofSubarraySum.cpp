#include <iostream>
using namespace std;
pair<int, int> SubarraySum(int arr[], int size, int target)
{
    int sum = 0;
    int end = -1;
    bool endbreak = false;
    int start = -1;
    pair<int, int> indexes;
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            // int arr[5] = {1, 2, 3, 7, 5};

            sum += arr[j];
            if (sum == target)
            {
                end = j + 1;
                endbreak = true;
                break;
            }
        }
        sum = 0;
        if (endbreak)
        {

            if (i == 0)
            {
                i+= 1;
            }
            indexes.first = i;
            indexes.second = end;
            break;
        }
    }
    return indexes;
}
int main()
{
    int arr[5] = {1, 2, 3, 7, 5};
    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    pair<int, int> p = SubarraySum(arr2, 5, 12);
    cout << p.first << "\t" << p.second << endl;
}