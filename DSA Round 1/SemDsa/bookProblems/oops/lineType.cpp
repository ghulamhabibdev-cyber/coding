#include <bits/stdc++.h>
using namespace std;
class line
{
    double a;
    double b;
    double x;
    double y;
    double c;
    char lineType;
    double slope;

public:
    line(double a, double b, double x, double y);
    double Findslope();
    double pointIntersection();
    bool operator==(line &ln);
    static bool isParrallel(line &ln1, line &ln2);
    static bool isPerpendicular(line &ln1, line &ln2);
};
bool line::isParrallel(line &ln1, line &ln2)
{
    if (ln1.lineType == 'V' && ln2.lineType == 'V')
        return true;
    return false;
}
bool line::isPerpendicular(line &ln1,line &ln2)
{
    if((ln1.lineType=='V'||ln2.lineType=='H')||(ln1.lineType=='H'||ln2.lineType=='V'))
    {
        return true;
    }
    return false;
}
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
        this->c = (a * x) + (b * y);
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
