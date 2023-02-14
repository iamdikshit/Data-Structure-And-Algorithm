#include <bits/stdc++.h>
  using namespace std;

int parent(int i)
{
	return (i-1)/2;
}
void insert(int heap[],int i,int val)
{
	heap[i]=val;
	while(i!=0 && heap[i]<heap[parent(i)])
	{
		swap(heap[i],heap[parent(i)]);
		i = parent(i);
	}
}

void heapDown(int arr[],int n,int i)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int s = i;
	
	if(l<n && arr[l]< arr[i])
	{
		s = l;
	}
	
	if(r<n && arr[r]< arr[s])
	{
		s = r;
	}
	
	if(s!=i)
	{
		swap(arr[i],arr[s]);
		heapDown(arr,n,s);
	}
	
}



void buildHeap(int heap[], int n)
{
	for(int i = (n/2-1); i>=0;i--)
	{
		heapDown(heap,n,i);
	}
}
void extract(int arr[],int n)
{
	if(n>0)
	{
		int key = arr[0];
		swap(arr[0],arr[n-1]);
		n--;
		cout<<key<<" ";
		buildHeap(arr,n);	
	}
	
	
}
void print(int arr[], int n)
{
  for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
  int main()
  {
    //write your code here
    int t;
    cin>>t;
    while(t--)
    {
      int n;
      cin>>n;
      int arr[n];
      int val;
      for(int i=0;i<n;i++)
      {
        cin>>val;
        insert(arr,i,val);
      }
      extract(arr,n);
      print(arr,n-1);
    }
    
    return 0;
  }
