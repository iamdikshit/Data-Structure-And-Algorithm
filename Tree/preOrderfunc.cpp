/*
	Implementing tree structure and performing PreOrder Traversal.
*/
#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

struct node{
	struct node* left;
	int data;
	struct node* right;
};

struct node *createNode(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
		
}

// PreOrder  root -> left subtree -> right subtree
void preOrder(struct node *root)
{
	if(root!=NULL)
	{
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
		
	}
	
	
}

int main()
{
	struct node *root = createNode(1);

	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	
	preOrder(root);
	
	return 0;
}
