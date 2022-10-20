/*
	Binary Search Tree
	Search in BST
*/

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

struct node *FindElementBSTRecursive(struct node *root,int data)
{
	if(root==NULL)
		return NULL;
	if(data<root->data)
		return FindElementBSTRecursive(root->left,data);
	if(data>root->data)
		return FindElementBSTRecursive(root->right,data);
	return root;

}



int main()
{
	struct node *root = createBinarySearchTree(10);
	root->left = createBinarySearchTree(6);
	root->right = createBinarySearchTree(16);
	root->left->left = createBinarySearchTree(4);
	root->left->right = createBinarySearchTree(9);
	root->right->left = createBinarySearchTree(13);
	root->right->right = createBinarySearchTree(17);
	int n;
	cin>>n;
	root = FindElementBSTRecursive(root,n);
	if(root!=NULL)
	{
		cout<<root->data;	
	}	
	
	return 0;
}
