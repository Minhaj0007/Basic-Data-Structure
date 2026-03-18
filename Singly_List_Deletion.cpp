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

// Delete from beginning
void deleteFromBeginning(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void deleteFromEnd(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == NULL)
    { // Only one node
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Delete from any position (1-based index)
void deleteFromPosition(Node *&head, int pos)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (pos == 1)
    {
        deleteFromBeginning(head);
        return;
    }

    Node *temp = head;
    int i = 1;
    while (i < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL)
    {
        cout << "Position out of range!" << endl;
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
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

    // Creating initial list
    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Initial list:" << endl;
    display(head);

    // Delete from beginning
    deleteFromBeginning(head);
    cout << "After deleting from beginning:" << endl;
    display(head);

    // Delete from end
    deleteFromEnd(head);
    cout << "After deleting from end:" << endl;
    display(head);

    // Delete from position 2
    deleteFromPosition(head, 2);
    cout << "After deleting position 2:" << endl;
    display(head);

    return 0;
}
