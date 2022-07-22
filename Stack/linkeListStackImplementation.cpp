#include<bits/stdc++.h>
#include<cstdlib>
#include<limits.h>

using namespace std;

struct node{
	int data;
	node *next;
};

struct Stack{
	node *top;
};

// create stack
struct  Stack *createStack()
{
	struct Stack *stk;
	stk =(struct Stack*)malloc(sizeof(struct Stack));
	stk->top = NULL;
	return stk;
}
// isEmpty function
int isEmpty(struct Stack *S)
{
	return (S->top==NULL);
}


// peek function
int peek(struct Stack *S)
{
	if(isEmpty(S))
	{
		cout<<"Stack is Empty! ";
		return INT_MIN;
	}
	return S->top->data;
}
// size function
int size(struct Stack *S)
{
	struct node *temp;
	int count = 0;
	if(isEmpty(S))
	{
		cout<<"Stack is empty!";
		return 0;
	}
	temp = S->top;
	while(temp)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
//push functions
void push(struct Stack *S,int data)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	if(!temp)
	{
		cout<<"Heap overflow!";
		return;
	}
	temp->data = data;
	temp->next = S->top;
	S->top = temp;
}
// pop function
int pop(struct Stack *S)
{
	int data;
	struct node *temp;
	if(isEmpty(S))
	{
		cout<<"Stack is empty!";
		return INT_MIN;
	}
	temp = S->top;
	S->top = S->top->next;
	data = temp->data;
	free(temp);
	return data;
}
//delete function
void deleteStack(struct Stack *S)
{
	struct node *p,*temp;
	p = S->top;
	while(p)
	{
		temp = p->next;
		p = p->next;
		free(temp);
	}
	free(S);
}


int main()
{
	//create stack
	struct Stack *S = createStack();
	for(int i = 1; i<=6; i++)
	{
		push(S,i);
	}
	cout<<"Peek Element of the Stack : "<<peek(S)<<endl;
	cout<<"Size of Stack : "<<size(S)<<endl;
	for(int i = 0; i<3; i++)
	{
		cout<<"POPPED element : "<<pop(S)<<endl;
	}
	cout<<"Peek Element of the Stack : "<<peek(S)<<endl;
	cout<<"Size of Stack : "<<size(S)<<endl;
	if(isEmpty(S))
	{
		cout<<"Stack is empty!"<<endl;
	}
	else{
		cout<<"Stack is not empty!"<<endl;
	}
	deleteStack(S);
	
	return 0;
}
