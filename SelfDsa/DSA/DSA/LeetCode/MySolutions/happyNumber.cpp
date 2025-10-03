#include <bits/stdc++.h>
using namespace std;
int digitSqure(int num)
{
    int sum = 0;
    while (num != 0)
    {
        int digit = num % 10;
        sum += (digit * digit);

        num = num / 10;
    }

    return sum;
}

bool happnumber(int num)
{

    int temp = num;
    vector<int> v;
    int count = 0;
    bool found=false;
    while (num != 1)
    {
        num = digitSqure(num);
        v.push_back(num);
        temp=num;
        count++;
        if (count > 4)
        {
            for (int i = 0; i < v.size(); i++)
            {
                if(temp==v[i])
                {
                    found=true;
                    break;
                }

            }
        }
        if(found==true)
        {
            break;
        }
    }

    if (num == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    cout << "True : " << happnumber(536) << endl;
    //   cout<<digitSqure(19);
    return 2;
}