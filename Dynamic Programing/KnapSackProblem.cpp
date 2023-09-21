// Knapsack Problem

#include<bits/stdc++.h>
using namespace std;
// recursion 
int knapsackRecursion(int index,int weight[],int value[],int capacity){
	if(index==0)
	{
		if(weight[index]<=capacity)
			return value[index];
		else
			return 0;
	}
	
	int include = value[index] + knapsackRecursion(index-1,weight,value,capacity-weight[index]);
	int exclude = 0 + knapsackRecursion(index-1,weight,value,capacity);
	int ans = max(exclude,include);
	
	return ans;
}

// Knapsack Memoization
int knapsackRecursionMemo(int index,int weight[],int value[],int capacity,vector< vector<int> > dp){
	if(index==0)
	{
		if(weight[index]<=capacity)
			return value[index];
		else
			return 0;
	}
	if(dp[index][capacity]!=-1)
		return dp[index][capacity];
		
	int include = value[index] + knapsackRecursionMemo(index-1,weight,value,capacity-weight[index],dp);
	int exclude = 0 + knapsackRecursionMemo(index-1,weight,value,capacity,dp);
	dp[index][capacity] = max(exclude,include);
	return dp[index][capacity];
}

// KnapSack Tabulation
int knapsackRecursionTabulation(int index,int weight[],int value[],int capacity){
	
	vector< vector<int> > dp(numberOfItems,vector<int>(capacity+1,0));

	if(weight[index]<=capacity)
		dp[index][capacity] =  value[index];
	else
		dp[index][capacity] =  0;

	if(dp[index][capacity]!=-1)
		return dp[index][capacity];
	
		
	int include = value[index] + knapsackRecursionTabulation(index-1,weight,value,capacity-weight[index]);
	int exclude = 0 + knapsackRecursionTabulation(index-1,weight,value,capacity);
	dp[index][capacity] = max(exclude,include);
	return dp[index][capacity];
}


int main()
{
	int capacity; // knapsack capacity
	cin>>capacity;
	int numberOfItems;
	cin>>numberOfItems;
	int weight[numberOfItems];
	int value[numberOfItems];
	
	for(int i=0; i<numberOfItems; i++)
	{
		cin>>weight[i];
		cin>>value[i];
	}
	
	vector< vector<int> > dp(numberOfItems,vector<int>(capacity+1,-1));
	
//	cout<<knapsackRecursion(numberOfItems-1, weight,value,capacity);
	cout<<knapsackRecursionMemo(numberOfItems-1,weight,value,capacity,dp);
	return 0;
}

