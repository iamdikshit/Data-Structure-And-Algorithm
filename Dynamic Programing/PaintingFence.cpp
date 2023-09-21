// Painting fence problem

#include<bits/stdc++.h>
#include<vector>

using namespace std;

// Recursion
int paintingFence(int pole, int color)
{
	if(pole==1)
		return color;
	if(pole==2) 
		return color + (color * (color - 1));
	
	int ans = (paintingFence(pole-2,color)*(color-1)) + (paintingFence(pole-1,color)*(color-1));
	return ans;
}


// Recursion + memoization
int paintingFenceDP(int pole, int color, vector<int> dp)
{
	if(pole==1)
		return color;
	if(pole==2) 
		return color + (color * (color - 1));
	
	if(dp[pole]!=-1)
		return dp[pole];
		
	int ans = (paintingFenceDP(pole-2,color,dp)*(color-1)) + (paintingFenceDP(pole-1,color,dp)*(color-1));
	dp[pole] = ans;
	return dp[pole];
}

// Tabulation
int paintingFenceTabulation(int pole,int color)
{
	vector<int> dp(pole+1,0);
	dp[1] = color;
	dp[2] = color + (color * (color - 1));
	
	for(int i=3;i<pole;i++)
	{
		dp[i] = (dp[i-2]*(color+1)) + (dp[i-1]*(color + 1));
	}
	return dp[pole];
}

int paintingFenceSO(int pole,int color)
{

	int prev = color;
	int prev2 = color + (color * (color - 1));
	
	for(int i=3;i<pole;i++)
	{
		int ans = (prev2*(color+1)) + (prev*(color + 1));
		prev = prev2,
		prev2 = ans;
	}
	return prev2;
}

int main()
{
	int pole,color;
	cin>>pole>>color;
//	vector<int> dp(pole+1,-1);
//	cout<<paintingFence(pole,color);
//	cout<<paintingFenceDP(pole,color,dp);
	cout<<paintingFenceSO(pole,color);
	return 0;
}
