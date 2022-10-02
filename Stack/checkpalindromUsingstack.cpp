/*
	Given an array of characters formed with a's and b's. The string is marked with special character X 
	which represents the middle of the list .check whether the string is palindrome. Using Stack

*/
#include<bits/stdc++.h>
#include<cstdlib>
#include<stack>

using namespace std;

void checkPalindrome(string s)
{	int i =0;
	char val;
	stack<char> st;
	while(s[i]&&s[i]!='X')
	{
		st.push(s[i]);
		i++;
	}
	i++;
	while(s[i])
	{
		val = st.top();
		
		if(st.empty() || val!=s[i] )
		{
			cout<<"Not a Palindrome"<<endl;
			return;
		}
		st.pop();
		i++;
	}
	cout<<"Palindrome"<<endl;
	

}

int main(){
	checkPalindrome("ababaXababa");
	checkPalindrome("abaabaXababa");
	return 0;
}
