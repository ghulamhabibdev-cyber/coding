#include <bits/stdc++.h>
using namespace std;
class romanClass
{
    unordered_map<char, int> mp;
    int decimal;
    string roman;
    // void convertDecimalToRoman(int romanNumber);
public:
    void convertRomanTodecimal(string number);
    void convertDecimalToRoman(int number);
    romanClass();

};
void romanClass::convertRomanTodecimal(string number)
{
    int ans = 0;
    int prev=0;
    for (int i = number.length() - 1; i >= 0; i--)
    {
        int ch=mp[number[i]];
        if(ch<prev)
        {
            ans-=ch;
        }
        else{
            ans+=ch;
        }
        prev=ch;
    }
    cout << "Ans  : " << ans << endl;
}
romanClass::romanClass()
{
    mp['M'] = 1000;
    mp['D'] = 500;
    mp['C'] = 100;
    mp['L'] = 50;
    mp['X'] = 10;
    mp['V'] = 5;
    mp['I'] = 1;
    decimal = 0;
    roman = "";
}

int main()
{
    romanClass r;
    r.convertRomanTodecimal("III");

    // cout << "Hello World\n";

    return 0;
}
