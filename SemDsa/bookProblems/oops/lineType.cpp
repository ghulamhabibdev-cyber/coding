#include <bits/stdc++.h>
using namespace std;
class line
{
    double a;
    double b;
    double x;
    double y;
    char lineType;
    double slope;
public:
    line(double a, double b, double x, double y);
    double Findslope();
    bool isEqualLines();
    bool isParrallel();
    double pointIntersection();
    bool operator=(line &ln);
    friend bool isParrallel(line &ln1, line &ln2);
    friend bool perpendicular(line &ln1, line &ln2);
};
line::line(double a, double b, double x, double y)
{
    if (x == 0 && y == 0)
    {
        cout << "Both Can not Be Zero\n";
        cout << "data set to 1 are set 1\n";
        a = 1;
        b = 1;
        x = 1;
        y = 1;
    }
    else
    {
        this->x = x;
        this->y = y;
        this->a = a;
        this->b = b;
        if (b == 0)
        {
            lineType = 'V';
            slope = 1;
        }
        else if (a == 0)
        {
            lineType = 'H';
            slope = 0;
        }
        else
        {
            slope = (-a / b);
        }
    }
}
double line::Findslope()
{
    return slope;
}
int main()
{
    line line1(32, 23, 5, 4);
    cout << line1.Findslope() << endl;
    return 0;
}
