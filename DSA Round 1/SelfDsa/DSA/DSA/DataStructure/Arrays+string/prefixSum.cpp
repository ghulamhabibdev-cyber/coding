#include <iostream>
using namespace std;

int main() {
    int arr[] = {3, 1, 4, 2, 5};
    int n = 5;
    int prefix[n];
    
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
        cout<<prefix[i]<<endl;
    }

    int l = 1, r = 4; // Want sum from index 1 to 3
    int rangeSum = prefix[r] - (l > 0 ? prefix[l - 1] : 0);
    
    cout << "Sum from index " << l << " to " << r << " is " << rangeSum << endl;
}
