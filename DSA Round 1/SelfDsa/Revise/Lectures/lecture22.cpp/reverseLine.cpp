#include <iostream>
using namespace std;
void reverseWord(string &word)
{
    int s = 0;
    int e = word.length() - 1;
    while (s < e)
    {
        swap(word[s], word[e]);
        s++;
        e--;
    }
}
int main()
{
    string text = "Ali is My Name";
    string ans = "";
    int i=0;
   while(i<text.length())
    {
        string wordy = "";
        while( i < text.length() && text[i] != ' ')
        {
            wordy += text[i];
            i++;
        }
        reverseWord(wordy);

        ans += wordy + " ";
        i++;
    }
    cout << ans << endl;
    return 0;
}
