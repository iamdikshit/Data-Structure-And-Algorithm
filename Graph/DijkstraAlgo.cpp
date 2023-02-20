/*
*************************************************************
    SHORTEST PATH FOR WEIGHTRD GRAPH
    DIJKSTRA'S ALGORITHM
    USED GENERALISED BFS ALGORITHM TO FIND SHORTEST PATH
*************************************************************
*/

#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> ipair;
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

        void dijkstra(int source)
        {
            // min-heap 
            priority_queue< ipair,vector<ipair>, greater<ipair> > q;
            int distance[nodes],parent[nodes];
            for(int i=0; i<nodes;i++) distance[i]=-1;

            distance[source] = 0;
            q.push(make_pair(0,source));
            parent[source] = -1;

            while(!q.empty())
            {
                int vertex = q.top().second;
                q.pop();
                for(auto pair : adj[vertex])
                {
                    int v = pair.first;
                    int w = pair.second;
                    int dist = distance[vertex]+w;
                    if(distance[v]==-1)
                    {
                        distance[v] = dist;
                        q.push(make_pair(distance[v],v));
                        parent[v] = vertex;
                    }

                    if(distance[v]>dist)
                    {
                        distance[v] = dist;
                        q.push(make_pair(distance[v],v));
                        parent[v] = vertex;
                    }
                    
                }
            }


            cout<<"\nDistance : ";
            for(int i=0;i<nodes;i++)
            {
                cout<<distance[i]<<",";
            }
            cout<<"\nParents:";
            for(int i=0;i<nodes;i++)
            {
                cout<<parent[i]<<",";
            }

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
    // g.addEdge(0,1,4);
    // g.addEdge(0,2,1);
    // g.addEdge(1,4,4);
    // g.addEdge(2,1,2);
    // g.addEdge(2,3,4);
    // g.addEdge(3,4,4);
    g.addEdge(0,1,2);
    g.addEdge(0,3,1);
    g.addEdge(1,4,5);
    g.addEdge(1,2,4);
    g.addEdge(2,4,1);
    g.addEdge(2,3,3);

    g.display();
    g.dijkstra(0);
    return 0;
}