// 

#include<bits/stdc++.h>
using namespace std;

int solv(int target)
{
	if(target == 0)
		return 0;

	
	int a = target;
	for(int j = 1; j*j<=target ; j++)
	{
		int include = 1+ solv(target-(j*j));
		int a = min(include,a);
	}
	return  a;
}

int main()
{
	int n;
	cin>>n;
	cout<<solv(n);
	return 0;
}
