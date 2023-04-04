#include<bits/stdc++.h>
#include<queue>
#include<vector>

using namespace std;

void FindLongPath(vector< vector<int> > &adj,int node,vector<bool> &visited,int &count)
{
    queue<int> q;
    visited[node] = true;
    q.push(node);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int nbr : adj[v])
        {
            if(!visited[nbr])
            {
                count++;
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
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

        int count = 0;
        vector<bool> visited(vertex,false);
        for(int i=0; i<vertex; i++)
        {
            FindLongPath(adj,i,visited,count);
        }

        cout<<count<<endl;
    }
    
    
    return 0;
}

