#include <iostream>
using namespace std;
void FinalGradeReport(double assinment, double quizzes, double finaMarks)
{
    double result;
    int assingmentTotalMarks = 40;
    int quzziezTotalMarks = 20;
    int endtermMarks = 40;
    result = ((assinment / assingmentTotalMarks) * 40) + ((quizzes / quzziezTotalMarks) * 20) + ((finaMarks / endtermMarks) * 40);
    cout<<"Total Marks : "<<result<<endl;
    if (result < 50)
    {
        cout << "F";
    }
    else if (result < 60)
    {
        cout << "E";
    }
    else if (result < 70)
    {
        cout << "D";
    }
    else if (result < 80)
    {
        cout << "C";
    }

    else if (result < 85)
    {
        cout << "B";
    }
    else
    {
        cout << "A+";
    }
}
int main()
{
    double assingmentMark,quzizes,finalMark;
    cout<<"Enter Assingment Marks : "<<endl;
    cin>>assingmentMark;
    cout<<"Enter Quizzes Marks : "<<endl;
    cin>>quzizes;
    cout<<"Enter Final Mark : "<<endl;
    cin>>finalMark;

    FinalGradeReport(assingmentMark, quzizes, finalMark);
    return 0;
}