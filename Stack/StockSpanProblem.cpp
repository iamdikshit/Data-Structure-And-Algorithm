/*
	STOCK SPAN PROBLEM
	
	SPAN - NO. OF CONSICUTIVE DAYS BEFORE THE GIVEN DAY WHEN PREV IS LESS
	THEN EQUAL TO THAT DAY.
*/

#include<bits/stdc++.h>
#include<cstdlib>
#include<stack>

using namespace std;

void StockSpan(int price[],int n)
{
	stack<int> stack;
	int p;
	int result[n];
	for(int i =0; i<n; i++)
	{
		while(!stack.empty() && price[i]>price[stack.top()])
		{
			stack.pop();
		}
		if(stack.empty())
		{
			p=-1;
		}
		else{
			p = stack.top();
		}
		result[i] = i-p;
		stack.push(i);
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<result[i]<<" ";
	}
}

int main()
{
	int n;
	cin>>n;
	int price[n];
	// Enter price
	for(int i = 0; i<n; i++)
	{
		cin>>price[i];
	}
	StockSpan(price,n);
	return 0;
}
