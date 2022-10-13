/*
	Program to find level has maximum sum
	
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
int FindMaxLevel(struct node *root)
{
	struct node *temp;
	int level = 0, levelMax=0,currentSum=0,maxSum=0;
	queue<node*> q;
	q.push(root);
	q.push(NULL); // End of level 0
	while(!q.empty())
	{
		temp= q.front();
		q.pop();
		if(temp==NULL)
		{
			if(currentSum>maxSum)
			{
				maxSum = currentSum;
				levelMax = level;
			}
			
			currentSum = 0;
			// Implement for end of level
			if(!q.empty())
				q.push(NULL);
			level++;
		}
		else
		{
			currentSum+=temp->data;
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}
	}
	return levelMax;
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
	cout<<FindMaxLevel(root);
	return 0;
}
