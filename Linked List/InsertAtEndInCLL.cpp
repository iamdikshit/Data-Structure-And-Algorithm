  #include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

// creating node
struct node{
	int data;
	struct node *next;
};

struct node *InsertAtEndOfCLL(struct node *head, int value)
{
	struct node *newnode,*current = head;;
	newnode = (struct node*)malloc(sizeof(struct node));

	if(!newnode)
	{
		cout<<"Memory Error.....!";
		return head;
	}
	newnode->data = value;
	newnode->next = NULL;
	
	
	
	if (head == NULL)
	{
		head = newnode;
		head->next = head;
		return head;
	
	}
	
	while(current->next!=head)
	{
		current = current->next;
	}
	newnode->next = head;
	current->next = newnode;
	
	return head;
}

void PrintList(struct node *startnode)
{	struct node *current = startnode;
	
	if(startnode == NULL)
		return;
	do{
		cout<<current->data<<" ";
		current = current->next;
		
	}while(current->next!=startnode);
	
	cout<<endl;
}

// delete function
struct node *deleteAtGivenPos(struct node *head, int pos)
{
	struct node *current = head,*temp = head, *delptr = head;
	int count =1;
	

	
	if(pos==1)
	{
		
		while(current->next!=NULL)
		{
		
			current = current->next;
		
		}
	
		current->next = head->next;
		head = head->next;
		
		free(temp);
		return head;
	}
	return head;
}

int main()
{
	struct node *head = NULL;
	int n;
	cin>>n;
	for(int i = 1; i<=n+1; i++)
	{
		head = InsertAtEndOfCLL(head,i);
	
	}
	PrintList(head);
	int pos;
	cin>>pos;
	head = deleteAtGivenPos(head,pos);
	PrintList(head);
	
	
	
	
	
	return 0;
}
