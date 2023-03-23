#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Graph{
    public:
        int nodes;
        vector< vector<int> > adj;
    
        // Constructor
        Graph(int nodes)
        {
            this->nodes = nodes;
            this->adj.resize(nodes);
        }

        void addEdge(int u,int v)
        {
            if(u>=nodes || v>=nodes)
            {
                cout<<"Out of index"<< endl;
                return ;
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        void display()
        {
            for(int i =0; i<nodes;i++)
            {
                cout<<i<<"->";
                for(int j : adj[i])
                {
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }

        void dfs(int node,int disTime[],int low[],int parent[],bool visited[],int &timer)
        {
            visited[node] = true;
            disTime[node]=low[node] = timer++;
            for(int nbr : adj[node])
            {
                
                // if(nbr == parent)
                // {
                //     continue;
                // }

                if(!visited[nbr])
                {
                    parent[nbr] = node;
                    dfs(nbr,disTime,low,parent,visited,timer);
                   
                    // CHeck for bridge
                    if(low[nbr]>disTime[node])
                    {
                        cout<<node<<"->"<<nbr;
                        cout<<endl;
                    }
                    

                }
                else if(nbr!=parent[node]){
                    // Back edge condition
                    low[node] = min(low[node],disTime[nbr]);
                }
            }
        }

        void Bridge()
        {
            int disTime[nodes],low[nodes],parent[nodes];
            // int parent = -1;
            int timer = 0;
            bool visited[nodes];
            for(int i=0;i<nodes;i++)
            {
                disTime[i]=-1;
                low[i]=-1;
                parent[i]=-1;
              
            }
            for(int i=0;i<nodes;i++)
            {
                visited[i] = false;
            }

            for(int i=0;i<nodes;i++)
            {
                if(!visited[i])
                {
                    dfs(i,disTime,low,parent,visited,timer);
                }
            }

                cout<<"\nDisTime:";
            for(int i=0;i<nodes;i++)
            {
                cout<<disTime[i]<<" ";
            }
            cout<<endl;

               cout<<"\nLow:";
            for(int i=0;i<nodes;i++)
            {
                cout<<low[i]<<" ";
            }
            cout<<endl;
        }

};

int main()
{
    int n;
    cin>>n;
    Graph g(n);
    g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(1,2);
	g.addEdge(3,4);
    g.display();
    g.Bridge();
    return 0;
}