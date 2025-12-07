#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool checkLowerOrEqualOrder(char ch, char top)
{
    char orderArray[5] = {'%', '/', '*', '+', '-'};
    int index = 0;
    int topIndex = 0;
    for (int i = 0; i < 5; i++)
    {
        if (ch == orderArray[i])
        {
            index = i;
        }
        if (top == orderArray[i])
        {
            topIndex = i;
        }
    }
    return index >= topIndex;
}
string infixToPostFix(string str)
{
    stack<char> st;
    stack<int>st2;
    stack<bool>st3;
    // char orderArray[5] = {'%', '/', '*', '+', '-'};
    int i = 0;
    int len = str.length();
    string ans = "";
    while (i < len)
    {
      string f=  "(1+2)*(3+5)";
        char ch = str[i];
        ch='*';
        i++;
        if (ch >= '0' && ch <= '9')
        {
            ans.push_back(ch);
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (st.top() != '(')
            {

                ans.push_back(st.top());
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && st.top() != '(' && checkLowerOrEqualOrder(ch, st.top()))
            {
                ans.push_back(st.top());
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int solve(int num1, int num2, char op)
{
    if (op == '+')
    {
        return num1 + num2;
    }
    else if (op == '-')
    {
        return num1 - num2;
    }
    else if (op == '*')
    {
        return num1 * num2;
    }
    else
    {
        return num1 / num2;
    }
}
int evalPostfix(string str)
{
    int ans = 0;
    stack<int> st;
    if (str.empty())
    {
        return ans;
    }
    else
    {
        int i = 0;
        int len = str.length();
        while (i < len)
        {
            char ch = str[i];
            i++;
            if (ch >= '0' && ch <= '9')
            {
                int digit = ch - '0';
                st.push(digit);
            }
            else
            {

                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                int res = solve(op1, op2, ch);
                st.push(res);
            }
        }
    }
    return st.top();
}
string decimalToBinary(int number)
{
    string ans = "";
    stack<int> st;
    while (number != 0)
    {
        int digit = number % 2;
        st.push(digit);
        number /= 2;
    }
    while (!st.empty())
    {
        char ch = st.top() + '0';
        ans.push_back(ch);
        st.pop();
    }
    return ans;
}
bool isBalance(string str)
{
    stack<char> st;
    int i = 0;
    int len = str.length();
    while (i != len)
    {
        char ch = str[i];
        i++;
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else{
            if(st.empty())
            {
                return false;
            }
            char top=st.top();
            if ((top == '(' && ch == ')') || (top == '{' && ch == '}')||(top=='['&& ch==']'))
            {
                st.pop();
            }
            else{
                return false;
            }
        }

    }

    return st.empty();
}
int main()
{
    cout<<"===============> infix  notation to Postfix notatoin <=======================  \n";
    string str;
    cout<<"Enter You Notation \n";
    getline(cin, str);
    string postFix = "(1+2)+(4+5)";
    string postfix = infixToPostFix(str);
    cout<<"==========================>Evaluating the postfix <==================\n";
    cout << "Result: " << evalPostfix(postfix) << endl;
    int number;
    cout<<"Enter a Decimal A number \n";
    cin>>number;
    cout << "Binary : " << decimalToBinary(number) << endl;
    string str1="[{({()})}]";
    if(isBalance(str1))
    {
        cout<<"It balance pair of Brackets \n";
    }else{
        cout<<"Not Balance \n";
    }
    return 0;
}
