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
	int root_val,right_val,left_val;
	int max = INT_MIN;
	if(root)
	{
		root_val = root->data;
		left_val = maxElement(root->left);
		right_val = maxElement(root->right);
		
		if(right_val< left_val)
			max=left_val;
		else
			max = right_val;
		
		if(root_val>max)
			max = root_val;
	}
	
	return max;
}

int main()
{
int m;
	struct node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(23);
	root->right->right = createNode(7);
	
	m = maxElement(root);
	cout<<"max:"<<m;
	return 0;
}
