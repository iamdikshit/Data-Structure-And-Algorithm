#include<bits/stdc++.h>
using namespace std;


void printnum(int n)
{
	cout<<n<<" ";
	if(n<=0)
	{
		return;
	}
	printnum(n-5);
	cout<<n<<" ";
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		printnum(n);
	}
	return 0;
}
