/*
*************************************************************
    SHORTEST PATH FOR WEIGHTRD GRAPH
    BELLMAN FORD ALGORITHM
    USED FOR NEGATIVE WEIGHTED GRAPH
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

        void bellmanFordAlgo(int source)
        {
            // distance
            int distance[nodes],path[nodes];
            for(int i =0; i<nodes;i++) distance[i] = INT_MAX;
            distance[source] = 0;
            // Queue
            queue<int> q;
            q.push(source);
            path[source] = 0;
            while(!q.empty())
            {
                int vertex = q.front();
                q.pop();
                for(auto pair:adj[vertex])
                {
                    int v = pair.first;
                    int w = pair.second;
                    int dist = distance[vertex]+w;
                    if(distance[v]>dist)
                    {
                        distance[v] = dist;
                        path[v] = vertex;
                        q.push(v);
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
                cout<<path[i]<<",";
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
    n =3;
    /*
        0->directed graph
        1->undirected graph
    */
    Graph g(n,0);
    g.addEdge(0,1,2);
    g.addEdge(0,2,4);
    g.addEdge(2,1,-3);
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
    g.bellmanFordAlgo(0);
    return 0;
}