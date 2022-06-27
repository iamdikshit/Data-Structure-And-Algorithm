#include<bits/stdc++.h>
using namespace std;

void subset(string str,int index, string output)
{
	if(index==str.length())
	{
		cout<<"{"<<output<<"}"<<endl;
		return;
	}
	
	subset(str,index+1,output); // excluding
	output.push_back(str[index]);
	subset(str,index+1,output);
	
}
int main()
{
	string str,output;
	cin>>str;
	subset(str,0,output);
	return 0;
}
