#include <bits/stdc++.h>
using namespace std;
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

void buildfromlevelorder(Node *&root)
{
    queue<Node*> q;
    cout<<"enter data for root";
    int d;cin>>d;
    root=new Node(d);
    q.push(root);

    while(!q.empty())
    {
        Node* temp= q.front();
        q.pop();

        cout<<"ENTER LEFT NODE FOR "<<temp->data<<endl;
        int ldata;
        cin>>ldata;

        if(ldata!=-1)
        {
            temp->left=new Node(ldata);
            q.push(temp->left);
        }


         cout<<"ENTER RIGHT NODE FOR "<<temp->data<<endl;
        int rdata;
        cin>>rdata;

        if(rdata!=-1)
        {
            temp->right=new Node(rdata);
            q.push(temp->right);
        }

    }

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
            cout<<temp->data<<" ";
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


int main()
{   Node * root=NULL;
buildfromlevelorder(root);
Levelordertraversal(root);

    
    return 0;
}