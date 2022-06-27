#include<bits/stdc++.h>
using namespace std;


void premutation(int zeroes,int ones,string output, vector<string>&perm)
{
	if(zeroes == 0)
	{
		for(int i=0; i<ones; i++)
			output+="1";
		
		perm.push_back(output);
		return;
	}
	else if(ones==0)
	{
		for(int i=0; i<zeroes; i++)
			output+="0";
		
		perm.push_back(output);
		return;
	}
	
	premutation(zeroes-1,ones,output+"0",perm);
	premutation(zeroes,ones-1,output+"1",perm);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,ones=0,zeroes=0;
	cin>>n;
	
	while(n>0)
	{
		if(n&1)
			ones++;
		else
			zeroes++;
		
		n = n>>1;
	}
	string output = "";
	vector<string>perm;
	premutation(zeroes,ones,output,perm);
	
	sort(perm.begin(),perm.end());
	
	for(int i = 0; i<perm.size();i++)
		cout<<perm[i]<<endl;
		
	}
	
	return 0;
}
