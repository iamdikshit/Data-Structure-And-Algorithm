// Minimum squre triangulation


#include<bits/stdc++.h>
#include<vector>
using namespace std;
    // recursion - TC - exponantial
    int solv(vector<int>& v,int i,int j)
    {
        // base case
        if(i+1 == j)
            return 0;
        
        int ans = INT_MAX;
        for(int k=i+1; k<j; k++)
        {
            ans = min(ans,v[i]*v[k]*v[j]+solv(v,i,k)+solv(v,k,j));
        }
        return ans;
    }
  // Recursion + Memoization
    int solvMemo(vector<int>& v,int i,int j,vector< vector<int> > dp)
    {
        // base case
        if(i+1 == j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];

        int ans = INT_MAX;
        for(int k=i+1; k<j; k++)
        {
            ans = min(ans,v[i]*v[k]*v[j]+solvMemo(v,i,k,dp)+solvMemo(v,k,j,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    // Tabulation
    int solvTab(vector<int>& v)
    {
        int n = v.size();
        vector< vector<int> > dp(n,vector<int> (n,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+2; j<n; j++)
            {
                int ans = INT_MAX;
                for(int k=i+1; k<j;k++)
                {
                    ans = min(ans,v[i]*v[k]*v[j]+dp[i][k]+dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][n-1];
        
    }
int main()
{
	int n;
	cin>>n;
	vector<int> values(n);
	for(int i=0;i<n; i++)
	{
		cin>>values[i];
	}
	cout<<solvTab(values);
	return 0;
}
