/*
	Program to Reverse level order output
	Approach : use stack to print the output in reverse order
	
*/

#include<bits/stdc++.h>
#include<cstdlib>
#include<queue>
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
void ReverseLevelOrder(struct node *root)
{
	struct node *temp;
	if(!root)
		return;
	queue<node*> q;
	stack<node*> s;
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		s.push(temp);
		if(temp->left!=NULL)
			q.push(temp->left);
		
		if(temp->right!=NULL)
			q.push(temp->right);
	}
	while(!s.empty())
	{
		cout<<s.top()->data<<" ";
		s.pop();
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
	ReverseLevelOrder(root);
	return 0;
}
