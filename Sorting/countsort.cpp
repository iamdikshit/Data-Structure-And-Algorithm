#include<bits/stdc++.h>
using namespace std;

int getmax(int arr[], int n)
{
	int max = arr[0];
	for(int i = 1; i<n; i++)
	{
		if(arr[i]>max)
			max = arr[i];
	}
	return max;
}

void countsort(int arr[],int n, int k)
{
	int i,c[k+1],b[n];
	for(i = 0; i<=k;i++)
		c[i] = 0;
	
	// count frequency
	for(i = 0; i<n; i++)
		c[arr[i]]+=1;
	
	// commutative sum
	for(i = 1; i<=k; i++)
		c[i] = c[i]+c[i-1];
	
	// replacing the value
	for(i=n-1; i>=0; i--)
	{
		b[c[arr[i]]-1] = arr[i];
		c[arr[i]]--;	
	}
		
	
	for(i =0; i<n;i++)
		cout<<b[i]<<" ";
	
}
int main()
{
	int n,mx;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	mx = getmax(arr,n);

	countsort(arr,n,mx);
	return 0;
}
