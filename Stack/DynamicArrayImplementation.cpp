#include<bits/stdc++.h>
#include<cstdlib>
#include<limits.h>

using namespace std;

struct Stack{
    int capacity;
    int top;
    int *array;
};

struct Stack *createStack(int capacity)
{
    struct Stack *S = (struct Stack*)malloc(sizeof(struct Stack));
    if(!S)
    {
        return NULL;
    }
    S->capacity = capacity;
    S->top = -1;
    S->array = (int*)malloc(S->capacity * sizeof(int));
    if(!S->array)
        return NULL;
    return S;
}

// function to check stack is empty or not;
int isEmpty(struct Stack *S)
{
    return (S->top == -1);
}

// function to check stack is full or not
int isFull(struct Stack *S)
{
    return (S->top == S->capacity-1);
}

void doubleStack(struct Stack *S)
{
	if(isFull(S)){
		S->capacity = S->capacity * 2;
		S->array = (int*)realloc(S->array,S->capacity*(sizeof(int)));
	}
}

int peek(struct Stack *S)
{
	if(!isEmpty(S))
	{
		return S->array[S->top];
	}
	else{
		cout<<"Stack is Empty..!";
		return INT_MIN;
	}
}

void push(struct Stack *S,int data)
{
	if(isFull(S))
		doubleStack(S);
	S->array[++S->top]=data;
	
}

int pop(struct Stack *S){
	if(isEmpty(S))
	{
		cout<<"Stack is Empty!";
		return INT_MIN;
	}
	return S->array[S->top--];
	
}
int size(struct Stack *S){
	return (S->top+1);
}

void deleteStack(struct Stack *S){
	if(S)
	{
		if(S->array)
		{
			free(S->array);
			free(S);
		}
	}
}

void printStack(struct Stack *S)
{
	int cursor = S->top;
	for(int i =0; i<=cursor; i++)
	{
		cout<<S->array[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int capacity = 5;
	// Create stack
	struct Stack *S = createStack(capacity);
	for(int i=0;i<2*capacity; i++)
	{
		push(S,i);
	}
	cout<<"Top element is "<<peek(S);
	cout<<"Size of the Stack is : "<<size(S)<<endl;
	printStack(S);
	for(int i =0; i<capacity; i++)
	{
		cout<<"Popped element is : "<<pop(S)<<endl;
	}
	if(isEmpty(S))
	{
		cout<<"Stack is empty!";
	}
	else{
		cout<<"Stack is not empty!";
	}
	
	deleteStack(S);
    return 0;
}
