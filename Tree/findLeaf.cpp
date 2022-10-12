/*
	Program to find the Number of leaves in a tree
	Approach :  a node is said to be leaf node if its left and right child is NULL; 
		
	
*/

#include<bits/stdc++.h>
#include<cstdlib>
#include<queue>

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
int NumberOfLeaf(struct node *root)
{
	struct node *temp;
	int count= 0;
	queue<node*> q;
	if(root==NULL)
	{
		return 0;
	}
	
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp->left == NULL && temp->right ==NULL)
		{
			count++;
		}
		
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
	return count;
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
	root->left->left->left = createNode(8);
	root->left->left->right = createNode(9 );
	cout<<"Number of leaves in a tree : "<<NumberOfLeaf(root);
	
	return 0;
}
