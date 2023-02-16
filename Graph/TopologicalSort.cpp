/*
    TOPOLOGICAL SORT USING DFS
*/

#include<bits/stdc++.h>
#include<vector>
#include<stack>
using namespace std;

// Create Directed graph
class Graph{
    public:
    int nodes;
    vector< vector<int> > adj;
    Graph(int nodes)
    {
        this->nodes = nodes;
        this->adj.resize(nodes);
    }

    // Add Edge
    void addEdge(int source, int destination)
    {
        if(source>=nodes || destination>=nodes)
        {
            cout<<"Out of Index";
            return;
        }
        adj[source].push_back(destination);
    }

    void topologicalSort(int visited[],int start,stack<int> &s)
    {
        visited[start]=1;
        
        for(auto j: adj[start])
        {
            if(visited[j]==0)
            {
                topologicalSort(visited,j,s);
            }
        }

        s.push(start);
    }

    void topologicalSortUitlity(int n)
    {
        int visited[n];
        for (int i = 0; i < n; i++)
        {
        visited[i] = 0;
        }
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            if(visited[i]==0)
            {
                topologicalSort(visited,i,s);
            }
        }
        cout<<"\n**************OutPut***********"<<endl;
        
        while(!s.empty())
        {
            cout<<s.top()<<", ";
            s.pop();
        }
    }

    void display()
    {
        for(int i=0;i<nodes; i++)
        {
            cout<<i<<"->";
            for(auto j:adj[i])
            {
                cout<<j<<", ";
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
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
	g.display();
    g.topologicalSortUitlity(n);
    return 0;
}

