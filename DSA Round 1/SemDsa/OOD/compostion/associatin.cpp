#include <bits/stdc++.h>
using namespace std;
class student;
class course
{
    int courseNo;
    string name;
    vector<student *> stdArray;

public:
    course()
    {
    }
    void print();
    course(int courseNo, string name);
    void enrollStd(student *std1);

    void printCourseInformation();
};

class student
{
    int roolNo;
    string name;
    course* array[7];
    int arr;

public:
    student(string name, int rollNo);
    void enrollCourse(course *course);
    void printInfor();
    void print();
};
student::student(string name, int roolNo)
{
    this->name = name;
    this->roolNo = roolNo;
    arr = 0;
}
void student::enrollCourse(course *c)
{
    if (arr <= 7)
    {
        array[arr] = c;
    }
    arr++;
}
void student::printInfor()
{
    cout << "student Name : " << name << endl;
    cout << "Roll No : " << roolNo << endl;
    for (int i = 0; i < 7; i++)
    {
        array[i]->print();
    }
}
void student::print()
{
    cout << "Name  : " << name << endl;
    cout << "Roll No : " << roolNo << endl;
}
course::course(int courseNo, string name)
{
    this->courseNo = courseNo;
    this->name = name;
}
void course::enrollStd(student *std1)
{
    stdArray.push_back(std1);
}
void course::print()
{
    cout << "Name : " << name << endl;
    cout << "Roll No : " << courseNo << endl;
}
void course::printCourseInformation()
{
    cout << "Course Name : " << name << endl;
    cout << "Course No : " << courseNo << endl;
    for(int i=0;i<7;i++)
    {
       stdArray[i]->print();
    }
}

int main()
{
    // cout << "Hello World\n";
    course oop(12, "OOP");
    course dsa(13, "DSA");
    student *ali = new student("ali", 232);
    student *habib = new student("Habib", 323);
    oop.enrollStd(ali);
    oop.enrollStd(habib);
    ali->enrollCourse(&oop);
    // ali->enrollCourse(&oop);
    habib->enrollCourse(&oop);
    habib->enrollCourse(&dsa);
    habib->printInfor();

    return 0;
}
