/*
*********************************************************************
	ADJACENCY MATRIX TO IMPLEMENT THE GRAPH
	UNDIRECTED GRAPH
*********************************************************************
*/

#include<bits/stdc++.h>
using namespace std;

class Graph{
	int nodes;
	bool **adjMat;
	public:
		Graph(int nodes)
		{
			this->nodes = nodes;
			// column
			adjMat = new bool*[nodes];
			for(int i=0; i<nodes;i++)
			{
				adjMat[i] = new bool [nodes];// creating row
				for(int j=0;j<nodes;j++)
				{
					adjMat[i][j] = false;
				}
			}
		}
		
		void addEdge(int u,int v)
		{
			// for undirected graph we have to make edge two way
			adjMat[u][v] = true;
			adjMat[v][u] = true;
		}
		
		void display()
		{
			for(int i=0;i<nodes;i++)
			{
				for(int j=0;j<nodes;j++)
				{
					cout<<adjMat[i][j];
				}
				cout<<endl;
			}
		}
};
int main()
{
	int n;
	cin>>n;
	Graph graph(n);
	for(int i=0;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		graph.addEdge(u,v);
	}
	graph.display();
	return 0;
}
