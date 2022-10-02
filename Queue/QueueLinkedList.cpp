#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

// Creating node structure
struct node{
	int data;
	struct node *next;
};

// creating queue structure
struct Queue{
	struct node *front;
	struct node *rear;
};

// function for creating queue
struct Queue *createQueue()
{
	struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
	if(!q)
		return NULL;
	
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	
	if(!temp)
		return NULL;
		
	q->front=q->rear =NULL;
	return q;
	
}

// Function to return size of queue
int size(struct Queue *q)
{
	struct node *temp = q->front;
	int count = 0;
	if(q->front == NULL and q->rear==NULL)
		return 0;
		
	while(temp!=q->rear)
	{
		count++;
		temp = temp->next;
	}
	if(temp==q->rear)
		count++;
		
	return count;
}

// Return front element
int frontElement(struct Queue *q)
{
	return q->front->data;
}

//return rear element
int rearElement(struct Queue *q)
{
	return q->rear->data;
}

// Is empty function 
void isEmpty(struct Queue *q)
{
	if(q->front==NULL && q->rear==NULL)
	{
		cout<<"\nQueue is Empty";
	}
	else{
		cout<<"\nQueue is not empty";
	}
}

// Enqueue Function
void Enqueue(struct Queue *q,int data)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	if(!newnode)
	{
		cout<<"\nMemory Error";
		return;
	}
	newnode->data = data;
	newnode->next = NULL;
	
	if(q->rear==NULL)
	{
		q->front = q->rear = newnode;
	}
	
	q->rear->next = newnode;
	q->rear = newnode;
	
}
// display
void display(struct Queue *q)
{
	struct node *temp = q->front;
	if(q->front ==NULL && q->rear==NULL)
	{
		cout<<"Queue is Empty";
		return ;
	}
	cout<<"\n";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

// Dequeue Function 
int dequeue(struct Queue *q)
{
	int data;
	if(q->front==NULL)
	{
		cout<<"Queue is empty.";
		return INT_MIN;
	}
	else{
		struct node *temp = q->front;
		q->front = q->front->next;
		if(q->front==NULL)
		{
			q->rear = NULL;
		}
		data = temp->data;
		free(temp);
		return data;
	}
	
}



int main()
{
	struct Queue *q;
	q = createQueue();
	Enqueue(q,2);
	Enqueue(q,5);
	Enqueue(q,7);
	Enqueue(q,1);
	display(q);
	isEmpty(q);
	cout<<"\nFront Element : "<<frontElement(q);
	cout<<"\nRear Element : "<<rearElement(q);
	cout<<"\nDeleted Element : "<<dequeue(q);
	display(q);
	cout<<"\nFront Element : "<<frontElement(q);
	cout<<"\nRear Element : "<<rearElement(q);
	
	return 0;
}
