#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Insert at beginning
void insertAtBeginning(Node *&head, int value)
{
    Node *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    { // Empty list
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at any position (1-based index)
void insertAtPosition(Node *&head, int pos, int value)
{
    if (pos == 1)
    {
        insertAtBeginning(head, value);
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

    Node *newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Display list
void display(Node *head)
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
    Node *head = NULL;
    int n, pos;

    // Insert nodes
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    cout << "Initial list:" << endl;
    display(head);

    // Insert at beginning
    insertAtBeginning(head, 5);
    cout << "After inserting 5 at beginning:" << endl;
    display(head);

    // Insert at end
    insertAtEnd(head, 40);
    cout << "After inserting 40 at end:" << endl;
    display(head);

    // Insert at position
    pos = 3;
    insertAtPosition(head, pos, 25);
    cout << "After inserting 25 at position " << pos << ":" << endl;
    display(head);

    return 0;
}
