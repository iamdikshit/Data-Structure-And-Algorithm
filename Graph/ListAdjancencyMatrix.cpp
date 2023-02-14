/*
	Adjacency List using vector
*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Graph{
	public:
	
	vector< vector<int> > adj;
	Graph(int nodes)
	{
		this->adj.resize(nodes);
		
	}
	void addEdge(int u,int v)
	{
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	void display(int n)
	{
		for(int i=0;i<n;i++)
		{
			cout<<i<<"-->";
			for(int j:adj[i])
			{
				cout<<j;
			}
			cout<<endl;
		}
	}
		
};

int main()
{
	int n;
	cin>>n;
	Graph g(n);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.display(n);
	
	return 0;
}
