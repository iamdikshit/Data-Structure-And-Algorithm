/*
*****************************************
Maximum sum of non-adjacent element usind DP

Approach 1 : Recursion
Approach 2 : Recursion memoization
Approach 3 : Tabulation
Approach 4 : Space optimization

*****************************************
*/

#include<bits/stdc++.h>
#include<vector>

using namespace std;

// Recursion method
int maxNumRecursion(int nums[],int n)
{
	// base case
	if(n<0)
		return 0;
	
	if(n==0)
		return nums[0];
	
	
	// including
	int include = maxNumRecursion(nums,n-2) + nums[n];
	int exclude = maxNumRecursion(nums,n-1) + 0;
	
	return max(include,exclude);
}

// Recursion + Memoization
int maxNumRecurMemo(int nums[],int n,vector<int> dp)
{
	// base case
	if(n<0)
		return 0;
	
	if(n==0)
		return nums[0];
	
	if(dp[n]!=-1)
		return dp[n];
	
	// including
	int include = maxNumRecursion(nums,n-2) + nums[n];
	int exclude = maxNumRecursion(nums,n-1) + 0;
	dp[n] = max(include,exclude);
	return dp[n];
}

// Tabulation
int maxNumTabulation(int nums[],int n)
{
	vector<int> dp(n,0);
	
	dp[0] = nums[0];
	for(int i = 1; i<n; i++)
	{
		int include = dp[i-2] + nums[i];
		int exclude = dp[i-1] + 0;
		dp[i] = max(include,exclude);
	}
	return dp[n-1];
	
}

int maxNumSpace(int nums[],int n)
{
	int prev2 = 0;
	int prev = nums[0];
	for(int i=1;i<n; i++)
	{
		int incl = prev2 + nums[i];
		int exl = prev + 0;
		int ans = max(incl,exl);
		prev2 = prev;
		prev = ans;
	}
	return prev;
}
int main()
{
	int n;
	cin>>n;
	int nums[n];
	for(int i =0; i<n;i++)
	{
		cin>>nums[i];
	}
	
	// Recursion method
//	cout<<maxNumRecursion(nums,n-1);
	
	// Recursion memoization
//	vector<int> dp(n,-1);
//	cout<<maxNumRecurMemo(nums,n-1,dp);
	
	// Tabulation method
//	cout<<maxNumTabulation(nums,n);

	// space optimization
	cout<<maxNumSpace(nums,n);
	return 0;
}
