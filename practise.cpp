#include<iostream>
using namespace std;

class stack
{
    int n;
    int top;
    int* arr;
    public:
    stack(int size)
    {
        n = size;
        arr = new int[n];
        top = -1;
    }
    void push(int x)
    {
        if(top == n - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop()
    {
        if(top == -1)
        {
            cout << "No Element to pop" << endl;
            return;
        }
        top--;
    }
    int Top()
    {
        if(top == -1)
        {
            cout << "No element in the Stack" << endl;
            return -1;
        }
        return arr[top];
    }
    bool empty()
    {
        return top = -1;
    }
};
int main()
{
    stack st(5);
    st.push(4);
    st.push(52);
    st.push(1);
    st.push(9);
    st.push(2);

    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    cout << st.empty() << endl;
    return 0;
}
