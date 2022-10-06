/*
	Implementing tree structure and performing InOrder Traversal.
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

// inOrder   left subtree -> root -> right subtree
void inOrder(struct node *root)
{
	if(root!=NULL)
	{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
		
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
	
	inOrder(root);
	
	return 0;
}
