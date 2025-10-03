#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
void Decorator()
{
    cout << "<\n================================================================================================\n>";
}
void SortDataSet(int arr[], int len)
{

    cout << "Size is " << len << endl;
    int temp;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << "\t";
    }
}
double MeanOfDataSet(int arr[], int len)
{
    float sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += arr[i];
    }
    double mean = sum / len;
    return mean;
}
int* returnDataSetFequency(int arr[])
{
    return 0;
}
void FrequencyOfdataElements()
{

}
void CommulativeFrequency()
{
    int dataSet[5]={3,4,5,6,7};
    int commulativeFre[5];
    for(int i=0;i<5;i++)
    {
        if(i=0)
        {
            commulativeFre[i]=dataSet[i];

        }
        else{
            commulativeFre[i]=dataSet[i-1]+dataSet[i];
        }


    }
    for(int i=0;i<5;i++)
    {
        cout<<"\t"<<commulativeFre[i];

    }
}
int main()
{
    // int arr[5] = {12, 34, 54, 45, 34};
    // float len = sizeof(arr) / sizeof(arr[0]);
    // Decorator();
    // SortDataSet(arr, len);
    // Decorator();
    // cout << endl;
    // for (int num : arr)
    // {
    //     cout << num << "\t";
    // }
    // Decorator();
    //  Decorator();
    // double mean = MeanOfDataSet(arr, len);
    // Decorator();
    // cout<<"Mean : "<<mean<<endl;
    CommulativeFrequency();
}
