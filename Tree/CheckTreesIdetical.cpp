/*
	Program to return true if two tree are identical
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
int checkIdentical(struct node *root1,struct node *root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	
	if(root1==NULL || root2==NULL)
		return 0;
	
	return ((root1->data==root2->data)&& (checkIdentical(root1->left,root2->left)) && (checkIdentical(root1->right,root2->right)));
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
	// Tree 2
	struct node *root2 = createNode(1);
	root2->left = createNode(2);
	root2->right = createNode(3);
	root2->left->left = createNode(4);
	root2->left->right = createNode(5);
	root2->right->left = createNode(6);
	root2->right->right = createNode(7);
	if(checkIdentical(root1,root2))
		cout<<"True";
	else
		cout<<"False";
	return 0;
}
