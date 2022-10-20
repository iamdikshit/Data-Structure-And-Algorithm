/*
	Find Min and Max Number in a BST
*/

#include<bits/stdc++.h>

using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *createBinarySearchTree(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = newnode->right;
	return newnode;
}


struct node *FindMax(struct node *root)
{
	if(root==NULL)
	{
		return NULL;	
	}
	else
	{
		while(root->right!=NULL)
		{	
			root = root->right;
			cout<<root->data;
		}
	
	}
		
	
	return root;
}

struct node *FindMin(struct node *root)
{
	if(root==NULL)
		return NULL;
	else if(root->left==NULL)
		return root;
	else
		return FindMin(root->left);
}






int main()
{
	struct node *root = createBinarySearchTree(10);
	root->left = createBinarySearchTree(6);
	root->right = createBinarySearchTree(16);
	root->left->left = createBinarySearchTree(4);
	root->left->right = createBinarySearchTree(9);
	root->right->left = createBinarySearchTree(12);
	root->right->right = createBinarySearchTree(17);	
	cout<<"\nMin : "<<FindMin(root)->data;    
	cout<<"\nMax : "<<FindMax(root)->data;                                            
	
	
	return 0;
}
