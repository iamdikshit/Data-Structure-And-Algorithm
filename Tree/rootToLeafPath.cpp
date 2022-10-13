/*
	Printout all its root-to-leaf path
	
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

void print(int path[], int pathlength)
{
	for(int i=0;i<pathlength; i++)
	{
		cout<<path[i]<<"->";
	}
	cout<<endl;
}
void RootTOLeaf(struct node *root,int path[], int pathlength)
{
	
	if(root==NULL)
		return;
	
	path[pathlength]= root->data;
	pathlength++;
	if(root->left ==NULL && root->right==NULL)
	{
			print(path,pathlength);
	}
	else
	{
		RootTOLeaf(root->left,path,pathlength);
		RootTOLeaf(root->right,path,pathlength);
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
	int arr[10];
	RootTOLeaf(root,arr,0);
	return 0;
}
