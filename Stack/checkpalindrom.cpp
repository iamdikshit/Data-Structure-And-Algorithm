/*
	Given an array of characters formed with a's and b's. The string is marked with special character X 
	which represents the middle of the list .check whether the string is palindrome.

*/
#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

void checkPalindrome(string s)
{
	int i,j;
	i = 0;
	j = s.length()-1;
	while(i<j && s[i]==s[j])
	{
		i++;
		j--;
	}
	if(i<j){
		cout<<"Not a palindrome"<<endl;
	}
	else{
		cout<<"Palindrome"<<endl;
	}
}

int main(){
	checkPalindrome("ababaXababa");
	checkPalindrome("abaabaXababa");
	return 0;
}
