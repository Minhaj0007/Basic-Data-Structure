#include <iostream>
#include <stack>
using namespace std;

// Check operand
bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

// Convert postfix to prefix
string postfixToPrefix(string s)
{

    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // Operand → push as string
        if (isOperand(c))
        {
            st.push(string(1, c));
        }
        else
        {
            // Operator → pop two operands
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            // Prefix = operator + op1 + op2
            string expr = c + op1 + op2;

            st.push(expr);
        }
    }

    return st.top();
}

int main()
{
    string postfix;
    cin >> postfix;
    cout << "Prefix: " << postfixToPrefix(postfix);
    return 0;
}
