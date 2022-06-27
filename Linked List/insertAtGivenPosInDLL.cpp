#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

// creating duobly linked list structure
struct node{
	struct node *pre;
	int data ;
	struct node *next;
};

// fucntion to insert at the end of node.
struct node *InsertAtEnd(struct node *head , int n)
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

// function for print list
void PrintList(struct node *startnode)
{
	while(startnode->next!=NULL)
	{
		cout<<startnode->data<<" ";
		startnode = startnode->next;
	}
	cout<<endl;
}

struct node *InsertAtgivenpos(struct node *head,int pos,int value)
{
	struct node *newnode, *current = head;
	newnode = (struct node*)malloc(sizeof(struct node));
	int count = 1;
	if(!newnode)
	{
		return head;
	}
	newnode->pre = NULL;
	newnode->data = value;
	newnode->next = NULL;
	
	if(head==NULL)
	{
		head = newnode;
		return head;
	}
	else{
		while(current->next!=NULL && count<pos-1)
		{
			current = current->next;
			count++;
		}
		
		
		if(count<pos-1)
		{
			cout<<"Desired position does not exists";
			return head;
		}
		newnode->next = current->next;
		newnode->pre = current;
		
		if(current->next)
		{
			current->next->pre = newnode;
			
		}
		current->next = newnode;
	}
	
	return head;
}

int main()
{
	struct node *head = NULL;
	int n;
	cin>>n;
	head =  InsertAtEnd(head,n);
	PrintList(head);
	int pos;
	cin>>pos;
	int value;
	cin>>value;
	head = InsertAtgivenpos(head, pos,value);
	PrintList(head);
	return 0;
}
