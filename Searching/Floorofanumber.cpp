#include<bits/stdc++.h>
using namespace std;

int floorofanumber(int arr[],int low,int high,int x)
{
	if(low>high)
		return -1;
	
	int mid = low + (high-low)/2;
	if(arr[mid]<=x)
		return	mid;
	
	if(arr[mid]>x)
		return floorofanumber(arr,low,mid-1,x);
	else
		return floorofanumber(arr,mid+1,high,x);
	
}
int main()
{
	int t,i,res;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n;
		cin>>x;
		int arr[n];
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		res = floorofanumber(arr,0,n,x);
		cout<<res<<endl;
	}
	return 0;
}
