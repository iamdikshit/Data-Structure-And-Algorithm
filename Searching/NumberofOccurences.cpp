#include<bits/stdc++.h>
using namespace std;

void numberOfoccurences(char arr[],int n)
{
	int count = 0;
	for(int i=0; i<n; i++)
	{
		if(arr[i]=='x')
		{
			count++;
		}
	}
	cout<<count<<endl;
}
int main()
{
	int t,i;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		char arr[n];
		for(i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		numberOfoccurences(arr,n);
	}
	return 0;
}
