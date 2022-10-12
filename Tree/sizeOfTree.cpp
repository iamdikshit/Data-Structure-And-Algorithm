/*
	Program to find the size of tree
	Approach : (size of left subtree) + root + (size of right subtree)
	
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
int sizeOFtree(struct node *root)
{
	if(root==NULL)
		return 0;
	return (sizeOFtree(root->left) + 1 + sizeOFtree(root->right));
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
	cout<<"Size of tree : "<<sizeOFtree(root);
	return 0;
}
