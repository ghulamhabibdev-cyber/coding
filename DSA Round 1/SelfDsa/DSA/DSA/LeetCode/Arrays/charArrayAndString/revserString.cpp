#include <iostream>
using namespace std;
string reverseString(string name)
{
    int count = name.length();
    cout << count << endl;
    char temp[100] = {};
    int i = 0;
    // count=count-1;
    while (i < count)
    {
        temp[i] = name[count - 1 - i];

        i++;
        cout << count << endl;
    }
    temp[count] = '\0';
    return string(temp);
}
string reverse(char arr[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        char temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
    return arr;
}
int getLength(char arr[])
{
    int i = 0;
    int count = 0;
    while (arr[i] != 0)
    {
        count++;
        i++;
    }
    cout << count;
    cout << endl;
    return count;
}
string RevserString2(string arr)
{
    int s = 0;
    int end = arr.length();
    end = end - 1;
    while (s < end)
    {
        char temp = arr[s];
        arr[s] = arr[end];
        arr[end] = temp;
        s++;
        end--;
    }
    return arr;
}
char UperTolower(char a)
{
    if (a >= 65 && a <= 90)
    {
        // A:65 Z : 90 a : 97 z : 122 a->a
        a = a + ('a' - 'A');
    }

    return a;
}
bool Palindrome(string str)
{
    int s = 0;
    int e = str.length();
    e = e - 1;
    while (s <= e)
    {
        if (UperTolower(str[s]) != UperTolower(str[e]))
        {
            return 0;
        }
        else
        {
            return 1;
        }
        s++;
        e--;
    }
}

int main()
{
    cout << UperTolower('9');
    string name;
    cout<<"Enter name : \n";
    getline(cin,name);
    cout<<RevserString2(name);
    // string str="13331";
    // str.push_back('a');
    // cout<<Palindrome(str);
    //     string name="non";
    //  string temp=RevserString2(name);
    //  if(temp==name)
    //  {
    //     cout<<"True";
    //  }
    // string name;
    // string temp;
    // cout<<"Enter Name \n";
    // getline(cin,name);
    // cout<<name;
    // name=reverseString(name);
    // cout<<name;
    // if(name==temp)
    // {
    //     cout<<"Plandrome";
    // }
    // cout<<temp;
    // char name[20]="habib";
    // cout<<reverse(name,getLength(name));
    //     string names;
    //     cout<<"Enter Name : \n";
    //     getline(cin,names);
    //     string temp;
    //     temp=reverseString(names);
    //    cout<<"\n\n"<<temp<<"\n";
    //     if(temp==names)
    //     {
    //         cout<<"\nok";
    //     }
}