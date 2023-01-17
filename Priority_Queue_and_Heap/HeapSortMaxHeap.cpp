/*************************************************
@HeapSort
@Steps For HeapSort
	- Heapify the given array
	- For the HeapSort we can delete the max element
	  from the heap by replacing it with last element
	  and reducing the size of the heap.
	- Repeat the step 2 until size of heap is greater
	  than 1
**************************************************/
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
  
    // If left child is larger than root
    if (l < N && arr[l] > arr[s])
        s = l;
  
    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[s])
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
  
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void Print(int arr[],int n)
{
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}


int main()
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
	return 0;
}
