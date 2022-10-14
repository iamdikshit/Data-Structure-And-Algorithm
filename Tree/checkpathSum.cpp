/*
	Check the existance of path with given sum
	
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
int CheckPath(struct node *root,int sum)
{
	// check for base condition
	if(root==NULL)
	{
		return (sum==0);
	}
	else
	{
		int remainingSum = sum - root->data;
		// check whether node has left and right child or not
		if((root->left && root->right) || (!root->left && !root->right))
		{
			return ((CheckPath(root->left,remainingSum)) || CheckPath(root->right,remainingSum) );
		}
		// check for only left child
		else if(root->left)
		{
			CheckPath(root->left,remainingSum);
		}
		else // else go for right child
		{
			CheckPath(root->right,remainingSum);
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
	if(CheckPath(root,7))
		cout<<"true";
	else
		cout<<"false";
	

	return 0;
}
