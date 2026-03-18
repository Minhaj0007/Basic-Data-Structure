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

void DeleteFromBeginning(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node *temp = head;

    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
    delete (temp);
}

void DeleteFromEnd(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node *temp = head;

    if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete (temp);
}

void DeleteFromAnyPosition(Node *&head, Node *&tail, int pos)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (pos == 1)
    {
        DeleteFromBeginning(head, tail);
        return;
    }

    Node *temp = head;
    int i = 1;
    while (i < pos)
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
        DeleteFromEnd(head, tail);
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete (temp);
}

void traversal(Node *head)
{
    Node *temp = head;
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
    Node *tail = NULL;

    Node *n1 = new Node(5);
    head = tail = n1;

    Node *n2 = new Node(6);
    head->next = n2;
    n2->prev = tail;
    tail = n2;

    Node *n3 = new Node(8);
    tail->next = n3;
    n3->prev = tail;
    tail = n3;

    Node* n4 = new Node(10);
    tail->next = n4;
    n4->prev = tail;
    tail = n4;

    cout << "Initial List:" << endl;
    traversal(head);

    cout <<" From which position You want to delete:" << endl;
    int pos;
    cin >> pos;
    DeleteFromAnyPosition(head, tail, pos);
    cout << "After deletetion list is: " << endl;
    traversal(head);

    DeleteFromBeginning(head, tail);
    cout << "After delete from beginning list is: " << endl;
    traversal(head);

    DeleteFromEnd(head, tail);
    cout << "After delete from end list is: " << endl;
    traversal(head);

    return 0;
}

