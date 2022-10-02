#include<bits/stdc++.h>
#include<queue>
#include<string>
using namespace std;

void generateBinary(int n)
{
	
	queue<string> q;
	q.push("1");
	for(int i =0 ; i<n;i++)
	{
		string a = q.front();
		q.pop();
		cout<<a<<" ";
		string temp = a;
		
		q.push(a.append("0"));
		q.push(temp.append("1"));
	}

}
int main()
{
	
	int n ;
	cin>>n;
	generateBinary(n);
	
	return 0;
}
