#include<bits/stdc++.h>
using namespace std;

void k_string(int n,int a[], int k, int m)
{
	if(n<1)
	{
		for(int i=0; i<m;i++)
		{
			cout<<a[i];
		}
		cout<<endl;
	}
	else
	{
		for(int j = 0; j<k; j++)
		{
			a[n-1] = j;
			k_string(n-1,a,j,m);
		}
	}
}
int main()
{
	int n;
	int k;
	cin>>n;
	cin>>k;
	int a[n];
	int m = n;
	k_string(n,a,k,m);
	return 0;
}
