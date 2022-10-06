/*
	Implementing tree structure and performing Level Order Traversal.
*/
#include<bits/stdc++.h>
#include<cstdlib>
#include <queue>
using namespace std;

struct node{
	struct node* left;
	int data;
	struct node* right;
};

struct node* createNode(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

void leveOrderTraversal(struct node *root)
{
	struct node *temp;
	queue<node*> q;
	if(!root)
		return;
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		cout<<temp->data<<" ";
		
		if(temp->left)
			q.push(temp->left);
			
		if(temp->right)
			q.push(temp->right);
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
	leveOrderTraversal(root);
	return 0;
}
