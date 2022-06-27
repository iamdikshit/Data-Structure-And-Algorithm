#include<bits/stdc++.h>
using namespace std;

class Searching{
	public:
	int UnorderLinear(int arr[], int n,int data)
	{
		for(int i = 0; i<n; i++)
		{
			if(arr[i]==data)
			return i;
		}
		return -1;
	}
	int OrderedLinear(int arr[], int n,int data)
	{
		for(int i = 0; i<n; i++)
		{
			if(arr[i]==data)
				return i;
			if(arr[i]>data)
				return -1;
		}
		return -1;
	}
};
int main()
{
	Searching s;
	int n;
	int arr[n];
	int data;
	cin>>n;
	for(int i = 0; i<n; i++)
	{
		cin>>arr[i];
	}
	cin>>data;
	cout<<"Unordered List Search"<<endl;
	int res =s.UnorderLinear(arr,n,data); 
	if ( res!= -1)
	cout<<data<<" Found at position "<<res+1<<endl;
	else
	cout<<data<<" is not present";
	
	
	
	return 0;
}
