#include<bits/stdc++.h>
#include<queue>

using namespace std;

void stoneNumber(queue<int>& q)
{
	int temp;
	while(q.size()!=1)
	{
		temp = q.front();
		q.pop();
		q.push(temp);
		q.pop();
			
	}
		
		
	
}

void display(queue<int>& q)
{
	if(q.size()==0)
	{
		cout<<"Empty";
		return;
	}
	queue<int> temp = q;
	while(temp.size()!=0)
	{
		cout<<temp.front()<<" ";
		temp.pop();
	}
	cout<<"\n";
}

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		queue<int> q;
		cin>>n;
		for(int i=1; i<=n;i++)
		{
			q.push(i);
		}	
		
		stoneNumber(q);
	display(q);
	}
	
	return 0;
}
