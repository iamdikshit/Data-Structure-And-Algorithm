
#include<bits/stdc++.h>
using namespace std;

// Left leaf node
int left(int i)
{
	return 2*i+1;
}

// Right leaf node
int right(int i)
{
	return 2*i+2;
}

void heapify(int arr[], int N, int i)
{
  
    // Initialize largest as root
    int s = i;
  
    // left = 2*i + 1
    int l = left(i);
  
    // right = 2*i + 2
    int r = right(i);
  
 
    if (l < N && arr[l] < arr[i])
        s = l;
  
  
    if (r < N && arr[r] < arr[s])
        s = r;
  
    // If largest is not root
    if (s != i) {
        swap(arr[i], arr[s]);
        heapify(arr, N, s);
    }
}
  
// Main function to do heap sort
void heapSort(int arr[], int N)
{
  
    // Build heap 
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
  
    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {
  
        // Move current root to end
        swap(arr[0], arr[i]);
  
        heapify(arr, i, 0);
    }
}

void Print(int arr[],int n)
{
	
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i<n; i++)
	{
		cin>>arr[i];
	}
	heapSort(arr,n);
	Print(arr,n);
		
	}
	
	return 0;
}
