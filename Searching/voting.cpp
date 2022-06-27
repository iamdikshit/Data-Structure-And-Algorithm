#include<bits/stdc++.h>
using namespace std;

bool searchOne(int arr[],int n)
{
	for(int i = 0; i<n; i++)
	{
		if(arr[i]==1)
		{
			return true;
		}
	}
	return false;
		
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{	int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n;i++)
		{
			cin>>arr[i];
		}
		
		if(searchOne(arr,n))
		{
			cout<<"hard"<<endl;
		}
		else
		{
			cout<<"easy"<<endl;
		}
	}
	
	return 0;
}
