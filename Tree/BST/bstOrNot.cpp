#include<bits/stdc++.h>
#include<cstdlib>

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

int isBst(struct node *root, int *prev)
{
	if(root==NULL)
		return 1;
	
	if(!isBst(root->left,prev))
		return 0;
	
	if(root->data<prev)
		return 0;
	prev = root->data;
	return isBst(root->right,prev);
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
	int prev = INT_MIN;	  
	cout<<"Hekki";  
	cout<<isBst(root,prev);
	return 0;
}
