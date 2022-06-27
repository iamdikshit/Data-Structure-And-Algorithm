#include<bits/stdc++.h>
using namespace std;

void binary(int n, int a[],int k)
{
	if(n<1)
	{
		for(int i =0; i<k;i++)
		{
			cout<<a[i];
		}
		cout<<endl;
	}
	else
	{
		a[n-1]=0;
		binary(n-1,a,k);
		a[n-1]=1;
		binary(n-1,a,k);
	
		
	}
	
}

int main()
{
	
	int n;
	cin>>n;
	int a[n];
	int k = n;
	binary(n,a,k);
	return 0;
	
}
