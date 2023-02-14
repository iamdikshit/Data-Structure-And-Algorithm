/*
	***************************************************************
	HEAP DECREASE PROBLEM
		Algorithm
		- Build min heap using indexing method (insert one by one)
		- Replace key value with last value of heap
		  Reduce the size of heap and heapify from k to n-1 index
	***************************************************************
*/
#include<bits/stdc++.h>

using namespace std;

int parent(int i )
{
	return (i-1)/2;
}

void heapify(int heap[],int i,int n)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int s = i;
	
	if(l<n && heap[l]<heap[i])
	{
		s = l;
	}
	
	if(r<n && heap[r]<heap[s])
	{
		s = r;
	}
	
	if(s!=i)
	{
		swap(heap[i],heap[s]);
		heapify(heap,s,n);
	}
}

// insert function for inserting element into heap one by one 
void insert(int heap[],int i,int val)
{
	heap[i]=val;
	while(i!=0 && heap[parent(i)]>heap[i])
	{
		swap(heap[parent(i)],heap[i]);
		i = parent(i);
	}
}


void removeKey(int heap[],int key,int n)
{
		key = key-1;
		heap[key] = INT_MIN;
		while(key!=0 && heap[parent(key)>heap[key]])
		{
			swap(heap[parent(key)],heap[key]);
			key = parent(key);
		}
		swap(heap[0],heap[n-1]);
		
		heapify(heap,0,n-1);
	
}
void print(int heap[],int n)
{
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<heap[i]<<" ";
	}
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,val,key;
		cin>>n>>key;
		int heap[n];
		for(int i=0;i<n;i++)
		{
			cin>>val;
			insert(heap,i,val);
		}
		print(heap,n);
		removeKey(heap,key,n);
		print(heap,n-1);
	}
}
