/* Binary Tree Traversal - Preorder, Inorder, Postorder */
#include<iostream>
using namespace std;

struct Node {
	char data;
	struct Node *left;
	struct Node *right;
};

bool IsSubtreeLesser(struct Node* root, int value)
{

    if(root==NULL) return true;
    if(root->data<=value && IsSubtreeLesser(root->left,value) && IsSubtreeLesser(root->right,value)) return true;
    else return false;
}
bool IsSubtreeGreater(struct Node* root, int value)
{

    if(root==NULL) return true;
    if(root->data>value && IsSubtreeGreater(root->left,value) && IsSubtreeGreater(root->right,value)) return true;
    else return false;
}
bool IsBinarySearchTree(struct Node* root)
{
    if(root==NULL) return true;
    if(IsSubtreeLesser(root->left,root->data)
       && IsSubtreeGreater(root->right,root->data)
       && IsBinarySearchTree(root->left)
       && IsBinarySearchTree(root->right)
       )
        return true;
    else return false;
}

bool IsBinarySearchTreeUtil(struct Node* root, int minValue, int maxValue)
{
    if(root==NULL) return true;
    if(root->data>minValue
       && root->data<maxValue
       && IsBinarySearchTreeUtil(root->left,minValue,root->data)
       && IsBinarySearchTreeUtil(root->right,root->data,maxValue)
       )
        return true;
    else return false;
}

bool IsBinarySearchTreeUtilPasser(struct Node* root){
    return IsBinarySearchTreeUtil(root,INT_MIN,INT_MAX);
}

// Function to Insert Node in a Binary Search Tree
Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data)
		root->left = Insert(root->left,data);
	else
		root->right = Insert(root->right,data);
	return root;
}

bool isbstinorder(Node *root)
{
   static int prev = INT_MIN;
   if(root==NULL) return true;
   isbstinorder(root->left);
   if(root->data>prev) return false;
   prev=root->data;
   isbstinorder(root->right);
}



int main() {
	/*Code To Test the logic
	  Creating an example tree
                M
			   / \
			  B   Q
			 / \   \
			A   C   Z
    */
	Node* root = NULL;
	root = Insert(root,1); root = Insert(root,2);
	root = Insert(root,3); root = Insert(root,4);
	root = Insert(root,8); root = Insert(root,5);
	//cout<<"Insertion went well"<<endl;
	//cout<<(IsBinarySearchTree(root)?"Is BST\n":"Not a BST\n");
	//cout<<(IsBinarySearchTreeUtilPasser(root)?"Is BST\n":"Not a BST\n");
	cout<<(isbstinorder(root)?"Is BST\n":"Not a BST\n");
}
