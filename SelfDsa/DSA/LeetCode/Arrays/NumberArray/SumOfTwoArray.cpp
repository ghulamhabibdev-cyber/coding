#include <iostream>
#include <vector>
using namespace std;
int sumOfTwoArray(vector<int> v1, vector<int> v2)
{
    int ten = 1;
    int number1 = 0;
    int number2 = 0;
    for (int i = 0; i <v1.size(); i++)
    {
        number1 = number1 * ten + v1[i];
        ten=10;
    }
    ten=1;
    for (int i = 0; i <v2.size(); i++)
    {
        number2=number2*ten+v2[i];
        ten=10;
    }
    return (number1+number2);
}
int main()
{
    vector<int> v1={0,0};
    vector<int> v2={9,9};
    cout<<sumOfTwoArray(v1,v2);
}
