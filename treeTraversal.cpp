#include<bits/stdc++.h>

using namespace std;
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
};

Node *CreatenewNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void insert_node(Node *root, int number, int leftvalue, int rightvalue)
{
    if (root == NULL)
        return;
    if (root->data == number)
    {
        root->left = CreatenewNode(leftvalue);
        root->right = CreatenewNode(rightvalue);
    }
    else
    {
        insert_node(root->left, number, leftvalue, rightvalue);
        insert_node(root->right, number, leftvalue, rightvalue);
    }
}
void preorder(Node *root)
{
    if(root)
    {
        if(root->data)
            cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node *root)
{
    if(root)
    {
        inorder(root->left);
        if(root->data)
          cout<<root->data<<" ";
        inorder(root->right);
    }
}
void postorder(Node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        if(root->data)
            cout<<root->data<<" ";
    }
}
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    Node *root = NULL;
    int n, i = 0;
    cin>>n;
    if (n > 20)
        exit(0);
    int ro[n], l[n], r[n];
    while (n--)
    {
        int number, left, right;
        cin>>number>>left>>right;
        for (int j = 0; j < i; j++)
        {
            if (ro[j] == number)
            {
                cout<<"Tree can not contain loop";
                exit(0);
            }
            if (l[j] == left && left != 0)
            {
                cout<<"left node is already a child node";
                exit(0);
            }
            if (r[j] == right && right != 0)
            {
                cout<<"Right node is already a child node";
                exit(0);
            }
        }
        ro[i] = number;
        l[i] = left;
        r[i] = right;
        for (int j = 0; j <= i; j++)
        {
            if (ro[j] == left || ro[j] == right)
            {
                cout<<"Tree can not contain loop";
                exit(0);
            }
        }
        
        if (root == NULL)
        {
            root = CreatenewNode(number);
            root->left = CreatenewNode(left);
            root->right = CreatenewNode(right);
        }
        else
            insert_node(root, number, left, right);
        
        i++;
    }
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}
