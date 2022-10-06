/*
	Tree Traversal Using Class
	Note : D-> visited node, L-> Left node , R->Right node;
	PreOrder (DLR) 
	InOrder (LDR)
	PostOrder (LRD)
*/
#include<bits/stdc++.h>

using namespace std;

class Node{
	public:
		int data;
		Node *left,*right;
		Node(int data){
			this->data = data;
			left = NULL;
			right = NULL;
		}
};

class BinaryTree{
	public:
		void preOrder(Node* root)
		{
			if(root)
			{
				cout<<root->data<<" ";
				preOrder(root->left);
				preOrder(root->right);
			}
		}
		void inOrder(Node* root)
		{
			if(root)
			{
				inOrder(root->left);
				cout<<root->data<<" ";
				inOrder(root->right);
			}
		}
		
		void postOrder(Node* root)
		{
			if(root)
			{
				postOrder(root->left);
				postOrder(root->right);
				cout<<root->data<<" ";
			}
		}
		
};


int main()
{
	BinaryTree bt;
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	
	cout<<"PreOrder:";
	bt.preOrder(root);
	cout<<"\nINOrder:";
	bt.inOrder(root);
	cout<<"\nPostOrder:";
	bt.postOrder(root);
	
	return 0;
	
}
