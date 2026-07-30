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

class A
{
};

int main()
{
    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int rating;
        cin >> rating;
        if (rating <= 1399)
        {
            cout << "Division 4" << endl;
        }
        else if(rating>=1400&&rating<=1599)
        {
            cout << "Division 3" << endl;
        }
        else if(rating>=1600&&rating<=1899)
        {
            cout << "Division 2"<<endl;
        }
        else{
            cout << "Division 1" << endl;
        }
    }
    // For Division 1 : 1900≤rating
    //  For Division 2 : 1600≤rating≤1899
    //  For Division 3 : 1400≤rating≤1599
    //   For Division 4 : rating≤1399
    return 0;
}