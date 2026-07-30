#include <iostream>
#include <vector>
using namespace std;

class A
{
};

int elephantTraval(int distance)
{
    int maxStep=5;
    int count=0;
    while(distance>0)
    {
        if(distance>=maxStep)
        {
            count++;
            distance-=maxStep;
        }
        else{
            maxStep--;
        }
    }
    return count;
}
int main()
{
    int distance;
    cin >> distance;
    int steps = elephantTraval(distance);
    cout<<steps<<endl;
    return 0;
}