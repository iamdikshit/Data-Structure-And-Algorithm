/*
	Program to find diameter of tree
	O(n^2) approch 
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
int heightOftree(struct node *root)
{
	if(root==NULL)
		return 0;
	return 1+ max(heightOftree(root->left),heightOftree(root->right));
}
int diameter(struct node *root)
{
	int hl, hr, dl,dr;
	if(root==NULL)
		return 0;
		
	hl = heightOftree(root->left);
	hr = heightOftree(root->right);
	dl = heightOftree(root->left);
	dr = heightOftree(root->right);
	return max(hl+hr+1,max(dl,dr));
}

int main()
{
	struct node *root1 = createNode(1);

	root1->left = createNode(2);
	root1->right = createNode(3);
	root1->left->left = createNode(4);
	root1->left->right = createNode(5);
	root1->right->left = createNode(6);
	root1->right->right = createNode(7);
	
	cout<<"Diameter of Tree : "<<diameter(root1);

	return 0;
}
