/*
	*********************************************
	Breadth FIRST SEARCH
		-USING QUEUE
		-USE FOR FINDING SHORTEST PATH
	*********************************************
*/

#include<bits/stdc++.h>
#include<vector>
#include<queue>

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
		// Breadth first search
		void bfs(int visited[],int start)
		{
			
			queue<int> q;
			q.push(start);
			visited[start]=1;
			while(!q.empty())
			{
				int v = q.front();
				cout<<v<<" ";
				q.pop();
				for(auto j:adj[v])
				{
					if(visited[j]==0)
					{
						visited[j]=1;
						q.push(j);
					}
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
	g.addEdge(1,2);
	g.addEdge(1,7);
	g.addEdge(2,3);
	g.addEdge(4,5);
	g.addEdge(4,6);
	g.addEdge(4,7);
	g.display();
	int visited[n];
	for(int i =0; i<n;i++)
	{
		visited[i]=0;
	}
	cout<<"********DFS************"<<endl;
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			g.dfs(visited,i);	
		}
		
	}
	cout<<"\n********BFS**********"<<endl;
	for(int i =0; i<n;i++)
	{
		visited[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			g.bfs(visited,i);	
		}
		
	}
	
	return 0;
}
