#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

// struct Queue
typedef struct Queue{
	int front,rear;
	int capacity,size;
	int *arr;
};

// function for creating Queue
Queue *createQueue(int capacity)
{
	Queue *q = (Queue*)malloc(sizeof(Queue));
	if(!q)
	{
		return NULL;
	}
	q->capacity = capacity;
	q->front = -1;
	q->rear = -1;
	q->size = 0;
	q->arr = (int*)malloc(q->capacity*sizeof(int));
	if(!q->arr)
		return NULL;
	
	return q;
}

// size function
int size(Queue *q)
{
	return q->size;
}

// front element function
int frontElement(Queue *q)
{
	return q->arr[q->front];
}

// rear element function
int rearElement(Queue *q)
{
	return q->arr[q->rear];
}
// isfull function
int isFull(Queue *q)
{
	return (q->size ==q->capacity);
}

// isempty function
int isEmpty(Queue *q)
{
	return (q->size ==0);
}

// Enqueue function
void enqueue(Queue *q,int data)
{
	if(isFull(q))
	{
		cout<<"\nQueue is Full...";
		return;
	}
	else{
		q->rear = (q->rear+1)%q->capacity;
		q->arr[q->rear] = data;
		if(q->front==-1)
			q->front = q->rear;
		
		q->size+=1;
	}
}

// Dequeue function
int dequeue(Queue *q)
{
	int data = INT_MIN;//any min number
	if(isEmpty(q))
	{
		cout<<"\nQUEUE is Empty:";
		return data;
	}
	else{
		data = q->arr[q->front];
		if(q->front==q->rear)
		{
			q->front = q->rear = 1;
			q->size = 0;
		}
		else{
			q->front = (q->front+1)%q->capacity;
			q->size-=1;
		}
		return data;
	}
}

// Display function
void display(Queue *q)
{
	for(int i = q->front; i<=q->rear; i++)
	{
		cout<<q->arr[i]<<" ";
	}
}

int main()
{
	int capacity,n;
	cin>>capacity>>n;
	Queue *q = createQueue(capacity);
	for(int i=1;i<=n;i++)
	{
		enqueue(q,i);
	}
	display(q);
	cout<<"\n Front :"<<frontElement(q);
	cout<<"\n Rear :"<<rearElement(q);
	dequeue(q);
	cout<<"\n Front :"<<frontElement(q);
	cout<<"\n Rear :"<<rearElement(q);
	
	return 0;
}
