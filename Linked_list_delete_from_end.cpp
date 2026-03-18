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

void DeleteFromEnd(Node *&head, Node *&temp)
{
    if (head == NULL)
    {
        cout << "List is empty! Nothing to delete.\n";
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        temp = NULL;
        return;
    }

    Node *curr = head;
    Node *prev = NULL;

    while (curr->next != NULL)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    delete curr;

    temp = prev; // update tail
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

    while (true)
    {
        cin >> val;
        if (val == -1)
            break;

        Insert(head, temp, val);
    }

    DeleteFromEnd(head, temp);
    print(head);

    return 0;
}
