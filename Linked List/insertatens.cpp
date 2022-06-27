#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

struct node{
	int data;
	struct node *next;
};

struct node * InsertAtEnd(int value, struct node *head)
{
	// defining new node and temp
	struct node *newnode,*temp;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		return head;
	}
	newnode->data = value;
	newnode->next = NULL;
	
	if(head == NULL)
	{
		head = newnode;
		temp = head;
	}
	else
	{
		temp->next = newnode;
		temp = newnode;
	}
	
	return head;
	
}

struct node *InsertAtMiddle(struct node * head,int pos,int value)
{
	struct node *newnode,*temp;
	temp = head;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = value;
	newnode->next = NULL;
	
	if(head == NULL)
	{
		head = newnode;
		temp = head;
	}
	else{
		int count = 1;
		while(temp!=NULL && count<pos)
		{
			count++;
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
	
}
void PrintList(struct node *startnode)
{
	while(startnode!=NULL)
	{
		cout<<startnode->data;
		startnode = startnode->next;
	}
	cout<<endl;
}
int main()
{
	struct node *head = NULL;
	int t;
	cin>>t;
	while(t--)
	{
		int value;
		int n;
		cin>>n;
		
		for(int i = 0; i<n;i++)
		{
			cin>>value;
			head = InsertAtEnd(value,head);
		}
		PrintList(head);
		
		int pos;
		cin>>pos;
		cin>>value;
		InsertAtMiddle(head,pos,value);
		PrintList(head);
	}
	return 0;
}
