#include <bits/stdc++.h>
using namespace std;
class NStack
{
public:
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;
    NStack(int N, int S)
    {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // top initialise
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // next initialise
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }
        // update last index value to -1
        next[s - 1] = -1;

        // initialise freespot
        freespot = 0;
    }

    bool push(int x, int m)
    {
        if (freespot == -1)
        {
            return false;
        }
        int index = freespot;
        arr[index] = x;
        freespot = next[index];
        next[index] = top[m - 1];
        top[m - 1] = index;
        return true;
    }
    int pop(int m)
    {
        if (top[m - 1] == -1)
        {
            return false;
        }
        int index = top[m - 1];
        top[m - 1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};
int main()
{
    NStack n(3, 6);
    cout << n.push(10, 1) << endl;
    cout << n.push(20, 0) << endl;
    cout << n.push(10, 100) << endl;
    cout << n.push(10, 30) << endl;
    cout << n.push(10, 320) << endl;

    return 0;
}