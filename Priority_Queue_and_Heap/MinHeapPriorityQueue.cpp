/*
	***************************************************************
	HEAP IMPLEMENT USING PRIORITY QUEUE
	***************************************************************
*/

#include<bits/stdc++.h>
#include<queue>

using namespace std;
int main()
{
	/*
	BY DEFAULT PRIORITY QUEUE IS MAX HEAP
	*/
	priority_queue<string,vector<string>, greater<string> > q ;
	q.push("z");
	q.push("n");
	q.push("m");
	q.push("a");
	q.push("b");
	while(!q.empty())
	{
		cout<<q.top()<<" ";
		q.pop();
	}
	return 0;
}
