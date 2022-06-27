#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

struct node{
	struct node *pre;
	int data;
	struct node *next;
};

// fucntion to insert at the end of node.
struct node *InsertNode(struct node *head , int n)
{
	struct node *newnode, *current = head  ;

	for(int i = 1; i<=n; i++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		if(!newnode)
		{
			return head;
		}
		newnode->data = i;
		newnode->pre = NULL;
		newnode->next = NULL;
		if(head == NULL)
		{
			head = newnode;
			current = head;
		}
		else{
			
			while(current->next!=NULL)
			{
				current = current->next;
			
			}
			newnode->pre = current;
			current->next = newnode;
			current = newnode;
			
		}
		
		
	}

	
	return head;
	
}

struct node *reverseddl(struct node *head)
{
	struct node *current = head, *prev = NULL;
	while(current!=NULL)
	{
		prev = current->pre;
		current->pre = current->next;
		current->next = prev;
		current= current->pre;
		
		
	}

	if(prev!=NULL)
	{
			head = prev->pre;		
	}
		
	
	return head;
}

void PrintList(struct node *startnode)
{
	while(startnode!=NULL)
	{
		cout<<startnode->data<<" ";
		startnode = startnode->next;
	}
	cout<<endl;
}
int main()
{
	struct node *head = NULL;
	int n;
	cin>>n;
	head = InsertNode(head,n);
	PrintList(head);
	head = reverseddl(head);
	PrintList(head);
	return 0;
}
