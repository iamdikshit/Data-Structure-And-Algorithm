#include<bits/stdc++.h>
using namespace std;

void reverseString(string str, int i)
{
	if(i==str.length())
		return;
	reverseString(str,i+1);
	cout<<str[i];
}
int main()
{
	string str;
	cin>>str;
	reverseString(str,0);
	return 0;
}
