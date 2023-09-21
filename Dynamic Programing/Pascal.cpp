/// Pascal's Triangle

#include<bits/stdc++.h>
using namespace std;

int findCobination(int r,int n)
{
	int res = 1;
	for(int i =0; i<n;i++)
	{
		res = res * (r-i);
		res = res/(i+1);
		
	}
	return res;
}

int main()
{
	int n,row;
	cin>>row>>n;
	cout<<findCobination(row-1,n-1);
	cout<<"\n";
	for(int i=0;i<row; i++)
	{
		cout<<findCobination(row-1,i)<<" ";
	}
	cout<<"\n";
	for(int i=0;i<row; i++)
	{
		for(int j=0;j<=i;j++)
		{
			cout<<findCobination(i,j)<<" ";
		}
		cout<<"\n";
		
	}
	
	
	return 0;
}
