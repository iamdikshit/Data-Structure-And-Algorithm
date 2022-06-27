#include <iostream>  
using namespace std;  
  
/* Function to merge the subarrays of a[] */  
void merge(int a[], int beg, int mid, int end)    
{   int i,j,k;
  	int n1 = mid-beg+1,n2 = end-mid;
  	int leftarr[n1];
  	int rightarr[n2];
  	for ( i = 0; i < n1; i++)    
    	leftarr[i] = a[beg + i];    
    for (j = 0; j < n2; j++)    
    	rightarr[j] = a[mid + 1 + j]; 
  		
  	i=0;
  	j=0;
  	k=beg;
  	while(i<n1 && j<n2)
  	{
  		if(leftarr[i]<=rightarr[j])
  		{
  			a[k]=leftarr[i];
			  i++;		
		}
		else
		{
			a[k]=rightarr[j];
			j++;
		}
		k++;
	}
	
	while(i<n1)
	{
		a[k]=leftarr[i];
		i++;
		k++;
	}
	
	while(j<n2)
	{
		a[k]=rightarr[j];
		j++;
		k++;
	}
}    

  
void mergeSort(int a[], int beg, int end)  
{  
    if(beg<end)
    {
    	int mid = (beg+end)/2;
    	mergeSort(a,beg,mid);
    	mergeSort(a,mid+1,end);
    	merge(a,beg,mid,end);
	}
}  
  
/* Function to print the array */  
void printArray(int a[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout<<a[i]<<" ";  
}  
  
int main()  
{  	int n;
	cin>>n;
	int a[n];
	for(int i =0; i<n;i++)
	{
		cin>>a[i];
	}
    cout<<"Before sorting array elements are - \n";  
    printArray(a, n);  
    mergeSort(a, 0, n - 1);  
    cout<<"\nAfter sorting array elements are - \n";  
    printArray(a, n);  
    return 0;  
}  
