#include<bits/stdc++.h>
#include<cstdlib>


using namespace std;
struct node{
	int data;
	struct node *next;
};

struct Queue{
	struct node* front;
	struct node* rear;
};

struct Queue *CreateQueue()
{
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
	if(!q)
		return NULL;
	
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	if(!temp)
		return NULL;
	
	q->front=q->rear=NULL;
	return q;
}

void enqueue(struct Queue *q,int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	if(!newnode)
	{
		cout<<"\n Memory Error";
		return;
	}
	newnode->data = data;
	newnode->next = NULL;
	if(q->rear == NULL)
	{
		q->rear = q->front = newnode;
		return;
	}
	
	q->rear->next = newnode;
	q->rear = newnode;
}

void dequeue(struct Queue *q)
{
	if(q->front==NULL)
	{
		cout<<"\nQueue is Empty";
		return ;
	}
	
	struct node *temp = q->front;
	q->front = q->front->next;
	if(q->front ==NULL)
	{
		q->front=q->rear =NULL;
	}
	free(temp);
}

void display(struct Queue *q)
{
	if(q->front == NULL && q->rear==NULL)
	{
		return;
	}
	struct node *temp = q->front;
	
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp = temp->next;
	}
	cout<<endl;
}

int main()
{
	int n,i;
	cin>>n;
	int a[n];
	for(i=0; i<n;i++)
	{
		cin>>a[i];
	}
	struct Queue *q = CreateQueue();
	for(i=0;i<n;i++)
	{
		enqueue(q,a[i]);
		display(q);
		
	}
	for(i=0;i<n;i++)
	{
		dequeue(q);
		display(q);
		
	}
	
	return 0;
}
