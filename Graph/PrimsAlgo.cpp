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

        void prims(int source)
        {
            // distance
            int distance[nodes],parents[nodes];
            bool mst[nodes];
            for(int i =0; i<nodes;i++)
            {
                distance[i] = INT_MAX;
                mst[i]=false;
            }
            distance[source] = 0;
            // Priority Queue
            priority_queue<int,vector<int>, greater<int> > q;
            q.push(source);
            parents[source] = -1;
            while(!q.empty())
            {
                int vertex = q.top();
                q.pop();
                for(auto pair:adj[vertex])
                {
                    int v = pair.first;
                    int w = pair.second;
                    // if we want to calculate distance from source
                    // int dist = distance[vertex]+w;

                    if(mst[v]==false && distance[v]>w)
                    {
                        distance[v] = w;
                        parents[v] = vertex;
                        mst[v]=true;
                        q.push(v);
                    }

                    // no need this code if we are not finding
                    // distance from source
                    // if(distance[v]>w)
                    // {
                    //     distance[v] = w;
                    //     q.push(v);
                    //     parents[v] = vertex;
                    // }
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
                cout<<parents[i]<<",";
            }

            cout<<"\nCost of Spanning Tree:";
            int sum = 0;
            for(int i=0;i<nodes;i++)
            {
                sum+=distance[i];
            }
            cout<<sum;

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
    g.addEdge(0,1,2);
    g.addEdge(0,3,6);
    g.addEdge(1,2,3);
    g.addEdge(1,3,8);
    g.addEdge(1,4,5);
    g.addEdge(4,2,7);
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
    g.prims(0);
    return 0;
}