/*
	Evaluate postfix problem
*/

#include<bits/stdc++.h>
#include<cstdlib>
#include<stack>

using namespace std;
void Evaluate(string s)
{
	stack<int> st;
	int exp;
	for(int i=0; i<s.length(); i++)
	{
		if(isdigit(s[i]))
		{
			//It converts the ascii value of 0-9 characters to its numerical value.
			/*
			This subtracts from the character to which string is pointing
			the ASCII code of the character '0'. So, '0' - '0' gives you 0 and so on and '9' - '0' gives you 9.
			*/
			st.push(s[i]-'0');
		}
		else{
			int firstnum = st.top();
			st.pop();
			int secondnum = st.top();
			st.pop();
			switch(s[i])
			{
				case '+':st.push(secondnum+firstnum);
							break;
				case '-':st.push(secondnum-firstnum);
							break;
				case '*':st.push(secondnum*firstnum);
							break;
				case '/':st.push(secondnum/firstnum);
							break;
			}
		}
		
	}
	cout<<st.top();
}
int main()
{
	string s;
	cin>>s;
	Evaluate(s);
	return 0;
}
