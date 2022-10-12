/*
	Program to find the Deepest node of tree
	Approach :  Here we use level order traversal to find the last node of a 
	tree i.e deepest node; 
		
	
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
struct node *DeepestNodeOfTree(struct node *root)
{
	struct node *temp;
	queue<node*> q;
	if(root==NULL)
	{
		return root;
	}
	
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp->left!=NULL)
			q.push(temp->left);
		if(temp->right!=NULL)
			q.push(temp->right);
	}
	return temp;
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
	cout<<"Deepest Node of tree : "<<DeepestNodeOfTree(root)->data;
	return 0;
}
