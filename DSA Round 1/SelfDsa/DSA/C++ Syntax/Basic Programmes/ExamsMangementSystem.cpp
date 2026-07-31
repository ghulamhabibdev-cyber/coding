#include <iostream>
using namespace std;
void ExamManagement()
{

    int MarkArr[7];
    double average;
    double totalMarks = 0;
    int size = sizeof(MarkArr) / sizeof(MarkArr[0]);
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Marks For Subject : " << i+1 << " : " << endl;
        cin >> MarkArr[i];
        totalMarks += MarkArr[i];
    }
    cout << "Total Marks : " << totalMarks << endl;
    average = totalMarks / size;
    cout << "Average Marks : " << average << endl;
}
int main()
{

    ExamManagement();
}