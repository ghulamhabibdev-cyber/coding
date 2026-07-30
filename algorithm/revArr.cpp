#include <iostream>
#include<vector>
using namespace std;

class A {
};
void reverseArray(vector<int>& arr) {
    int n=arr.size();
    for(int i=0;i<n/2;i++)
    {
        int other=arr[n-i-1];
        int curr=arr[i];
       int temp=curr;
        arr[i]=other;
        arr[n-i-1]=temp;
    }
}
void print(string world)
{
    cout<<"Print Hellow World ";
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    reverseArray(arr);
    for (int x : arr) {
        cout << x << " ";
    }
    for(int i=0;i<30;i++)
    {
        print("hello world");
    }
    return 0;
}