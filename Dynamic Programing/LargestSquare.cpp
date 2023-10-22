// Largest square formed in a matrix

#include<bits/stdc++.h>
#include<vector>
using namespace std;
// Recursion approach
int solvRec(int i, int j, vector< vector<int> > mat,int &maxi)
{
	if(i>=mat.size() || j>=mat[0].size())
		return 0;

	
	int right = solvRec(i+1,j,mat,maxi);
	int diagonal = solvRec(i+1,j+1,mat,maxi);
	int bottom = solvRec(i,j+1,mat,maxi);
	
	// checking current value
	if(mat[i][j]==1)
	{
		int ans = 1 +  min(right,min(diagonal,bottom));
		maxi = max(maxi,ans);
		return ans;
	}
	else{
		return 0;
	}

}

int solvMemo(int i, int j, vector< vector<int> > mat,int &maxi,vector< vector<int> > dp)
{
	if(i>=mat.size() || j>=mat[0].size())
		return 0;
	
	if(dp[i][j]!=-1)
		return dp[i][j];
	
	int right = solvMemo(i+1,j,mat,maxi,dp);
	int diagonal = solvMemo(i+1,j+1,mat,maxi,dp);
	int bottom = solvMemo(i,j+1,mat,maxi,dp);
	
	// checking current value
	if(mat[i][j]==1)
	{
		dp[i][j] = 1 +  min(right,min(diagonal,bottom));
		maxi = max(maxi,dp[i][j]);
		return dp[i][j];
	}
	else{
		return 0;
	}

}
int solvTab(vector< vector<int> > mat,int &maxi)
{
	vector< vector<int> > dp( mat.size()+1 , vector<int> (mat[0].size()+1,0));
	
	
	for(int i=mat.size()-1; i>=0; i-- )
	{
		for(int j=mat.size()-1; j>=0; j--)
		{
			int right = dp[i+1][j];
			int diagonal = dp[i+1][j+1];
			int bottom = dp[i][j+1]
			if(mat[i][j]==1)
			{
				dp[i][j] = 1 +  min(right,min(diagonal,bottom));
				maxi = max(maxi,dp[i][j]);
			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}
	
	return dp[0][0];
	
}
int main()
{
	int n,m;
	cin>>n;
	cin>>m;
	vector< vector<int> > mat( n , vector<int> (m));
	for(int i=0; i<n;i++)
	{
		for(int j=0; j<m; j++)
		{
			int in;
			cin>>in;
			mat[i][j] = in;
		}
	}
	
	
	vector< vector<int> > dp( n , vector<int> (m,-1));
	int maxi =0;
	//solvRec(0,0,mat,maxi,dp);
//	solvMemo(0,0,mat,maxi,dp);
	solvTab(mat,maxi);
	cout<<maxi;
	return 0;
}
