/*
	Program to find the height of tree
	Approach : 
		find height of left subtree(hl)
		find height of right subtree(hr)
		compare hr and hl
		if hl greater
			return hl+1;
		else
			return hr+1;
	
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
int heightOfTree(struct node *root)
{
	int hr,hl;
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		hl = heightOfTree(root->left);
		hr = heightOfTree(root->right);
		if(hl>hr)
			return hl+1;
		else
			return hr+1;
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
	cout<<"Height of tree : "<<heightOfTree(root);
	return 0;
}
