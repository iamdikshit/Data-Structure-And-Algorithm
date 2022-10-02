#include<bits/stdc++.h>
#include<queue>

using namespace std;

int sum(queue<int> q)
{
	int sum =0;
	queue<int> temp = q;
	while(temp.size()!=0)
	{
		sum+=temp.front();
		temp.pop();
	}
	return sum;
}
void circulargas(queue<int> q,queue<int> q2)
{
	if(sum(q)>=sum(q2))
	{
		int i;
		int ans =0;
		int remaining_fuel = 0;
		for(i=0;i<q.size();i++)
		{
			remaining_fuel += q.front() - q2.front();
			q.pop();
			q2.pop();
			if(remaining_fuel<0)
			{
				ans = i+1;
				remaining_fuel  = 0;
			}
		}
		cout<<ans;
	}
	else{
		cout<<-1;
	}
}
int main()
{
	int n,input;
	cin>>n;
	queue<int> gas;
	queue<int> cost;
	for(int i=0; i<n;i++)
	{
		cin>>input;
		gas.push(input);
		
	}
	for(int i=0; i<n;i++)
	{
		cin>>input;
		cost.push(input);
		
	}
//	cout<<"gas :"<<sum(gas);
//	cout<<"cost :"<<sum(cost);
	
	circulargas(gas,cost);
	
	return 0;
}
