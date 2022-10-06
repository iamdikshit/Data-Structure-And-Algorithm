/*
	Algorithm to find the max element in the tree
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

struct node* createNode(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

int maxElement(struct node *root)
{
	struct node *temp ;
	queue<node*> q;
	int max = INT_MIN;
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(max<temp->data)
			max = temp->data;
		
		if(temp->left)
			q.push(temp->left);
		
		if(temp->right)
			q.push(temp->right);
	}
//	free(q);
	return max;
}

int main()
{
int m;
	struct node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(18);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	
	m = maxElement(root);
	cout<<"max:"<<m;
	return 0;
}
