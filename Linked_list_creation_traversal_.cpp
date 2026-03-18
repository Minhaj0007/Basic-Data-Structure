#include<iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node *head = nullptr, *temp = nullptr;

void Creation(int value)
{
    node* newnode = new node();
    newnode->data = value;
    newnode->next = nullptr;

    if(head == nullptr)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode; 
        temp = newnode;
    }
}

void traverse(node* head)
{
    if (!head)
    {
        cout << "List is empty.\n";
        return;
    }
    node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    int n;
    cout << "Please enter node numbers" << endl;
    cin >> n;
    cout << "Please enter values" << endl;

    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        Creation(a);
    }

    traverse(head);
}
