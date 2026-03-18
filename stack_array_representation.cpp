#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int n; // size of array

public:
    // Constructor with default size 10
    Stack(int size = 10)
    {
        n = size;
        arr = new int[n];
        top = -1;
    }
    // Push
    void push(int x)
    {
        if (top == n - 1)
        {
            // “Is the top pointer at the last index of the array?”
            // If yes -> the stack is full
            // If no -> you can still push more elements.

            cout << "Stack Overflow" << endl;
            return; // IMPORTANT
        }
        top++;
        arr[top] = x;
    }
    // Pop
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return; // IMPORTANT
        }
        top--;
    }

    // Get top element
    int Top()
    {
        // the code after the if will never execute if the condition is true.
        // you don’t need an else because the return inside the if already exits the function.
        if (top == -1)
        {
            cout << "No element in stack." << endl;
            return -1;
        }
        return arr[top];
    }

    // Check if empty
    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    Stack st(5); // size = 5

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.Top() << endl; // prints 4
    st.pop();
    cout << st.Top() << endl;   // prints 3
    cout << st.empty() << endl; // prints 0
    return 0;
}
