#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char c)
{
    return((c >= 'a' && c <= 'z')|| (c >= 'A' && c <= 'Z')|| (c >= '0' && c <= '9'));
}

int prec(char c)
{
    if(c == '^') return 3;
    else if(c == '/' || c == '*') return 2;
    else if(c == '+' || c == '-') return 1;
    else 
    return -1;
}

bool isRightAssociative(char c)
{
    return c == '^';
}
string InfixToPostfix(string &s)
{
    stack<char>st;
    string res;
    for(int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if(isOperand(c)) res += c;
        else if(c == '(') st.push(c);
        else if(c == ')')
        {
            while(!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while(!st.empty() && st.top() != '(' && (prec(st.top()) >= prec(c) && !isRightAssociative(c)))
            {
                res += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

int main()
{
    string exp;
    cout << "Enter infix Expression: " << endl;
    cin >> exp;
    cout << InfixToPostfix(exp) << endl;
}

