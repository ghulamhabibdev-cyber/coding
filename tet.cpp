#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string randomWord(int t)
{
    string word = "";

    for (int i = 0; i < t; i++)
    {
        char ch = 'a' + rand() % 26;
        word += ch;
    }

    return word;
}

int main()
{
    srand(time(0)); // seed for randomness

    int t;
    cin >> t;

    cout << randomWord(t) << endl;
}