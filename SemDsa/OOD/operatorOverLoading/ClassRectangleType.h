#include <bits/stdc++.h>
#ifndef H_rec
#define H_rec
using namespace std;
class rectangleType
{
private:
    double length;
    double width;
    friend void CreatRandDataObj();

public:
    rectangleType(double len = 0, double wid = 0);
    void setDimention(double len, double width);
    double calculateArea();
    void printDimention();
    rectangleType operator+(const rectangleType &rec);
    rectangleType operator-(const rectangleType &rec);
    rectangleType operator*(const rectangleType &rec);
    rectangleType operator/(const rectangleType &rec);
    bool operator==(const rectangleType &rec);
    bool operator!=(const rectangleType &rec);
    bool operator>(const rectangleType &rec);
    bool operator<(const rectangleType &rec);
    bool operator>=(const rectangleType &rec);
    bool operator<=(const rectangleType &rec);
    friend ostream &operator<<(ostream &osObject, rectangleType &rec);
    friend iostream &operator>>(iostream &osObject, rectangleType &rec);
};
rectangleType rectangleType::operator+(const rectangleType &rec)
{
    rectangleType temp;
    temp.length = length + rec.length;
    temp.width = width + rec.width;
    return temp;
}

rectangleType rectangleType::operator-(const rectangleType &rec)
{

    rectangleType temp;
    temp.length = length - rec.length;
    temp.width = width - rec.width;
    return temp;
}

rectangleType rectangleType::operator*(const rectangleType &rec)
{
    rectangleType temp;
    temp.length = length * rec.length;
    temp.width = width * rec.width;
    return temp;
}
rectangleType rectangleType::operator/(const rectangleType &rec)
{
    rectangleType temp;
    temp.length = (rec.length != 0) ? length / rec.length : 0;
    temp.width  = (rec.width  != 0) ? width  / rec.width  : 0;
    return temp;
}
bool rectangleType:: operator==(const rectangleType &rec)
{
    if(length==rec.length &&width==rec.width)
    {
        return true;
    }
    return false;
}

bool rectangleType:: operator!=(const rectangleType &rec)
{
    return !(*this==rec);
}
bool rectangleType::operator>(const rectangleType &rec)
{
    if(length>rec.length&&width>rec.width)
    {
        return true;
    }
    return false;
}
bool rectangleType:: operator<(const rectangleType &rec)
{
    return (length < rec.length && width < rec.width);
}
bool rectangleType::operator>=(const rectangleType &rec)
{
    if(length>=rec.length&&width>=rec.width)
    {
        return true;
    }
    return false;

}
bool rectangleType::operator<=(const rectangleType &rec)
{
    return (length <= rec.length && width <= rec.width);
}
ostream &operator<<(ostream &osObject, rectangleType &rec)
{
    osObject<<"Lenght : "<<rec.length<<endl;
    osObject<<"Width  : "<<rec.width<<endl;
    return osObject;
}
iostream &operator>>(iostream &isObject, rectangleType &rec)
{
    isObject>>rec.length>>rec.width;
}
rectangleType rectangleType::operator+(const rectangleType &oper)
{
    rectangleType temp;
    temp.length = length + oper.length;
    temp.width = width + oper.width;
    return temp;
}
void rectangleType::setDimention(double len, double width)
{
    this->length = len;
    this->width=width;
}
double rectangleType::calculateArea()
{
    return (length * width);
}
void rectangleType::printDimention()
{
    cout << "Length : " << this->length << endl;
    cout << "Width  : " << this->width << endl;
}
rectangleType::rectangleType(double l = 0, double w = 0)
{
    this->length = l;
    this->width = w;
}

#endif
