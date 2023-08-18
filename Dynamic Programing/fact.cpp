// Factorial using DP


#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin>>n;
	int dp[n];
	
	dp[0] = 1;
	dp[1] = 1;
	for(int i=2; i<=n; i++)
	{
		dp[i] = i * dp[i-1];
	}
	cout<<dp[n];
	return 0;
}
