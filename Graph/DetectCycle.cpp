#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

// Graph
class Graph{
    public:
    int vertices;
    vector< vector<int> > adj;

    Graph(int v)
    {
        this->vertices = v;
        this->adj.resize(v);
    }

    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool DetectCycle(int node, bool visited[])
    {
        int parent[vertices];
        for(int i=0; i<vertices; i++)
        {
            parent[i] = -1;
        }

        visited[node] = true;
        queue<int> q;
        q.push(node);
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            for(int j : adj[v])
            {
                if(!visited[j])
                {
                    visited[j] = true;
                    parent[j] = v;
                    q.push(j);
                }
                else if(parent[v]!=j)
                {
                    return true;
                }
            }
        }

        return false;

    }

    void display()
    {
        for(int i=0; i<vertices; i++)
        {
            cout<<i<<"->";
            for(int j:adj[i])
            {
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int verteces,edge;
    cin>>verteces>>edge;
    int u,v;
    Graph g(verteces);
    for(int i=0; i<edge; i++)
    {
        cin>>u>>v;
        g.addEdge(u,v);
    }
    bool flag ;
    bool visited[verteces];
    for(int i=0; i<verteces; i++)
    {
        visited[i] = false;
    }

    for(int i=0; i<verteces; i++)
    {
        if(!visited[i] && g.DetectCycle(i,visited))
        {
            flag = true;
        }
    }

    g.display();
    if(flag)
        cout<<"Yes";
    else
        cout<<"No";
    

    return 0;
}