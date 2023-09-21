// De arrangements


#include<bits/stdc++.h>
#include<vector>
using namespace std;

// recursion
int deArrangements(int n)
{
//	base case
	if(n==0 || n==1)
		return 0;
	
	if(n==2)
		return 1;
	
	int ans = (n-1)*(deArrangements(n-2) + deArrangements(n-1));
	return ans;
}

// recursion + memoization
int deArrangementsMemo(int n, vector<int> dp)
{
	// base case
	if(n==0 || n==1)
		return 0;
	
	if(n==2)
		return 1;
	
	// check if dp has contain answer
	if(dp[n]!=-1)
		return dp[n];
		
	dp[n] = (n-1) * (deArrangementsMemo(n-2,dp) + deArrangementsMemo(n-1,dp));
	return dp[n];
}

// Tabulation

//int tabulationDeArr(int n)
//{
//	vector<int> dp(n+1,0);
//	dp[1] = 0;
//	dp[2] = 1;
//	for(int i=3; i<=n;i++)
//	{
//		int first = dp[i-2];
//		int second = dp[i-1];
//		int sum = first + second;
//		dp[i] = ((i-1)*sum);
//	
//	}
//	return dp[n];
//}

int tabulationDeArr(int n)
{
	
	int first = 0;
	int second = 1;
	for(int i=3; i<=n;i++)
	{
	
		int sum = second + first;
		int ans = ((i-1)*sum);
		first = second;
		second = ans;
	
	}
	return second;
}
int main()
{
	int n;
	cin>>n;

//	vector<int> dp(n+1,-1);
	
//	cout<<deArrangements(n);
//	cout<<deArrangementsMemo(n,dp);
	cout<<tabulationDeArr(n);
	
}
