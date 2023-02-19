/*
    SHORTEST PATH FOR UNWEIGHTED DIRECTED GRAPH
    USING Breadth first search concept
*/

#include<bits/stdc++.h>
#include<vector>
#include<queue>
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

    // function for unweighted Shortest path
    void UnweightedShortesPath(int src,int destination,int N )
    {
        
        int visited[N],parent[N];
        for(int i = 0;i<N;i++) visited[i] = -1; 
        queue<int>  q;
        visited[src] = 0;
        parent[src] = -1;
        q.push(src); 
        while(q.empty()==false) 
        { 
            int node = q.front(); 
            q.pop();
            for(auto it:adj[node]){
                if(visited[it]==-1){
                    visited[it]=visited[node]+1;
                    parent[it] = node;
                    q.push(it);
                }
            } 
        } 

        vector<int> ans;
        ans.push_back(destination);
        while(destination!=src)
        {
            ans.push_back(parent[destination]);
            destination = parent[destination];
        }

        reverse(ans.begin(),ans.end());
        for(auto i : ans)
        {
            cout<<i<<"->";
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
    int n,src,dest;
    cout<<"\nEnter Number of Nodes:";
    cin>>n;
    cout<<"\nEnter Source:";
    cin>>src;
    cout<<"\nEnter Destination:";
    cin>>dest;
    Graph g(n);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 0);
    g.addEdge(2, 5);
    g.addEdge(3, 5);
    g.addEdge(3, 6);
    g.addEdge(4, 6);
    g.addEdge(5, 6);

	g.display();


    g.UnweightedShortesPath(src,dest,n);
    
    return 0;
}

