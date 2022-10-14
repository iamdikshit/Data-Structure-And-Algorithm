/*
	create mirror image of tree
	
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
struct node *MirrorImg(struct node *root)
{
//	check for base condition
	struct node *temp;
	if(root)
	{
		MirrorImg(root->left);
		MirrorImg(root->right);
		temp= root->left;
		root->left = root->right;
		root->right = temp;
	}
	return root;
}

void display(struct node *root)
{
	struct node *temp;
	queue<node*> q;
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		cout<<temp->data<<" ";
		
		if(temp->left!=NULL)
			q.push(temp->left);
		
		if(temp->right!=NULL)
			q.push(temp->right);
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
	root = MirrorImg(root);
	display(root);
	return 0;
}
