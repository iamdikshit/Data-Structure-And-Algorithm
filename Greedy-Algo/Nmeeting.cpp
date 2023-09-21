// N meeting in one room problem

#include<bits/stdc++.h>
#include<vector>

using namespace std;

class CalculateMeeting{
	public:
		static bool cmp(pair<int,int> a,pair<int,int> b)
		{
			return (a.second < b.second);
		}
		
		
		void numberOfMeetings(int startTime[],int endTime[],int n)
		{
			// create a vector pair
			vector < pair<int,int> > v;
			
			// make a pair
			for(int i=0;i<n;i++)
			{
				pair<int,int> p = make_pair(startTime[i],endTime[i]);
				v.push_back(p);
			}
			
			// Sort the vector pair based on end time
			sort(v.begin(),v.end(),cmp);
			// here cmp is comparision function
			
			int count = 1;
			int ansEnd = v[0].second;
			
			for(int i =1; i<n; i++)
			{
				if(v[i].first>ansEnd)
				{
					count++;
					ansEnd = v[i].second;
				}
			}
			
			cout<<"\nNumber of meeting to be done : "<<count;
			
		}
		
};


int main(){
	
	CalculateMeeting cm;
	int startTime[6] = {1,3,0,5,8,5};
	int endTime[6] = {2,4,6,7,9,9};
	int n = 6;
	
	cm.numberOfMeetings(startTime,endTime,n);
	return 0;
}
