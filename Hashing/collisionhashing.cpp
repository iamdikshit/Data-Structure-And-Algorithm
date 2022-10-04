#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a[5]= {1,145,156,66,43};
	int hash[11];
	for(int i=0;i<11;i++)
	{
		hash[i]= -1;
	}
	for(int i=0;i<5;i++)
	{
		hash[a[i]%11]= a[i];
	}
	for(int i=0;i<11;i++)
	{
		if(hash[i]!=-1)
		{
			cout<<"\nElement present at slot index "<<i<<" is "<<hash[i];
		}
		
	}
	int n;
	cout<<"\nEnter value to be search: ";
	cin>>n;
	if(hash[n%11]==-1)
	{
		cout<<"\n False";
	}
	else{
		cout<<"\n True";
	}
	
	return 0;
}
