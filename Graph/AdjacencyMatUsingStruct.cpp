#include<bits/stdc++.h>
using namespace std;

struct graph{
	int nodes;
	int **adj;
};

struct graph* createGraph(int nodes)
{
	struct graph* g = (struct graph*)malloc(sizeof(struct graph));
	g->nodes = nodes;
	g->adj = (int *)malloc(nodes * sizeof(int));
	// Memory allocation for each column and initialised with 0
	// for initialing with zero we use calloc
	for(int i=0; i<nodes; i++)
	{
		g->adj[i] = (int *)calloc(nodes * sizeof(int));
	}
	return g;
	
	
}

// void insert edge
void insertEdge(struct graph* g, int u,int v)
{
	if(u>=g->nodes || v>=g->nodes)
	{
		cout<<"Error when adding edge";
		return;
	}
	// For undirected graph
	if(g->adj[u][v]==0)
	{
		g->adj[u][v] = 1;
		g->adj[v][u] = 1;
	}
	
}
void display(struct graph* g)
{
	for(int i =0; i<g->nodes; i++
	{
		for(int j=0;j<g->nodes;i++)
		{
			cout<< g->adj[i][j];
		}
		cout<<endl;
	}
}

int main()
{
	struct graph* g;
	int n;
	cin>>n;
	g = createGraph(n);
	insertEdge(g,0,1);
	display(g);
	
	return 0;
}
