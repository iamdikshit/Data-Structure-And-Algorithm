/*
	Program to find diameter of tree
	O(n) approch 
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
int diameterOfTree(struct node *root,int &ans)
{
	int hl,hr;
	if(root==NULL)
		return 0;
	hl = diameterOfTree(root->left,ans);
	hr = diameterOfTree(root->right,ans);
	ans = max(ans,hl+hr+1);
	return 1+max(hl,hr);
}


int main()
{
	struct node *root1 = createNode(1);

	root1->left = createNode(2);
	root1->right = createNode(3);
	root1->left->left = createNode(4);
	root1->left->right = createNode(5);
	root1->right->left = createNode(6);
	root1->right->right = createNode(7);
	int ptr = 0;
//	cout<<ptr;
	diameterOfTree(root1,ptr);
	cout<<ptr;
	

	return 0;
}
