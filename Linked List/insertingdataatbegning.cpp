#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;
struct node{
	int data;
	struct node *next;
};

struct node * creatingList(struct node * head )
{
	struct node *newnode, *temp;
	for(int i = 1 ; i<=5; i++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			return head;
		}
		// inserting data into new node.
			newnode->data = i;
			newnode->next = NULL;
			
		if(head==NULL)
		{
			head = newnode;
			temp = head;
		}
		else{
			temp->next = newnode;
			temp = newnode;
		}
		
		
	}
	return head;
}

void printList(struct node * headnode)
{
	while(headnode!=NULL)
	{
		cout<<headnode->data;
		headnode = headnode->next;
	}
}
int main()
{
	struct node *head = NULL;
	head = creatingList(head);
	printList(head);

	return 0;
}
