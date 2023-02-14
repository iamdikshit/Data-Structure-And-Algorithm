/*
	*********************************************
	DEPTH FIRST SEARCH
		-RECURSIVE APPROCH
		-USES LESS SPACE THEN BREADTH FIRST SEARCH
	*********************************************
*/

#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Graph{
	public:
		int nodes;
		vector< vector<int> > adj;
		
		//Constructor
		Graph(int nodes)
		{
			this->nodes = nodes;
			this->adj.resize(nodes);
		}
		
		void addEdge(int u,int v)
		{
			if(u>=nodes || v>=nodes )
			{
				cout<<"Out of Index"<<endl;
				return;
			}
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		void display()
		{
			for(int i=0;i<nodes;i++)
			{
				cout<<i<<"->";
				for(int j : adj[i])
				{
					cout<<j<<",";
				}
				cout<<endl;
			}
		}
		
		void dfs(int visited[],int start)
		{
			visited[start]=1;
			cout<<start<<" ";
			for(auto j:adj[start])
			{
				if(visited[j]==0)
				{
					dfs(visited,j);
				}
			}
		}
};

int main()
{
	int n;
	cin>>n;
	Graph g(n);
	g.addEdge(0,1);
	g.addEdge(1,3);
	g.addEdge(1,2);
	g.addEdge(3,4);
	g.display();
	int visited[n];
	for(int i =0; i<n;i++)
	{
		visited[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			g.dfs(visited,i);	
		}
		
	}
	
	return 0;
}
