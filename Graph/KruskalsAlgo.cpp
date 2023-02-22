/*
*************************************************************
    MINIMUM SPANING TREE
        -PRIMS ALGORITHM
*************************************************************
*/

#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> ipair;

class DisjointSet{
    public:

    void makeSet(int parent[],int rank[],int size)
    {
        for(int i=0;i<size;i++)
        {
            parent[i]=i;
            rank[i] = 0;
        }
    }
    
    int find(int parent[],int node)
    {
        if(parent[node]==node)
        {
            return node;
        }
        else return parent[node]=find(parent,parent[node]);
    }

    void unionByRank(int parent[],int rank[],int node1,int node2)
    {
        int u = find(parent,node1);
        int v = find(parent,node2);

        if(rank[u]<rank[v])
        {
            parent[u] = v;
        }
        else if(rank[u]>rank[v])
        {
            parent[v] = u;
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    } 

};

class Graph{
    public:
        int nodes;
        int typeOfGraph;
        vector< vector<ipair> > adj;
        Graph(int nodes,int typeOfGraph)
        {
            this->nodes = nodes;
            this->typeOfGraph = typeOfGraph;
            this->adj.resize(nodes);
        }

        // For directed graph
        void addEdge(int u,int v,int weight)
        {
            /*
                typeOfGraph 
                0 - > directed graph
                1 - > undirected graph
            */
           if(typeOfGraph==0)
           {
            adj[u].push_back(make_pair(v,weight));
           }
           else if(typeOfGraph==1)
           {
            adj[u].push_back(make_pair(v,weight));
            adj[v].push_back(make_pair(u,weight));
           }
            
        }

        void kruskals()
        {
            DisjointSet d;
            int parent[nodes];
            int rank[nodes];
            // Making set
            d.makeSet(parent,rank,nodes);
            vector< pair<int, ipair> > edges;

            // making edge datastructure based on weight
            for(int i=0; i<nodes; i++)
            {
                for(auto j:adj[i])
                {
                    edges.push_back({j.second,{i,j.first}});
                }
                
            }

            // sort edges on the basis of weigt
            sort(edges.begin(),edges.end());
            int minCost = 0;
            for(auto j:edges)
            {
                int w = j.first;
                int u = d.find(parent,j.second.first);
                int v = d.find(parent, j.second.second);

                if(u!=v)
                {
                    minCost+=w;
                    d.unionByRank(parent,rank,u,v);
                }
                
            }

            cout<<"\nMinimum Cost  = "<<minCost;
        }

        void display()
        {
            for(int i=0; i<nodes; i++)
            {
                cout<<i<<"->";
                for(auto j:adj[i])
                {
                    cout<<"["<<j.first<<","<<j.second<<"],";
                }
                 cout<<endl;
            }
           
        }

};

int main()
{
    int n;
    n =5;
    /*
        0->directed graph
        1->undirected graph
    */
    Graph g(n,1);
    g.addEdge(0,2,1);
    g.addEdge(0,1,4);
    g.addEdge(2,1,2);
    g.addEdge(1,4,4);
    g.addEdge(2,3,4);
    g.addEdge(3,4,4);
    // g.addEdge(0,1,4);
    // g.addEdge(0,2,1);
    // g.addEdge(1,4,4);
    // g.addEdge(2,1,2);
    // g.addEdge(2,3,4);
    // g.addEdge(3,4,4);
    // g.addEdge(0,1,2);
    // g.addEdge(0,3,1);
    // g.addEdge(1,4,5);
    // g.addEdge(1,2,4);
    // g.addEdge(2,4,1);
    // g.addEdge(2,3,3);

    g.display();
    g.kruskals();
    return 0;
}