#include <iostream>
using namespace std;

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

Node *head = NULL;
Node *temp = NULL;

void Insert(Node *&head, Node *&temp, int value)
{
    Node *newnode = new Node(value);

    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}

void DeleteFromAnyPosition(Node* &head, int position)
{
    if (head == NULL || position <= 0) 
    {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* temp = head;

    // Case 1: delete head
    if (position == 1)
    {
        head = head->next;
        delete temp;
        return;
    }

    Node* prev = NULL;

    // Traverse to (position - 1)
    for(int i = 1; temp != NULL && i < position; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    // If position is out of range
    if (temp == NULL)
    {
        cout << "Position out of range!" << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
}

void print(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    int val;
    cout << "Please enter values: " << endl;

    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        Insert(head, temp, val);
    }

    int pos;
    cout << "Please enter position number: " << endl;
    cin >> pos;

    DeleteFromAnyPosition(head, pos);
    print(head);

    return 0;
}
