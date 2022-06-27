#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

// structure of Node ( Doubly Linked list )
struct node{
	struct node *pre;
	int data ;
	struct node *next;
};

// fucntion to insert at the end of node.
struct node *InsertAtEnd(struct node *head , int n)
{
	struct node *newnode, *current = head  ;

	for(int i = 1; i<=n+1; i++)
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

// function to delete node at given position

struct node *DeleteAtGivenPos(struct node *head,int pos)
{
	struct node *current = head, *temp = head;
	if(head == NULL)
	{
		cout<<"List is empty";
		return head;
	}
	
	if(pos == 1)
	{
		head = head->next;
		free(current);
		return head;
	}
	
	int count = 1;
	while(current->next!=NULL && count<=pos-1)
	{
		current = current->next;
		count++;
	}
	
	if(count < pos)
	{
		cout<<"Incorrect position";
		return head;
	}
	
	temp = current->pre;
	temp->next = current->next;
	if(temp->next)
	{
		current->next->pre = temp;
	}
	
	free(current);
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
//	int value;
//	cin>>value;
	head = DeleteAtGivenPos(head, pos);
	PrintList(head);
	return 0;
}
