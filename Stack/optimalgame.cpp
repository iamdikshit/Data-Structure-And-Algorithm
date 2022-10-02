#include<bits/stdc++.h>
#include<stack>

using namespace std;


void optimalgame(stack<int> s1,int a[])
{
	while(!s1.empty() || !s2.empty())
	{
		if(s1.top()> s2.top())
		{
			cout<<"1";
			s2.pop();
		}
		else if(s1.top()< s2.top())
		{
			cout<<"2";
			s1.pop();
		}
		else if(s1.top() == s2.top())
		{
			cout<<"0";
			s1.pop();
			s2.pop();
		}
		
	}
	
}
void insertinreverse(stack<int> s1,stack<int> s2)
{
	int temp;
	if(s1.empty())
	{
		return;
	}
	else{
		
		temp = s1.top();
		cout<<temp<<" ";
		s1.pop();
//		s2.push(temp);
		insertinreverse(s1,s2);
		s2.push(temp);
//		s1.push(temp);
		s1.push(temp);
		
	}
}



int main()
{
	int a[4];
	stack<int> s2;
	for(int i =1; i<=4; i++)
	{
		cin>>a[i];
	}
	
	for(int i =4; i>=1; i--)
	{
		s2.push(a[i]);
	}
	
	return 0;
}
