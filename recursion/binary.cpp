#include<bits/stdc++.h>
using namespace std;

int findbinary(int n)
{
	if(n<=0)
	{
		return 0;
	}
	
	return n%2 + 10*findbinary(n/2);
}

void printcombination(int n,int binary)
{
	if 
	
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		binary = findbinary(int n);
		if
		printcombination(n,binary);
	}
	return 0;
}
