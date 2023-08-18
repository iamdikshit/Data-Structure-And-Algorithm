// Fibonacci series using Dynamic programin Top down approach in which we preserve
// recursive call
#include<bits/stdc++.h>

using namespace std;

class FindFibo{
	public:
		int dp[];
	
	FindFibo(int n)
	{
		int dp[n];
		for(int i=0;i<n;i++)
		{
			dp[i]=-1;
			cout<<dp[i];
		}
	}
	
	int fib(int n)
	{
		if(n==0 || n==1)
			return n;
		if(dp[n]!=-1) return dp[n];
		return dp[n] = fib(n-1)+fib(n-2);
		
	}
};

int main(){
	
	int n;
	cin>>n;
	FindFibo f(n);
	cout<<f.fib(n);

	return 0;
}
