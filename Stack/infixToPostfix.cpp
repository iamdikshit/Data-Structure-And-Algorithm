/*
	Program to convert infix expression into post fix expression 
	Using built in c++ stack
*/

#include<bits/stdc++.h>
#include<stack>

using namespace std;

// Priority function
int priority(char x)
{
	if(x=='(')
	{
		return 0;
	}
	if(x=='+' || x=='-')
	{
		return 1;
	}
	if(x=='*' || x=='/')
	{
		return 2;
	}
}

int infixtopostfix(string s)
{
	stack<char> st;
	string result;
	
	for(int i =0; i<s.length(); i++)
	{
		char c = s[i];
		// check input is operand or operator
		if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
		{
			result+=c;
		}
		else if(c=='(')
		{
			st.push('(');
		}
		else if(c==')')
		{
			while(st.top()!='(')
			{
				result+=st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while(!st.empty() && priority(s[i]) <= priority(st.top()))
			{
				if(c == '^' && st.top() == '^')
				{
					break;
				}
				else
				{
					result+=st.top();
					st.pop();
				}
			}
			st.push(c);
		}
	}
	
	while(!st.empty())
	{
		result+=st.top();
		st.pop();
	}
	cout<<result<<endl;
}
int main()
{
	string exp = "a*b-(c+d)+e";
    infixtopostfix(exp);
	return 0;
}
