/*
	Ceil Problem Binary Search Tree
*/

#include<bits/stdc++.h>
#include<cstdlib>
#include<queue>

using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *createBinarySearchTree(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = newnode->right;
	return newnode;
}

struct node *InsertIntoBST(struct node *root,int data)
{
	if(root==NULL)
	{
		root = (struct node*)malloc(sizeof(struct node));
		if(root==NULL)
		{
			cout<<"Memory error";
			return root;
		}
		else
		{
			root->data = data;
			root->left = root->right = NULL;
			
		}
	}
	else
	{
		if(data<root->data)
		{
			root->left = InsertIntoBST(root->left,data);
		}
		else if(data>root->data)
		{
			root->right = InsertIntoBST(root->right,data);
		}
	}
	return root;
}

int Ceilfunc(struct node *root, int key)
{
	int ceil = -1;
	while(root)
	{
		if(root->data==key)
		{
			ceil = root->data;
			return ceil;
		}
		
		if(key>root->data)
		{
			root = root->right;
		}
		else
		{
			ceil = root->data;
			root = root->left;
		}
	}
	return ceil;
}

int floorfunc(struct node *root, int key)
{
	int floor=-1;
	while(root)
	{
		if(root->data==key)
		{
			floor = root->data;
			return floor;
		}
		if(key<root->data)
		{
			root = root->left;
		}
		else
		{
			floor = root->data;
			root = root->right;
		}
	}
	return floor;
}

void display(struct node* root)
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
		{
			q.push(temp->left);
		}
		if(temp->right!=NULL)
		{
			q.push(temp->right);
		}
	}
	
}



int main()
{
	struct node *root=NULL;
	root = InsertIntoBST(root,10); 
	root = InsertIntoBST(root,13); 
	root = InsertIntoBST(root,6); 
	root = InsertIntoBST(root,4);    
	root = InsertIntoBST(root,14);                                  
	display(root);
	cout<<"\nCeil : "<<Ceilfunc(root,5);
	cout<<"\nFloor : "<<floorfunc(root,5);
	
	return 0;
}
