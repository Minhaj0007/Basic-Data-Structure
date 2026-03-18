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

// Insert at end
void insertAtEnd(Node *&head, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
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

// Reverse singly linked list iteratively
void reverseList(Node *&head)
{
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next; // store next node
        current->next = prev; // reverse link
        prev = current;       // move prev
        current = next;       // move current
    }

    head = prev; // update head
}

int main()
{
    Node *head = NULL;

    // Creating list: 10 -> 20 -> 30 -> 40
    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Original List:" << endl;
    display(head);

    // Reverse the list
    reverseList(head);

    cout << "Reversed List:" << endl;
    display(head);

    return 0;
}
