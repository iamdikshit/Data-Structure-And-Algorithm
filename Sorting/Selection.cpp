#include<bits/stdc++.h>
using namespace std;
void SelectionSort(int arr[], int n)
{
	int min,temp;
	for(int i = 0; i<n-1;i++)
	{
		min = i;
		for(int j=i; j<n; j++)
			{
				if(arr[j]<arr[min])
				{
					min = j;
				}
			}
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
	
//	display 
	
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	SelectionSort(arr,n);
	return 0;
}
