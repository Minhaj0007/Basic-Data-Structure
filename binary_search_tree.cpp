//Binary search tree insertion,traversal,searching,counting 
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node *InsertBinarySearchTree(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }
    if (value < root->data)
    {
        root->left = InsertBinarySearchTree(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = InsertBinarySearchTree(root->right, value);
    }
    return root;
}

void Preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node *root)
{
    if (root == NULL)
        return;
    Preorder(root->left);
    cout << root->data << " ";
    Preorder(root->right);
}

void Postorder(Node *root)
{
    if (root == NULL)
        return;
    Preorder(root->left);
    Preorder(root->right);
    cout << root->data << " ";
}

int FindMax(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}
int FindMin(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty!" << endl;
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

bool SearchBST(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    else if (key < root->data)
    {
        SearchBST(root->left, key);
    }
    else if (key > root->data)
    {
        SearchBST(root->right, key);
    }
}

int countNodes(Node* root) 
{
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


int main()
{
    Node *root = NULL;
    int n, value, key;
    cout << "Enter total number of nodes:" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        root = InsertBinarySearchTree(root, value);
    }
    cout << "Enter search key" << endl;
    cin >> key;
    if (SearchBST(root, key))
    {
        cout << "Element found\n";
    }
    else
    {
        cout << "Element not found\n";
    }
    cout << "After Preorder Traversal" << endl;
    Preorder(root);
    cout << endl;
    cout << "After Postorder Traversal" << endl;
    Postorder(root);
    cout << endl;
    cout << "After Inorder Traversal" << endl;
    Inorder(root);
    cout << endl;
    cout << "Min value is : " << FindMin(root) << endl;
    cout << "Max value is : " << FindMax(root) << endl;
    cout << "Total Nodes:" << countNodes(root) << endl;
    return 0;
}