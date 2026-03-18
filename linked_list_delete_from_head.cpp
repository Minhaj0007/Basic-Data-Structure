#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) 
    {
        data = value;
        next = NULL;
    }
};

Node* head = NULL;
Node* temp = NULL;

void Insert(Node* &head, Node* &temp, int value)
{
    Node *newnode = new Node(value);

    if (head == NULL) {        // First node
        head = temp = newnode;
    } 
    else {
        temp->next = newnode;  // Link new node
        temp = newnode;        // Move temp to last node
    }
}

void DeleteFromBeginning(Node* &head, Node* &temp)
{
    if (head == NULL) return;

    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;

    if (head == NULL)
    {
        temp = NULL;
    }
    
}

void print(Node* head)
{
    Node* curr = head;
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
        {
            break;
        }

        Insert(head, temp, val);
    }

    DeleteFromBeginning(head, temp);
    print(head);
    return 0;
}
