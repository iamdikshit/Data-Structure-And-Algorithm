#include<bits/stdc++.h>
#include<queue>
#include<stack>

using namespace std;

void interLeavingQueue(queue<int> q)
{
	if(q.size()%2!=0)
	{
		return;
	}
	int half = q.size()/2;
	stack<int> s;
	for(int i=0;i<half;i++)
	{
		s.push(q.front());
		q.pop();
	}
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
	for(int i=0;i<half;i++)
	{
		q.push(q.front());
		q.pop();
	}
	for(int i=0;i<half;i++)
	{
		s.push(q.front());
		q.pop();
	}
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
		q.push(q.front());
		q.pop();
	}
	
	while(q.size()!=0)
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	
}

void display(queue<int> q)
{
	while(q.size()!=0)
	{
		cout<<q.front()<<" ";
		q.pop();
	}
}

int main()
{
	int n,input;
	cin>>n;
	queue<int> q;
	for(int i=0; i<n; i++)
	{
		cin>>input;
		q.push(input);	
	}
	interLeavingQueue(q);
//	display(q);
	return 0;
}
