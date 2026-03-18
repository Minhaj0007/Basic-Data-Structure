#include <iostream>
#include <stack>
using namespace std;

// Check if character is operand
bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

string postfixToInfix(string s)
{
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // Operand → push
        if (isOperand(c))
        {
            st.push(string(1, c));
        }

        // Operator
        else
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        }
    }

    return st.top();
}

int main()
{
    string postfix;
    cin >> postfix;
    cout << "Infix: " << postfixToInfix(postfix);
    return 0;
}
