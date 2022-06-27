#include<bits/stdc++.h>
using namespace std;
void revers(string str,int k, int n)
{
	if(k==n)
	{
		return;
	}
	revers(str,k+1,n);
	cout<<str[k]; 
}

int main()
{
	int t,n;
	cin>>t;

	while(t--)
	{
		string str;
		cin>>str;
		n = str.length();
		revers(str,0,n); 
	}
	return 0;
}
