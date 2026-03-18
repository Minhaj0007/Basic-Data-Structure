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

// Convert prefix to postfix
string prefixToPostfix(string s)
{

    stack<string> st;

    // Read from right to left
    for (int i = s.length() - 1; i >= 0; i--)
    {
        char c = s[i];

        // If operand → push
        if (isOperand(c))
        {
            st.push(string(1, c));
        }

        // If operator → pop two, form postfix
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string expr = op1 + op2 + c; // Postfix format

            st.push(expr);
        }
    }

    return st.top();
}

int main()
{
    string prefix;
    cin >> prefix;
    cout << "Postfix: " << prefixToPostfix(prefix);
    return 0;
}
