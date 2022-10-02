#include<bits/stdc++.h>
#include<queue>

using namespace std;

void reverse(queue<int>& q1)
{
	if(q1.size() ==0)
		return;
	
	int front = q1.front();
	q1.pop();
	reverse(q1);
	q1.push(front);
}

void display(queue<int>& q1)
{
	queue<int> q2 = q1;
	if(q2.size() ==0)
	{
		cout<<"Queue is empty";
		return;
	}
	
	while(!q2.empty())
	{
		
		cout<<q2.front()<<" ";
		q2.pop();
	}
	cout<<"\n";
}
int main()
{
	int t,n,input;
	cin>>t;
	while(t--)
	{
		queue<int> q1;
		cin>>n;
		for(int i =0; i<n;i++)
		{
			cin>>input;
			q1.push(input);
		}
		
		reverse(q1);
		display(q1);
		
	}
	
	return 0;
}
