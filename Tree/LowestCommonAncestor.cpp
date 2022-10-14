/*
	Lowest common Ancesstor	
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
struct node *LCO(struct node *root,struct node *p,struct node *q)
{
	if(root==NULL || root==p || root==q)
		return root;
	
	struct node *left = LCO(root->left,p,q);
	struct node *right = LCO(root->right,p,q);
	if(left==NULL)
		return right;
	else if(right==NULL)
		return left;
	else // if both are left and right are null
		return root;
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
	root = LCO(root,root->right->left,root->right->right);
	cout<<root->data;
	return 0;
}
