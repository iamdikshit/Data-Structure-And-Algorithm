/*
	Direct Hashing
	We will make direct Hashing table and find 
	the frequency of the element in an other array.
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int freq[n];
	for(i=0;i<n;i++)
	{
		freq[a[i]]++;
	}
	for(i=0;i<n;i++)
	{
		if(freq[i]!=0)
			cout<<"Frequency of "<<i<<" is "<<freq[i]<<"\n";
	}
	return 0;
}
