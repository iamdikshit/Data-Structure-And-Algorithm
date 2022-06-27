#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,t;
	
	cin>>t;
	while(t--)
	{	int j = 0;
		string str1,str2;
		cin>>str1>>str2;
		
		for(i=0;i<str1.length() && j<str2.length(); i++)
		{
			if(str1[i]==str2[j])
				j++;
		}
		
		if(j==str2.length())
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
		
	}
}
