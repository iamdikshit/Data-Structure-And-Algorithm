#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

// Defining structure of the node
struct node{
	int data;
	struct node *next;
};

struct node *createList(struct node * head, int n)
{
	struct node *newnode,*temp;
	
	for(int i = 1 ;i<=n;i++)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		if(newnode == NULL)
		{
			return head;
		}
		newnode->data = i;
		newnode->next = NULL;
		
		if(head == NULL)
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
void printList(struct node *startnode)
{
	while(startnode!=NULL)
	{
		cout<<startnode->data;
		startnode = startnode->next;
	}
	cout<<endl;
}
struct node * deletefirstnode(struct node *startnode)
{
	struct node *temp;
	if(startnode == NULL)
	{
		cout<<"No Node is available.";
		return startnode;
	}
	else{
		temp = startnode;
		startnode = startnode->next;
		free(temp);
	}
	return startnode;
}
struct node * deleteLastnode(struct node *startnode)
{
	struct node *currentNode, *prenode;
	if(startnode == NULL)
	{
		cout<<"No Node is available.";
		return startnode;
	}
	currentNode = startnode;
	while(currentNode->next)
	{
		prenode = currentNode;
		currentNode = currentNode->next;
	}
	prenode->next = NULL;
	free(currentNode);
	return startnode;
}

struct node *deleteatgivenpos(struct node * head,int pos)
{
	struct node *newnode,*current,*prenode=NULL;
	current = head;
	int count =  1;
	if(head == NULL)
	{
		cout<<"No Node is available.";
		return head;
	}
	else{
		while(current->next && count<pos)
		{
			count++;
			prenode = current;
			current = current->next;
		}
		
		prenode->next = current->next;
		free(current);
	}
	return head;
}
int main()
{
	struct node *head = NULL;
	int n;
	cin>>n;
	head = createList(head,n);
	printList(head);
	head = deletefirstnode(head);
	printList(head);
	head = deleteLastnode(head);
	printList(head);
	int pos;
	cin>>pos;
	head = deleteatgivenpos(head,pos);
	printList(head);
	
	return 0;
}
