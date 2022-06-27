#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;
// creating singly linked list  
struct node{
	int data;
	struct node *next;
};


struct node *InsertNodeInLinkedList(struct node *head,int n)
{
	struct node *newnode, *current = head;
	
	
		newnode = (struct node*)malloc(sizeof(struct node));
		if(!newnode)
		{
			cout<<"Memory error";
			return head;
		}
		newnode->data = n;
		newnode->next = NULL;
		
		if(head==NULL)
		{
			head = newnode;
			return head;
		}
		else
		{
			while(current->next!=NULL)
		{
			current = current->next;
		}
		
			current->next = newnode;
			
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

struct node *reverseList(struct node *head)
{
	struct node *current = head, *nextnode,*prev = NULL;
	while(current!=NULL)
	{
		nextnode = current->next;
		current->next = prev;
		
		prev = current;
		head = prev;
		current = nextnode;
		
	}
	
	return head;
}

int main()
{
	struct node *head = NULL;
	int n;
	cin>>n;
	for(int i = 1; i<=n; i++)
	{
		head = InsertNodeInLinkedList(head,i);
	}
	PrintList(head);
	head = reverseList(head);
	PrintList(head);
	return 0;
}
