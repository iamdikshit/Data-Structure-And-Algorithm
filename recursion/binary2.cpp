#include<bits/stdc++.h>
using namespace std;
void binarycombi(int a[],int n, int k)
{
	if (k==n)
	{
		for(int i=0; i<k; i++)
		{
			cout<<a[i];
		}
		cout<<endl;
		return;
	}
	
	if(a[k-1]==0)
	{
		a[k]=0;
		binarycombi(a,n,k+1);
		a[k]=1;
		binarycombi(a,n,k+1);
	}
	else
	{
		a[k]=0;
		binarycombi(a,n,k+1);
		
	}
}

int main()
{
	int t,n;
	cin>>t;

	while(t--)
	{
		cin>>n;
		int a[n];
		a[0] = 0;
		binarycombi(a,n,1);
		a[0]=1;
		binarycombi(a,n,1);
		
	}
	return 0;
}
