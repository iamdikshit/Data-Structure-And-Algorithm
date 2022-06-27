#include<bits/stdc++.h>
using namespace std;

void binarysort(int arr[], int n)
{
	int i,j,temp;
	bool swapped ;
	for(i=n-1;i>=0;i--)
	{
		swapped = false;
		for(j=0; j<i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swapped = true;
			}
		}
		if(swapped == false)
			break;
	}
}
int main()
{
	int i,n;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	binarysort(arr,n);

	int mid = (0+n)/2;

	cout<<arr[mid];
	return 0;
}
