/*
	Program to insert a node in a binary tree
	We use Level order traversal to insert the node 
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

struct node * createNode(int data)
{
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = newnode->right = NULL; 
	return newnode;
}

struct node *InsertNode(struct node* root,int data)
{
	struct node *temp, *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	
	if(!newnode)
		return root;
	
	if(!root)
	{
		root = newnode;
		return root ;
	}
	else{
		queue<node*> q;
		q.push(root);
		while(!q.empty())
		{
			temp = q.front();
			q.pop();
			if(temp->left!=NULL)
			{
				q.push(temp->left);
			}
			else
			{
				temp->left = newnode;
				return root;
			}
			
			if(temp->right!=NULL)
			{
				q.push(temp->right);
			}
			else
			{
				temp->right = newnode;
				return root;
			}
		}
	}
	return root;
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
	struct node *root = NULL;
	root = InsertNode(root,1);
	leveOrderTraversal(root);
	root = InsertNode(root,2);
	root = InsertNode(root,3);
	root = InsertNode(root,4);
	leveOrderTraversal(root);
	return 0;
}
