/*
	Program to print tree in zig-zag format
*/
#include<bits/stdc++.h>
#include<cstdlib>
#include<stack>

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

void zigzag(struct node *root)
{
	stack<node*> currentlevel;
	stack<node*> nextlevel;
	struct node* temp;
	int lefttoright = 1;
	currentlevel.push(root);
	while(!currentlevel.empty())
	{
		temp = currentlevel.top();
		currentlevel.pop();
		if(temp)
		{
			cout<<temp->data<<" ";
			if(lefttoright)
			{
				if(temp->left)
					nextlevel.push(temp->left);
				if(temp->right)
					nextlevel.push(temp->right);
			}
			else
			{
				if(temp->right)
					nextlevel.push(temp->right);
				if(temp->left)
					nextlevel.push(temp->left);
			}
		}
		if(currentlevel.empty())
		{
			lefttoright = 1 - lefttoright;
			swap(currentlevel,nextlevel);
		}
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
	zigzag(root);
	return 0;
}
