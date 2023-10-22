// Pizza with 3n slices DP problem (same problem as House robbery question

#include<bits/stdc++.h>
#include<vector>

using namespace std;
int solv(int index,int endIndex,vector<int>&pizza,int n)
{
	if(n==0 ||index>endIndex)
	{
		return 0;
	}
	
	// Take
	int take = pizza[index] + solv(index+2,endIndex,pizza,n-1);
	// notTake
	int notTake = 0 + solv(index+1,endIndex,pizza,n);
	return max(take,notTake);
}
// Recursion + memoization

int solvMemo(int index,int endIndex,vector<int>&pizza,int n,vector< vector<int> > dp){
	if(n==0 ||index>endIndex)
	{
		return 0;
	}
	if(dp[index][n]!=-1)
		return dp[index][n];
	
	// Take
	int take = pizza[index] + solvMemo(index+2,endIndex,pizza,n-1,dp);
	// notTake
	int notTake = 0 + solvMemo(index+1,endIndex,pizza,n,dp);
	dp[index][n] = max(take,notTake);
	return dp[index][n];
}

int solvTab(vector<int>&pizza,int k )
{
	vector< vector<int> > dp(k+2,vector<int>((k+2),0));
	vector< vector<int> > dp2(k+2,vector<int>((k+2),0));
	for(int i = k-2; i>=0; i--)
	{
		for(int n = 1; n<=k/3;n++)
		{
				int take = pizza[i] + dp[i+2][n-1];
				// notTake
				int notTake = 0 + dp[i+1][n];
				
				dp[i][n] = max(take,notTake);
		}
	}
	int case1 =  dp[0][k/3];
	
	for(int i = k-1; i>=1; i--)
	{
		for(int n = 1; n<=k/3;n++)
		{
				int take = pizza[i] + dp2[i+2][n-1];
				// notTake
				int notTake = 0 + dp2[i+1][n];
				
				dp2[i][n] = max(take,notTake);
		}
	}
	
	int case2 =  dp2[1][k/3];
	
	return max(case1,case2);
	
}

int main()
{
	int k;
	cin>>k;
	vector<int> pizza(k);
	for(int i =0; i<k;i++)
	{
		cin>>pizza[i];
	}
//	// case 1 include first index
//	int case1 = solv(0,k-2,pizza,k/3);
//	// case 2 include last index
//	int case2 = solv(1,k-1,pizza,k/3);
	
//	vector< vector<int> > dp(k+1,vector<int>((k/3+1),-1));
//	// case 1 include first index
//	int case1 = solvMemo(0,k-2,pizza,k/3,dp);
//	// case 2 include last index
//	int case2 = solvMemo(1,k-1,pizza,k/3,dp);

	cout<<solvTab(pizza,pizza.size());
	
	
	return 0;
}
