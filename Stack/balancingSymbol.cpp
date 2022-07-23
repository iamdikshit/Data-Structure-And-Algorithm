/*
	Balacing symbols/paranthesis problem in using stack
	Here we are using STL Stack to reduce the code.
*/

#include<bits/stdc++.h>
#include<stack>

using namespace std;

// function for matching symbols
int matchingSymbol(char a,char b)
{
	if(a=='(' && b==')')
	{
		return 1;
	}
	else if(a=='{' && b=='}')
	{
		return 1;
	}
	else if(a=='[' && b==']')
	{
		return 1;
	}
	
	return 0;
}

// function to check expression
int checkExpression(char expression[])
{
	int count;
	char temp;
	stack<char> s;
	for(count = 0 ; count<strlen(expression); count++)
	{
		if(expression[count]=='(' || expression[count]=='{' || expression[count]=='[')
		{
			s.push(expression[count]);
		}
		if(expression[count]==')' || expression[count]=='}' || expression[count]==']')
		{
			if(s.empty())
			{
				cout<<"The right symbol more than left symbol!"<<endl;
				return 0;
			}
			else
			{
				temp = s.top();
				s.pop();
				if(!matchingSymbol(temp,expression[count]))
				{
					cout<<"Symbol "<<temp<<" is mismatched  with "<<expression[count]<<endl;
					return 0;
				}
			}
		}
	}
	
	if(s.empty())
	{
		cout<<"Expression has balance paranthesis!"<<endl;
		return 1;
	}
	else
	{
		cout<<"Expression has Unbalance paranthesis!"<<endl;
		return 0;
	}
}

int main()
{
	int validate;
	validate = checkExpression("[a+(b*{d+2)]");
	if(validate==1)
	{
		cout<<"Expression is valid!"<<endl;
	}
	else
	{
		cout<<"Expression is invalid"<<endl;
	}
	return 0;
}
