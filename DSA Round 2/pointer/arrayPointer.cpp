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
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;  // ptr points to the first element of the array

    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";  // Access elements using pointer arithmetic
    }
    cout << endl;
    int array[5] = {6, 7, 8, 9, 10};
    for(int i=0; i<5; i++) {
        cout << *(array + i) << " ";
    }
    cout << endl;

    return 0;
}