#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

   int ** arr=new int*[rows];
   for(int i=0;i<cols;i++)
   {
    arr[i]=new int[cols];
   }

    // Step 3: Input data
    cout << "Enter elements:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> arr[i][j];

    // Step 4: Display data
    cout << "2D Array:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    // Step 5: Free memory
    for (int i = 0; i < rows; ++i)
        delete[] arr[i];
    delete[] arr;

    return 0;
}
