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
class Str
{
    int cap = 1;
    char *arr = new char[cap];
    int index = 0;

public:
    void Add(char ch)
    {
        if (index < cap)
        {
            arr[index++] = ch;
            return;
        }
        cap *= 2;
        char *chArr = new char[cap];
        for (int i = 0; i < index; i++)
        {
            chArr[i] = arr[i];
        }
        delete arr;
        arr = chArr;
        chArr[index++] = ch;
    }
    char charAt(int n)
    {
        if (n >= 0 && n < index)
        {
            return arr[n];
        }
        else
        {
            return '-';
            ;
        }
    }
    char pop()
    {
        if (index > 0)
        {
            return arr[index--];
        }
    }
    Str subString(int st, int range)
    {
        Str temp;
        for (int i = st; (i <=range && range < index); i++)
        {
            cout << "in log";
            temp.Add(arr[i]);
        }
        return temp;
    }

    void print()
    {
        for (int i = 0; i < index; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }

public:
};
int main()
{
    Str str;
    str.Add('h');
    str.Add('a');
    str.Add('b');
    str.Add('i');
    str.Add('b');
    str.print();
    Str temp = str.subString(1, 3);
    cout << "===\n";
    temp.print();

    return 0;
}