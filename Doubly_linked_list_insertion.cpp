#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

Node *head = NULL;
Node *tail = NULL;

void InsertAtBeginning(Node *&head, Node *&tail, int value)
{
    Node *newnode = new Node(value);

    if (head == NULL)
    {
        head = tail = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void InsertAtEnd(Node *&head, Node *&tail, int value)
{
    Node *newnode = new Node(value);

    if (head == NULL)
    {
        head = tail = newnode;
        return;
    }

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void InsertAtAnyPosition(Node *&head, Node *&tail, int pos, int value)
{
    if (pos == 1)
    {
        InsertAtBeginning(head, tail, value);
        return;
    }

    Node *temp = head;
    int i = 1;

    while (i < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        cout << "Position out of range!" << endl;
        return;
    }

    if (temp == tail)
    {
        InsertAtEnd(head, tail, value);
        return;
    }

    Node *newnode = new Node(value);

    newnode->next = temp->next;
    newnode->prev = temp;

    temp->next->prev = newnode;
    temp->next = newnode;
}

void traversal(Node *head)
{
    Node *temp = head;
    cout << "List: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int n;

    cout << "Enter values (-1 to stop):" << endl;
    while (true)
    {
        cin >> n;
        if (n == -1)
            break;
        InsertAtEnd(head, tail, n);
    }

    cout << "\nInitial values:" << endl;
    traversal(head);

    cout << "Insert value at beginning: ";
    cin >> n;
    InsertAtBeginning(head, tail, n);
    traversal(head);

    int pos;
    cout << "Enter position and value to insert: ";
    cin >> pos >> n;

    InsertAtAnyPosition(head, tail, pos, n);

    cout << "After Insertion at Position " << pos << ":" << endl;
    traversal(head);

    return 0;
}
