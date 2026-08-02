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
    rectangleType()
    {

    }
    rectangleType(double len , double wid );
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
    friend istream &operator>>(istream &osObject, rectangleType &rec);
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
istream &operator>>(istream &isObject, rectangleType &rec)
{
    isObject>>rec.length>>rec.width;
    return isObject;
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
rectangleType::rectangleType(double l , double w )
{
    this->length = l;
    this->width = w;
}

#endif
