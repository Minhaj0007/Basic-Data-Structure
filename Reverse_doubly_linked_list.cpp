#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

// Insert at end
void insertAtEnd(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// Display list forward
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

// Reverse Doubly Linked List iteratively
void reverseDLL(Node *&head, Node *&tail)
{
    Node *current = head;
    Node *temp = NULL;

    while (current != NULL)
    {
        // Swap next and prev
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to next node (original next is prev now)
        current = current->prev;
    }

    // Update head and tail
    if (temp != NULL)
    {
        head = temp->prev;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    // Creating list: 10 <-> 20 <-> 30 <-> 40
    insertAtEnd(head, tail, 10);
    insertAtEnd(head, tail, 20);
    insertAtEnd(head, tail, 30);
    insertAtEnd(head, tail, 40);

    cout << "Original List:" << endl;
    display(head);

    reverseDLL(head, tail);

    cout << "Reversed List:" << endl;
    display(head);

    return 0;
}
