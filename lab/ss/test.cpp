//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pri(char op)
    {
        if (op == '[' || op == '{' || op == '(')
            return 0;
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        if (op == '^')
            return 3;
        return -1;
    }

    string infixToPostfix(string s)
    {
        string ans = "";
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if ((47 < ch and ch <= 57))
            {
                ans += ch;
            }
            else if (ch == '(')
            {
                st.push(ch);
            }
            else if (ch == ')')
            {
                while (st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() and (pri(st.top()) >= pri(ch)))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};

int main()
{
    string ans;
    cin >> ans;
    Solution ob;
    string exp = ob.infixToPostfix(ans);
    stack<int> s;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] > 47 && exp[i] <= 57)
        {
            s.push(exp[i] - '0');
        }
        else
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            switch (exp[i])
            {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                s.push(a / b);
                break;
            }
        }
    }
    cout<<s.top()<<endl;

    return 0;
}
