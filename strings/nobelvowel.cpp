#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		int count=0,i;
		cin>>str;
		for(i=0; i<str.length()-1;i++)
		{
			char ch = str[i];
			char ch2 = str[i+1];
			if(ch!='a' || ch!='e' || ch!='i' || ch!='o' || ch!='u')
			{
				if( ch2 =='a' || ch2 =='e' || ch2 =='i' || ch2 =='o' || ch2 =='u')
				{
					count++;
				}
			}
			else{
				count++;
			}
		}
		
		cout<<count<<endl;
//		if(count== str.length()-1)
//		{
//			cout<<"YES"<<endl;
//		}
//		else
//		{
//			cout<<"NO"<<endl;
//		}
		
	}
	return 0;
}
