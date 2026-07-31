#include <iostream>
using namespace std;
int romanToBinarY(string s)
{
    int ans = 0;
    char roman[7] = {'M', 'D', 'C', 'L', 'X', 'I', 'V'};
    int arr[7] = {1000, 500, 100, 50, 10, 5, 1};
    int index = 2;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            
                if (s[i] == roman[j])
                {
                    ans = arr[j];
                    cout << "Start Ans : " << ans << endl;

                    for (int k = 0; k < s.length() - 1; k++)
                    {
                        if (s[i + 1] == roman[k])
                        {
                            index = k;
                            cout << "Value  at : " << index << " : " << s[i + 1] << endl;
                            cout << "True " << (index < j) << endl;
                            if (index < (j))
                            {
                                // "MCMXLIV"
                                cout << "before minus  : " << ans << endl;
                                cout << " Idex Value : " << arr[index] << endl;
                                cout << "Value at j or I " << arr[i + 1] << " j " << arr[j] << endl;
                                ans = ans - arr[j];
                                cout << "ans=ans-arr[j]; minus  : " << ans << endl;
                                
                                int temp = arr[index] -arr[j];
                                cout<<"Temp : "<<temp<<endl;
                                ans+=temp;
                                cout << "after Minus  : " << ans << endl;
                                break;
                            }
                        }
                    }
                }
            
        }
    }
    // cout<<"ans :"<<ans<<endl;
    return 0;
}
int main()
{
    cout << romanToBinarY("MCMXLIV");
    return 0;
}