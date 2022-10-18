/*
	Tree Traversal NON Recursive Approach
	
*/

#include<bits/stdc++.h>
#include<cstdlib>
#include<stack>

using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *createNode(int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = data;
	newnode->left = newnode->right = NULL;
	return newnode;
}

// Pre Order Traversal (Non recursive ) 
void PreOrderNonRecursive(struct node *root)
{
	// creat stack
	stack<node*> s;
	while(1)
	{
		while(root)
		{
			//display root
			cout<<root->data<<" "; 
			s.push(root); // push into stack
			root =root->left; // go for left node
		}
		if(s.empty())
		{
			break;
		}
		else
		{
			root = s.top();
			s.pop();
			root = root->right;
		}
	}
}

// InOrder Traversal (Non Recursive)
void InOrderNonRecursive(struct node *root)
{
	stack<node*> s;
	while(1)
	{
		while(root)
		{
			s.push(root); //push into stack
			root = root->left; // go for left
		}
		if(s.empty())
			break;
		root = s.top();
		s.pop();
		cout<<root->data<<" ";
		root = root->right;
	}
}

// Post Order Traversal 
void PostOrderNonRecursive(struct node *root)
{
	stack<node*> s;
	struct node *previous = NULL;
	do{
		while(root!=NULL)
		{
			s.push(root);// push into stack;
			root = root->left; // go to left child
		}
		while(root==NULL && !s.empty())
		{
			root = s.top();
			if(root->right == NULL || root->right == previous)
			{
				cout<<root->data<<" ";
				s.pop();
				previous = root;
				root=NULL;
			}
			else
			{
				root = root->right;
			}
		}
	}while(!s.empty());
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
	cout<<"\nPreOrder Non Recursive : ";
	PreOrderNonRecursive(root);
	cout<<"\nInOrder Non Recursive : ";
	InOrderNonRecursive(root);
	cout<<"\nPostOrder Non Recursive : ";
	PostOrderNonRecursive(root);
	return 0;
}
