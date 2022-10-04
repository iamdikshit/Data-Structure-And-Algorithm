#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a[7]= {1,145,689,34,56,33,43};
	int hash[15];
	for(int i=0;i<15;i++)
	{
		hash[i]= -1;
	}
	for(int i=0;i<7;i++)
	{
		hash[a[i]%10]= a[i];
	}
	for(int i=0;i<15;i++)
	{
		if(hash[i]!=-1)
		{
			cout<<"\nElement present at slot index "<<i<<" is "<<hash[i];
		}
		
	}
	int n;
	cout<<"\nEnter value to be search: ";
	cin>>n;
	if(hash[n%10]==-1)
	{
		cout<<"\n False";
	}
	else{
		cout<<"\n True";
	}
	
	return 0;
}
