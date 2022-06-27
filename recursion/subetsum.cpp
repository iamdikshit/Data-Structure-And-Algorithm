#include<bits/stdc++.h>
using namespace std;
void findsubset(int i,int n,int a[],int sum, vector<int> totalsum)
{
	if(i==n)
	{
		totalsum.push_back(sum);
		return;
	}
	else
	{
		findsubset(i+1,n,a,sum+a[i],totalsum);
		findsubset(i+1,n,a,sum,totalsum);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		vector<int> totalsum;
		int sum = 0;
		cin>>n;
		int a[n];
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}
		for(int i=0; i<n; i++)
		{
			cout<<a[i];
		}
		
		findsubset(0,n,a,sum,totalsum);
		int s = 0;
		
		for (int i = 0; i < totalsum.size(); i++)
        {
        	cout<<totalsum[i];
        	//s = s + totalsum[i];
		}
       	
		cout<<s;
		
	}
	return 0;
}
