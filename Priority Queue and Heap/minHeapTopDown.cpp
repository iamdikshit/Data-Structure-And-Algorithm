#include<bits/stdc++.h>

using namespace std;

int parent(int i)
{
	return (i-1)/2;
}

void insert(int heap[],int i,int val)
{
	heap[i] = val;
	while(i!=0 && heap[parent(i)]>heap[i])
	{
		swap(heap[parent(i)],heap[i]);
		i = parent(i);
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
	int n,val;
	cin>>n;
	int heap[n];
	for(int i=0; i<n;i++)
	{
		cin>>val;
		insert(heap,i,val);
	}

	printHeap(heap,n);
	return 0;
}
