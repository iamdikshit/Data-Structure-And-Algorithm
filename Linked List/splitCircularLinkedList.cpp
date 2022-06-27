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
void SplitCLL(struct node *head)
{
	struct node *slow,*fast,*head1,*head2;
	if(head == NULL || head->next == NULL )
	{
		head1 = head;
		head2 = NULL;
	}
	else {
		slow = head;
		fast = head->next;
		while(fast!=NULL)
		{
			fast = fast->next;
			if(fast!=NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
			
			
		}
		head1 = head;
		head2 = slow->next;
		slow->next = NULL;
	}
	
	struct node *temp1 = head1;
	struct node *temp2 = head2;
	while(temp1!=NULL){
		cout<<temp1->data;
		temp1 = temp1->next;
	}
	
	cout<<endl;
	
	while(temp2!=NULL){
		cout<<temp2->data;
		temp2 = temp2->next;
	}
	cout<<endl;
}


int main()
{
	struct node *head = NULL;
	int n;
	cin>>n;
	for(int i = 1; i<=n; i++)
	{
		head = InsertAtEnd(i,head);
	
	}
	PrintList(head);
	SplitCLL(head);
	return 0;
}
