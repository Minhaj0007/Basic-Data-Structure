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

// Function to convert prefix to infix
string prefixToInfix(string s)
{

    stack<string> st;

    // Scan from right to left
    for (int i = s.length() - 1; i >= 0; i--)
    {
        char c = s[i];

        // Operand → push as string
        if (isOperand(c))
        {
            st.push(string(1, c));
        }
        // Operator
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            string expr = "(" + op1 + c + op2 + ")";
            st.push(expr);
        }
    }

    return st.top();
}

int main()
{
    string prefix;
    cin >> prefix;
    cout << "Infix: " << prefixToInfix(prefix);
    return 0;
}
