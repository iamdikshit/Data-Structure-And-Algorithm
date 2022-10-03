#include<bits/stdc++.h>
#include<queue>
#include<stack>

using namespace std;

void ReverseKthTerm(queue<int> q,int k)
{
	if(q.size()==0 || k>q.size())
	{
		return;
	}
	else if(k>0)
	{
		stack<int> s;
	for(int i=0;i<k;i++)
	{
		s.push(q.front());
		q.pop();
	}
	while(!s.empty())
	{
		q.push(s.top());
		s.pop();
	}
	for(int i=0;i<q.size()-k;i++)
	{
		q.push(q.front());
		q.pop();
	}
	
	while(q.size()!=0)
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	}
		
	
}
int main()
{
	int n,k,input;
	cin>>n;
	queue<int> q;
	for(int i=0; i<n;i++)
	{
		cin>>input;
		q.push(input);
	}
	cin>>k;
	ReverseKthTerm(q,k);
	return 0;
}
