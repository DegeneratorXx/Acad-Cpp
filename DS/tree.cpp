#include <bits/stdc++.h>

using namespace std;
// Trees -> Non Linear data structure
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *builtTree(Node *root)
{
    cout << "Enter the data :";
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Data left of " << data << endl;
    root->left = builtTree(root->left);
    cout << "Data for right of " << data << endl;
    root->right = builtTree(root->right);
    cout << endl;
    return root;
}
void Levelordertraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *temp = q.front();
        // cout << temp->data << " ";
        q.pop();

        if (temp == NULL)
        { // Previous level has already traversed
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
// LNR left node right
void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
// NLR
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
// LRN
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->right);
    postorder(root->left);
    cout << root->data << " ";
}
int maxheight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int ldepth = maxheight(root->left);
        int rdepth = maxheight(root->right);

        if (ldepth > rdepth)
        {
            return (ldepth + 1);
        }
        else
        {
            return (rdepth + 1);
        }
    }
}
int Tnodes(Node *root)
{
    if (root == NULL)
        return 0;

    int l = Tnodes(root->left);
    int r = Tnodes(root->right);
    return l + r + 1;
    // return sum;
}

void leafnode(Node *root, int &count)
{
    if (root == NULL)
    {
        return;
    }
    leafnode(root->right, count);
    leafnode(root->left, count);
    if (root->left == NULL && root->right == NULL)
        count++;
}
int main()
{
    Node *root = NULL;
    // Builting a tree
    cout << "BUILDING A TREE" << endl;
    root = builtTree(root);
    int c;
    // Level Order traversing
    int x = 1;
    
    while (x > 0)
    {

        cout << "Select the operation you want to perform" << endl;
        cout << "1.Level order Traversal" << endl;
        cout << "2.Inorder Traversal" << endl;
        cout << "3.Preorder Traversal" << endl;
        cout << "4.Postorder Traversal" << endl;
        cout << "5.Height of Tree" << endl;
        cout << "6.Total nodes" << endl;
        cout << "7.Count number of leafnode" << endl;

        cin >> c;
        cout << endl;
        if (c == 1)
        {
            cout << "Level Order Traversing " << endl;
            Levelordertraversal(root);
            cout << endl;
        }
        else if (c == 2)
        {
            cout << "Inorder traversal is as shown below" << endl;
            inorder(root);
            cout << endl;
        }
        else if (c == 7)
        {
            int count = 0;
            leafnode(root, count);
            cout << count;
        }
        else if (c == 4)
        {
            cout << "Postorder traversal is as shown below" << endl;
            postorder(root);
            cout << endl;
        }
        else if (c == 3)
        {
            cout << "Preorder traversal is as shown below" << endl;
            preorder(root);
            cout << endl;
        }
        else if (c == 5)
        {

            cout << "The Height of the tree is : " << maxheight(root);
            cout << endl;
        }
        else if (c == 6)
        {
            cout << "TOTAL NUMBER OF NODES ARE " << Tnodes(root);
            cout << endl;
        }
    }
}
// deletion