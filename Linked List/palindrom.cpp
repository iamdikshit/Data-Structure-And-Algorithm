// Check a linked list is Palindrom or not.

#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

struct node{
	int data;
	struct node *next;
};

// Function to insert the values
struct node *InsertAtEnd(struct node *head,int data)
{
	struct node *current = head, *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	if(!newnode)
	{
		cout<<"Memory Error";
		return head;
	
	}
	
	newnode->data = data;
	newnode->next = NULL;
	if(head == NULL)
	{
		head = newnode;
		return head;
	
	}
	else{
		while(current->next!=NULL)
		{
			current = current->next;
		}
		current->next = newnode;
	}
	
	return head;
}

// function to find the MID of linked list 
struct node *Mid(struct node *head)
{
	struct node *slow, *fast;
	slow = head;
	fast = head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

// Function to reverse the list
struct node *Reverse(struct node *head)
{
	struct node *prev = NULL, *current = head,*next;
	while(current!=NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		
	}
	if(prev!=NULL)
	{
		head= prev;
	}
	return head;
}

// function to check palindrom
bool Palindrom(struct node *head)
{
	struct node *mid,*last,*current = head;
	if(head==NULL)
	{
		return true;
	}
	mid = Mid(head);
	last = Reverse(mid->next);
	
	while(last!=NULL)
	{
		if(current->data!=last->data)
		{
			return false;
		}
		current = current->next;
		last = last->next;
	}
	return true;
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
struct node *head = NULL;
int main()
{
	
	int n,data;
	cin>>n;
	for(int i = 1; i<=n;i++)
	{
		cin>>data;
		head = InsertAtEnd(head,data);
	}
	PrintList(head);
	if(Palindrom(head))
	{
		cout<<"List is palindrom";
	}
	else
	{
		cout<<"List is not palindrom";
	}
	return 0;
}
