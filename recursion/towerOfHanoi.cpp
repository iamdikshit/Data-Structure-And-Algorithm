#include<bits/stdc++.h>
using namespace std;

void TowerOfHanoi(int n, char frompeg, char auxpeg,char topeg)
{
	if(n==1)
	{
		// if there is only 1 disk than move disk from source to destination
		cout<<"\nMove disk "<<n<<" from "<<frompeg<<" to "<<topeg;
		return;
	}
	else
	{
		//move n-1 disk then move n-1 th disk from source(frompeg to auxilary ) using toped 
		TowerOfHanoi(n-1, frompeg,topeg,auxpeg);
		cout<<"\nMove disk "<<n<<" from "<<frompeg<<" to "<<topeg;
		//move nth disk from auxilary(auxpeg) to destination(topeg) using source peg (frompeg)
		TowerOfHanoi(n-1,auxpeg,frompeg,topeg) ;
	}
}

int main()
{
	int n;
	cin>>n;
	char frompeg = 'A';
	char auxpeg = 'B';
	char topeg = 'C';
	TowerOfHanoi(n,frompeg,auxpeg,topeg);
	
}
