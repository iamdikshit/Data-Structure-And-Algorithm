#include<bits/stdc++.h>
using namespace std;


int sum(int n)
{
	
	if(n<=0)
	{
		return n;
	}
	return n%10 + sum(n/10);
	
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<sum(n)<<endl;
	}
	return 0;
}
