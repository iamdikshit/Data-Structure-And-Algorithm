/*
	Reverse the stack using push and pop;
*/

#include<bits/stdc++.h>
#include<cstdlib>
#include<stack>

using namespace std;
void insertAtBottom(stack<int> s, int data)
{
	int temp;
	if(s.empty())
	{
		s.push(data);
		return;
	}
	else{
		temp = s.top();
	s.pop();
	insertAtBottom(s,data);
	s.push(temp);
		
	}
	
	
}
void reverse(stack<int> s)
{
	int data;
	if(s.empty())
	{
		return ;
	}
	data = s.top();
	s.pop();
	reverse(s);
	insertAtBottom(s,data);
	
}



int main()
{
	stack<int> st;
	for(int i = 2; i<=5; i++)
	{
		st.push(i);
	}
	
	cout<<"Top element: "<<st.top()<<endl;
	reverse(st);
	cout<<"Top element: "<<st.top()<<endl;
	cout<<"Data After Reverse: ";
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}
