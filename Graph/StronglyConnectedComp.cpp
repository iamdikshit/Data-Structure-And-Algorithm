#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

// Graph
class Graph{
    public:
    int vertices;
    vector< vector<int> > adj;
    vector< vector<int> > revadj;


    Graph(int v)
    {
        this->vertices = v;
        this->adj.resize(v);
        this->revadj.resize(v); 
    }

    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
    }

    void dfs(int node,stack<int> &s, bool visited[])
    {
        visited[node] = true;
        for(int v:adj[node])
        {
            if(!visited[v])
            {
                dfs(v,s,visited);
            }
        }
        s.push(node);
    }

     void revdfs(int node, bool visited[])
    {
        visited[node] = true;
        cout<<node<<" ";
        for(int v:revadj[node])
        {
            if(!visited[v])
            {
                revdfs(v,visited);
                cout<<endl;
            }
        }
    
    }
    // Strongly connected function
    void StronglyConnected()
    {
        stack<int> s;
        bool visited[vertices];
        for(int i=0; i<vertices; i++)
        {
            visited[i] = false;
        }
        // Got topological sort
        for(int i=0; i<vertices; i++)
        {
            if(!visited[i])
            {
                dfs(i,s,visited);
            }
        }

        // Reverse or transpose adj list or graph

        for(int u=0; u<vertices; u++)
        {
            for(int v:adj[u])
            {
                revadj[v].push_back(u);
            }
        }

        for(int i=0; i<vertices; i++)
        {
            visited[i] = false;
        }

            int count =0;
        cout<<"\nReverse Adj"<<endl;
        for(int i=0; i<vertices; i++)
        {
            cout<<i<<"->";
            for(int j:revadj[i])
            {
                cout<<j<<",";
            }
            cout<<endl;
        }

        // run dfs for reverse graph
        while(!s.empty())
        {
            int top = s.top();
            s.pop();
            if(!visited[top])
            {   count++;
                revdfs(top,visited);
                cout<<endl;
            
            }
        }

        cout<<"\nCount : "<<count;

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
    int v;
    cin>>v;
    Graph g(v);
    /*
    0->1
    0->3
    1->2
    2->0
    2->3
    */
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    //  g.addEdge(1, 0);
    // g.addEdge(0, 2);
    // g.addEdge(2, 1);
    // g.addEdge(0, 3);
    // g.addEdge(3, 4);
    g.display();
    
    g.StronglyConnected();
    
    return 0;
}