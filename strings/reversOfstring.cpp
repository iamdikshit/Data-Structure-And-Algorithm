#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str,str2;
		cin>>str;
		for(int i=str.length()-1; i>=0;i--)
		{
			str2 = str2 + str[i];
		}
		cout<<str2<<endl;
	}
	return 0;
}
