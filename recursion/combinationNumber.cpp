#include<bits/stdc++.h>
#include <string>
using namespace std;
void combiNumber(int a[],string res,int  i,int n,int k)
{
	if (k==0)
	{
		cout<<res<<endl;
		return;
	}
	for(int j=i; j<n;j++)
	{
		res = res+to_string(a[j]);
		combiNumber(a,res,j+1,n,k-1);
	}
}
int main()
{
	int n,k;
	cin>>n;
	int a[n];
	for(int i = 0; i<n;i++)
	{
		cin>>a[i];
	}
	cin>>k;
	combiNumber(a,"",0,n,k);
	return 0;
}
