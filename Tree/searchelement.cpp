/*
	Program to search element in a tree.
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

// function return 1 if element is present in a tree else return 0 using recursion
int searchElement(struct node *root, int data)
{
	int temp;
	// Base condition
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		if(root->data==data)
		{
			return 1;
		}
		else
		{
		
			temp =	searchElement(root->left,data);
			if(temp!=0)
			{
				return temp;
			}
			else
			{
		 		return	searchElement(root->right,data);
			}
		}
		
	}
	
	return 0;
}

//using Iterative way
int SeachIterative(struct node *root, int data)
{
	struct node* temp;
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp->data==data)
		{
			return 1;
		}
		if(temp->left!=NULL)
			q.push(temp->left);
		
		if(temp->right!=NULL)
			q.push(temp->right);
	}
	return 0;
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
	
	cout<<"Recursive : "<<searchElement(root,6);
	cout<<"\nIterative : "<<SeachIterative(root,6);
	
	return 0;
}
