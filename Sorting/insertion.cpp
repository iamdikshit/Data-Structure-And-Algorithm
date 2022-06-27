#include<bits/stdc++.h>
using namespace std;

void insertionsort(int arr[], int n)
{
	int i,j,v;
	for(i = 1; i<n; i++)
	{
		v = arr[i];
		j = i;
		while(arr[j-1]>v && j>=1)
		{
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = v;
	}
	
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i =0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	insertionsort(arr,n);
	return 0;
}
