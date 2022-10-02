/*
	Evaluate the infix expration
	Infix expration : 2 + 3 - (1 * 4 / 2)
*/
#include<bits/stdc++.h>
#include<cstlib>
#include<stack>
using namespace std;

int priority(char x)
{
	if (x == '+' || x == '-')
	{
		return 1;
	}
	else if (x=='*' || x=='/')
	{
		return 2;
	}
}

int Evalutation(int v1,int v2,char x)
{
	if(x=='+')
	{
		return v1+v2;
	}
	else if(x=='-')
	{
		return v1-v2;
	}
	else if(x=='*')
	{
		return v1*v2;
	}
	else if(x=='/')
	{
		return v1/v2;
	}
}
// Infix Evaluation function
void infixEvaluation(string expression)
{
	stack<int> operands;
	stack<char> operators;
	for(int i=0; i<expression.length(); i++)
	{
		if(isdigit(expression[i]))
		{
			operands.push(expression[i]-'0');
		}
		else if(expression[i]=='('){
			operators.push(expression[i]);
		}
		else if(expression[i]==')'){
			while(operators.top()!='(' && !operators)
			{
				
			}
		}
	}

	
}

// Main function
int main()
{
	infixEvaluation("2+3-(1*4/2)");
	return 0;
}
