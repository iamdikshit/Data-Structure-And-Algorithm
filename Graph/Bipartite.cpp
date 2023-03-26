#include<bits/stdc++.h>
#include<queue>
#include<vector>

using namespace std;

bool isBipartite(int node ,vector<bool> &visited,vector<int> &color,vector< vector<int> > &adj)
{
    queue<int> q;
    visited[node] = true;
    color[node] = 1;
    q.push(node);
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int nbr : adj[v])
        {
            if(!visited[nbr])
            {
                visited[nbr] = true;
                color[nbr] = 1 - color[v];
                q.push(nbr);
            }
            else{
                if(color[nbr] == color[v])
                {
                    return false;
                }
            }
        }
    }
    return true;
}


int main()
{
    int vertex, edge;
    cin>>vertex>>edge;
    vector< vector<int> > adj;
    adj.resize(vertex);
    for(int i = 0; i<edge;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    vector<int> color(vertex,-1);
    vector<bool> visited(vertex,false);
    for(int i=0; i<vertex; i++)
    {
        if(!visited[i])
        {
            if(isBipartite(i,visited,color,adj))
            {
                cout<<"IS BIPARTITE GRAPH";
            }
            else
            {
                cout<<"IS NOT A BIPARTITE GRAPH";

            }
        }
    }
    return 0;
}

// 4 4
// 0 1
// 0 3
// 1 2
// 2 3