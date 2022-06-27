#include<bits/stdc++.h>

using namespace std;

int binary(int arr[],int data,int low,int high)
{
	if(low>high)
		return -1;
	
	int mid = low+(high-low)/2;
	if(arr[mid]==data)
		return mid;
	
	if(arr[mid]>data)
		return binary(arr,data,low,mid-1);
	else
		return binary(arr,data,mid+1,high);
}
int main()
{
	int n,data,i,res;
	cin>>n;
	int arr[n];
	for(i=0; i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>data;
	res = binary(arr,data,0,n-1);
	if(res!=-1)
	{
		cout<<data<<" Found at position "<<res+1<<endl;
	}
	else
	{
		cout<<data<<" is not present";
	}
	return 0;
}
