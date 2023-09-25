// Minimum traveling cost

#include<bits/stdc++.h>
#include<vector>
using namespace std;

// Recursion
int solv(int n,int days[],int cost[],int index)
{
	if(index>=n)
		return 0;
	
	// If we select 1 day pass
	int option1 = cost[0] + solv(n,days,cost,index+1);
	
	// if we select 7 Day pass then we have to check for dates come in between 7 days
	int i;
	for( i=index; i<n && (days[i]<days[index]+7); i++);
	int option2 = cost[1] + solv(n,days,cost,i);
	
	// if we select 30 Day pass then we have to check for dates come in between 30 days
	for( i=index; i<n && days[i]<days[index]+30; i++);
	int option3 = cost[2] + solv(n,days,cost,i);
	
	return min(option1,min(option2,option3));
}

// Recursion + Memoization
int solvMemo(int n,int days[],int cost[],int index,vector<int> dp)
{
	if(index>=n)
		return 0;
	
	
	// check cost is present in dp then return cost
	if(dp[index]!=-1)
		return dp[index];
	// If we select 1 day pass
	int option1 = cost[0] + solvMemo(n,days,cost,index+1,dp);
	
	// if we select 7 Day pass then we have to check for dates come in between 7 days
	int i;
	for( i=index; i<n && (days[i]<days[index]+7); i++);
	int option2 = cost[1] + solvMemo(n,days,cost,i,dp);
	
	// if we select 30 Day pass then we have to check for dates come in between 30 days
	for( i=index; i<n && days[i]<days[index]+30; i++);
	int option3 = cost[2] + solvMemo(n,days,cost,i,dp);
	
	dp[index] = min(option1,min(option2,option3));
	return dp[index];
}

// Tabulation Method

int solvTab(int n,int days[],int cost[])
{
	vector<int> dp(n+1,INT_MAX);
	
	dp[n] = 0;
	
	for(int k = n-1; k>=0; k--)
	{
		// option 1
		int option1 = cost[0] + dp[k+1];
//		option2 
		int i;
		for( i=k; i<n && (days[i]<days[k]+7); i++);
		int option2 = cost[1] + dp[i];
		// option 3
		for( i=k; i<n && days[i]<days[k]+30; i++);
		int option3 = cost[2] + dp[i];
		
		dp[k] = min(option1,min(option2,option3));
	}
	return dp[0];
}


int main(){
	int n;
	cin>>n;
	int days[n];
	int cost[3];
	
	// Days in which you want to travell
	for(int i = 0; i<n; i++)
	{
		cin>>days[i];
	}
		
	
	for(int i=0; i<3; i++)
	{
		cin>>cost[i];
	}
		
	// Recursion
//	cout<<"cost : "<<solv(n,days,cost,0);
	
	//Recursion + memoization
//	vector<int> dp(n+1,-1);
//	cout<<"cost : "<< solvMemo(n,days,cost,0,dp);

// Tabulation
	cout<<"cost : "<<solvTab(n,days,cost);
	return 0;
}
