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
	int ans=0;
	if(weight[index]<=capacity)
	{
		int include = value[index] + knapsackRecursion(index-1,weight,value,capacity-weight[index]);
		int exclude = 0 + knapsackRecursion(index-1,weight,value,capacity);
		ans = max(exclude,include);
	}
	
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
		
	if(weight[index]<=capacity)
	{
		int include = value[index] + knapsackRecursion(index-1,weight,value,capacity-weight[index]);
		int exclude = 0 + knapsackRecursion(index-1,weight,value,capacity);
		dp[index][capacity] = max(exclude,include);
	}
	return dp[index][capacity];
}

// KnapSack Tabulation
int knapsackRecursionTabulation(int n,int weight[],int value[],int capacity){
	
	vector< vector<int> > dp(n,vector<int>(capacity+1,0));

	for(int w = weight[0]; w<=capacity; w++)
	{
		if(weight[w]<=capacity)
		{
			dp[0][w] = value[0];
		}
		else
			dp[0][w] = 0;
	}
	
	
	// loop for rows
	for(int row = 1; row<n; row++)
	{
		for(int col = 1; col<=capacity; col++)
		{
			
			if(weight[row]<=col)
			{
				int include = value[row] + dp[row-1][col-weight[row]];
				int exclude = 0 + dp[row-1][col];
				dp[row][col] = max(exclude,include);
			}
			
		}
	}
		
	return dp[n-1][capacity];
}


// space optimication
int knapsackTwoArray(int n,int weight[],int value[],int capacity)
{
	vector<int> prev(n,0);
	vector<int> current(capacity+1,0);
	for(int w = weight[0]; w<=capacity; w++)
	{
		if(weight[w]<=capacity)
		{
			prev[w] = value[0];
		}
		else
			prev[w] = 0;
	}
	
	for(int row = 1; row<n; row++)
	{
		for(int col = 1; col<=capacity; col++)
		{
			
			if(weight[row]<=col)
			{
				int include = value[row] + prev[col-weight[row]];
				int exclude = 0 + prev[col];
				current[col] = max(exclude,include);
			}
			
		}
		prev = current;
	}
	
	return prev[n-1];
	
	
}

// single array optimization

int knapsackSingleArray(int n, int weight[], int value[],int capacity)
{
	vector<int> curr(capacity+1,0);
	for(int w = weight[0]; w<=capacity; w++)
	{
		if(weight[w]<=capacity)
		{
			curr[w] = value[0];
		}
		else
		{
			curr[w] = 0;
		}
	}
	
	
		for(int row = 1; row<n; row++)
		{
			for(int col = capacity; col>=0; col--)
			{
				if(weight[row]<=col)
				{
					int include = value[row] + curr[col-weight[row]];
					int exclude = 0 + curr[col];
					curr[col] =  max(exclude,include);
				}
				
				
			}
		}
		
		return curr[capacity];
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
//	cout<<knapsackRecursionMemo(numberOfItems,weight,value,capacity,dp);
//	cout<<knapsackRecursionTabulation(numberOfItems,weight,value,capacity);
//	cout<<knapsackTwoArray(numberOfItems,weight,value,capacity);
	cout<<knapsackSingleArray(numberOfItems,weight,value,capacity);

	return 0;
}

