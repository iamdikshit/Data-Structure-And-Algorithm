#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

typedef struct DynamicQueue
{
	int capacity,size;
	int front,rear;
	int *arr;
};

DynamicQueue *CreateQueue(int capacity)
{
	DynamicQueue *q = (DynamicQueue*)malloc(sizeof(DynamicQueue));
	q->capacity = capacity;
	q->front = -1;
	q->rear = -1;
	q->size = 0;
	q->arr = (int*)malloc(q->capacity * sizeof(int));
	if(!q->arr)
		return NULL;
	return q;
	
}

void Resize(DynamicQueue *q)
{
	q->size = q->capacity;
	q->capacity = q->capacity*2;
	q->arr = (int*)realloc(q->arr,sizeof(int));
	if(!q->arr)
	{
		cout<<"Memory Error";
		return;
	}
	if(q->front>q->rear)
	{
		for(int i=0; i<q->front; i++)
		{
			q->arr[i+q->size] = q->arr[i];
			
		}
		q->rear = q->rear+q->size;
	}
}


// size function
int size(DynamicQueue *q)
{
	return q->size;
}

// front element function
int frontElement(DynamicQueue *q)
{
	return q->arr[q->front];
}

// rear element function
int rearElement(DynamicQueue *q)
{
	return q->arr[q->rear];
}
// isfull function
int isFull(DynamicQueue *q)
{
	return (q->size ==q->capacity);
}

// isempty function
int isEmpty(DynamicQueue *q)
{
	return (q->size ==0);
}

// Enqueue function
void enqueue(DynamicQueue *q,int data)
{
	if(isFull(q))
	{
		Resize(q);
	}

		q->rear = (q->rear+1)%q->capacity;
		q->arr[q->rear] = data;
		if(q->front==-1)
			q->front = q->rear;
		
		q->size+=1;

}

// Dequeue function
int dequeue(DynamicQueue *q)
{
	int data = INT_MIN;//any min number
	if(isEmpty(q))
	{
		cout<<"\nQueue is empty..";
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
void display(DynamicQueue *q)
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
	DynamicQueue *q = CreateQueue(capacity);
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
	enqueue(q,8);
	enqueue(q,9);
	cout<<"\n Front :"<<frontElement(q);
	cout<<"\n Rear :"<<rearElement(q);
	cout<<"\n Size : "<<size(q);
	
	return 0;
}
