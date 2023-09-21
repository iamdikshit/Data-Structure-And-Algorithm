// Minimum number of coins required to get the target value

#include<bits/stdc++.h>
#include<vector>
using namespace std;

/*
******************************************************
Recursion
int miniCoin( int target,int coins[],int n)
{
	if(target==0)
		return 0;
	
	if(target<0)
		return INT_MAX;
		
	int mini = INT_MAX;
	
	for(int i = 0; i<n; i++)
	{
		// calling function and target is decrement by coins
		int ans = miniCoin(target - coins[i],coins,n);
		
		// check for minimum value
		if(ans!=INT_MAX)
			mini = min(mini,1+ans);//here 1 + ans means we consider the first coin
	}
	
	return mini;
}

******************************************************
*/


/*
*********************************************
Recursion + memoization
*********************************************
*/

int miniCoin( int target,int coins[],int n,vector<int> dp)
{
	if(target==0)
		return 0;
	
	if(target<0)
		return INT_MAX;
	
	if(dp[target]!=-1)
		return dp[target];
		
	int mini = INT_MAX;
	
	for(int i = 0; i<n; i++)
	{
		// calling function and target is decrement by coins
		int ans = miniCoin(target - coins[i],coins,n,dp);
		
		// check for minimum value
		if(ans!=INT_MAX)
			mini = min(mini,1+ans);//here 1 + ans means we consider the first coin
	}
	dp[target] = mini;
	return mini;
}

int main()
{
	int n;
	cin>>n;
	int coins[n];
	for(int i=0; i<n;i++)
	{
		cin>>coins[i];
	}
	
	int target;
	cin>>target;
	vector<int> dp(target+1,-1);
	int ans = miniCoin(target,coins,n,dp);
	

	if(ans==INT_MAX)
		cout<<-1;
	else
		cout<<"\nMinimum number of coin to make "<<target<<" is "<<ans;
	return 0;
}
