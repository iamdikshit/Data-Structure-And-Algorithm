#include <bits/stdc++.h>
  using namespace std;
  
int main()
  {
    //write your code here
    int t,i,j;
    cin>>t;
    while(t--)
    {
      int n;
      cin>>n;
      int arr[n];
      int vote_count[n]={0};
      
      for(i=0;i<n;i++)
      {
        cin>>arr[i];
      }
      
      for(i=0;i<n;i++)
      {
        for(j=0;j<n;j++)
        {
          if(arr[i]==arr[j])
          {
            vote_count[i]++;
          }
        }
      }
      for(i=0;i<n;i++)
      {
        cout<<vote_count[i]<<" ";
      }
      cout<<endl;
      int max = vote_count[0];
      int max_pos = 0;
      for(i=0;i<n;i++)
      {
        if(vote_count[i]>max)
        {
          max = vote_count[i];
          max_pos = i;
        }
      }
      
      if(max>n/2)
      {
        cout<<max_pos<<endl;
      }
      else
      {
        cout<<-1<<endl;
      }
    }
    
    return 0;
  }
