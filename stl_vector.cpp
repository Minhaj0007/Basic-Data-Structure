#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;

    s.push(10);
    cout << "10 pushed." << endl;

    s.push(20);
    cout << "20 pushed." << endl;

    s.push(30);
    cout << "30 pushed." << endl;

    
    if (!s.empty())
        cout << "Top element: " << s.top() << endl;
    else
        cout << "Stack is empty." << endl;

    
    if (s.empty()) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements: ";
        stack<int> temp = s; 
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    if (!s.empty()) {
        cout << s.top() << " popped." << endl;
        s.pop();
    } else {
        cout << "Stack Underflow!" << endl;
    }


    if (!s.empty())
        cout << "Top element: " << s.top() << endl;
    else
        cout << "Stack is empty." << endl;

    if (s.empty())
        cout << "Stack is EMPTY." << endl;
    else
        cout << "Stack is NOT empty." << endl;

    return 0;
}
