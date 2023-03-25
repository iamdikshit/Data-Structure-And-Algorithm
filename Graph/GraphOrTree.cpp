#include <bits/stdc++.h>
#include<vector>
  using namespace std;
  
 void dfs(int node, vector< vector<int> > &adj,bool visited[],int &count)
 {
   visited[node] = true;
   for(int j:adj[node])
   {
     if(!visited[j])
     {
       dfs(j,adj,visited,count);
     }
     else{
        count++;
     }
   }
 }
  
  int main()
  {
    //write your code here
    int t;
    cin>>t;
    while(t--)
    {
      int v,e;
      cin>>v>>e;
      vector< vector<int> > adj;
      adj.resize(v);
      for(int i=0;i<e;i++)
      {
        int v1,v2;
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
      }
      
      bool visited[v];
      for(int i=0;i<v;i++)
      {
        visited[i] = false;
      }
      int count = 0;

      for(int i=0; i<v; i++)
        {
            cout<<i<<"->";
            for(auto j:adj[i])
            {
                cout<<j;
            }
                cout<<endl;
        }
      for(int i=0;i<v;i++)
      {
        if(!visited[i])
        {
          dfs(i,adj,visited,count);
        }
      }
        
      if(count==(v-1))
      {

      cout<<"Yes"<<endl;
      }
      else{
      cout<<"No"<<endl;

      }
    }
    
    return 0;
  }