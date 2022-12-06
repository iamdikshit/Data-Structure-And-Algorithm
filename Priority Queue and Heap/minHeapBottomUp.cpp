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

void heapDown(int heap[],int n,int i)
{
	int l = left(i);
	int r = right(i);
	int s = i;
	
	if(l<n && heap[l]< heap[i])
	{
		s = l;
	}
	
	if(r<n && heap[r]< heap[s])
	{
		s = r;
	}
	
	if(s!=i)
	{
		swap(heap[i],heap[s]);
		heapDown(heap,n,s);
	}
	
}
void buildHeap(int heap[], int n)
{
	for(int i = (n/2-1); i>=0;i--)
	{
		heapDown(heap,n,i);
	}
}

printHeap(int heap[],int n)
{
	cout<<"\n";
	for(int i = 0; i<n; i++)
	{
		cout<<heap[i]<<" ";
	}

}
int main()
{
	int n;
	cin>>n;
	int heap[n];
	for(int i=0; i<n;i++)
	{
		cin>>heap[i];
	}
	buildHeap(heap,n);
	printHeap(heap,n);
	return 0;
}
