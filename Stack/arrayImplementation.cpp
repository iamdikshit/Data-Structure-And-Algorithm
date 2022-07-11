#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

struct node{
    int capacity;
    int top;
    int *array;
};

struct node *CreateStack(int capacity)
{
    struct node *S = (struct node*)malloc(sizeof(struct node));
    if(!S)
    {
         return NULL;
    }
    S->capacity = capacity;
    S->top = -1;
    S->array = (int*)malloc(S->capacity * sizeof(int));
    if(!S->array)
    {
        return NULL;
    }
    return S;
   
}

int isEmpty(struct node *S)
{
    return (S->top==-1); // if condition is true than return 1 else return 0.
}

int size(struct node *S)
{
    return (S->top +1);
}

int isFull(struct node *S)
{
    return (S->top == S->capacity-1);
}

void push(struct node *S, int data)
{
    if(isFull(S))
    {
        cout<<"Stack is full";
    }
    else{
        S->array[++S->top] = data;
    }
}

int pop(struct node *S)
{
    if(isEmpty(S))
    {
        cout<<"Stack is Empty";
        return INT_MIN;
    }
    else{
        return (S->array[S->top--]);
    }
}

int peek(struct node*S)
{
    if(isEmpty(S))
    {
        cout<<"Stack is empty";
        return INT_MIN;

    }
    else{
        return (S->array[S->top]);
    }
}

void Delete(struct node* S)
{
    if(S)
    {
        if(S->array)
            free(S->array);
            free(S);
    }
}
// main function
int main()
{
    int i =0, capacity = 15;
    // Creating stack
    struct node *S = CreateStack(capacity);
    for(i=0;i<capacity; i++ )
    {
        push(S,i);
    }
    cout<<"Top of the element : "<<peek(S)<<"\n";
    cout<<"Stack size : "<<size(S)<<"\n";
    for(i=0;i<capacity; i++ )
    {
        pop(S);
    }
    if(isEmpty(S))
    {
        cout<<"Stack is empty!";
    }
    else{
        cout<<"Stack is Full";

    }
    Delete(S);
    
    return 0;
}