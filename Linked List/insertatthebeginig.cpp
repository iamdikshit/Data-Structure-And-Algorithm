#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

struct node{
	int data;
	struct node *next;
};

struct node* InsertDataAtBegining(int value, struct node* head)
{
	struct node *newnode, *temp;
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
	else{
		newnode->next = head;
		head = newnode;
	}
	return head;
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
	struct node*head = NULL;
	int t;
	cin>>t;
	while(t--)
	{
		int value;
		cin>>value;
		head = InsertDataAtBegining(value, head);
		PrintList(head);
		
	}
	return 0;
}
