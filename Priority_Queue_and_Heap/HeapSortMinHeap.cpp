/*
	Heap sort using min heap.
*/

#include<bits/stdc++.h>
using namespace std;

int left(int i)
{
	return (2*i+1); 
}

int right(int i)
{
	return (2*i+2);
}

void heapify(int heap[],int n, int i)
{
	int l = left(i);
	int r = right(i);
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
		swap(heap[i],heap[i]);
		heapify(heap,n,s);
	}
}

void buildHeap(int heap[],int n)
{
	for(int i = n/2-1; i>=0; i--)
	{
		heapify(heap,n,i);
	}
}
void heapSort(int heap[],int n)
{
	buildHeap(heap,n);
	
	for(int i=n-1; i>0;i--)
	{
		swap(heap[0],heap[i]);
		heapify(heap,i,0);
	}
	
}

void print(int heap[], int n)
{
	cout<<"\n";
	for(int i=n-1; i>=0;i--)
	{
		cout<<heap[i]<<" ";
	}
}
int main()
{
	int n;
	cin>>n;
	int heap[n];
	for(int i = 0; i<n; i++)
	{
		cin>>heap[i];
	}
	heapSort(heap,n);
	print(heap,n);
	return 0;
	
}
