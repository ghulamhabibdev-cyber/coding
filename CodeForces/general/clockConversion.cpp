#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>
#include <list>
#include <cstdlib>
#include <string>
using namespace std;

class A
{
};
string clockConversion(string _24FormatTime)
{
    unordered_map<int, int> clockConvertor;
    clockConvertor[0] = 12;
    for (int i = 1; i <= 12; i++)
    {
        clockConvertor[i] = i;
    }
    int upperHour = 13;
    for (int i = 1; i <=11; i++)
    {
        clockConvertor[upperHour] = i;
        upperHour += 1;
    }
    string hour = _24FormatTime.substr(0, 2);
    int n = hour.length();
    int index = 0;
    int hours = 0;
    string mintes = _24FormatTime.substr(3, 3);
    while (index < n)
    {
        int currHourDigt = hour[index] - '0';
        hours = hours * 10 + currHourDigt;
        index++;
    }
    string _12FormatTime = "";

    string stry = to_string(clockConvertor[hours]);
    int hourLen=stry.length();
    if(hourLen<2)
    {
        _12FormatTime+="0";
    }
    string newHour = to_string(clockConvertor[hours]);
    newHour += ":";
    _12FormatTime += newHour;
    _12FormatTime += mintes;
    if (hours >= 12)
    {
        _12FormatTime += " PM";
    }
    else
    {
        _12FormatTime += " AM";
    }
    return _12FormatTime;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string _24FomatTime;
        cin >> _24FomatTime;
        // cout<<endl;
        // cout<<endl;
        // cout<<"24 Hour Format : "<<_24FomatTime<<endl;
        string _12FormatTime = clockConversion(_24FomatTime);
        cout << _12FormatTime << endl;
    }

    return 0;
}