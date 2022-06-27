#include<bits/stdc++.h>
using namespace std;


int gcd(int n,int p)
{
	if (n==0 || p==0)
	{
		return 0;
	}
	else if(n==p)
	{
		return n;
	}
	else if(n>p)
	{
		return gcd(n-p,p);
	}
	else
	{
		return gcd(n,p-n);
	}
	
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,p;
		cin>>n;
		cin>>p;
		cout<<gcd(n,p)<<endl;
	}
	return 0;
}
