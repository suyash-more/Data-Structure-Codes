#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    bool isThreaded;
};

void inorder(Node* root){
    if(root==NULL) return;
inorder(root->left);
cout<<root->data<<" ";
inorder(root->right);
}

Node* Insert(Node *root,char data)
{
    if(root == NULL)
    {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if(data <= root->data)
        root->left = Insert(root->left,data);
    else{
        root->right = Insert(root->right,data);
        root->isThreaded=true;
    }
    return root;
}

Node* leftmost(Node* node)
{
    if(node==NULL)
        return NULL;
    while(node!=NULL)
        node=node->left;
    return node;
}

void tbt(Node* root)
{
    if(root->left==NULL) return;
    Node* cur=leftmost(root);
    while(cur!=NULL){
        cout<<cur->data<<" ";

        if(cur->isThreaded){
            cur=cur->right;
        }else{
        cur=leftmost(cur->right);
        }
    }
}

int main()
{
    Node* root = NULL;
    root = Insert(root,5);
    root = Insert(root,10);
    root = Insert(root,3);
    root = Insert(root,4);
    root = Insert(root,1);
    root = Insert(root,11);

    //inorder(root);
    tbt(root);

}
