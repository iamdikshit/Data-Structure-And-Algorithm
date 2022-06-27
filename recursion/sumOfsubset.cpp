#include<bits/stdc++.h>
using namespace std;

void sumOfSubset(int arr[],int index,vector<int>&subset,int n)
{
	if(index>=n)
	{
		return;
	}
	//exclude
	sumOfSubset(arr,index+1,subset,n);
	// include
	subset.push_back(arr[index]);
	sumOfSubset(arr,index+1,subset,n);
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int sum = 0;
	vector<int>subset;
	sumOfSubset(arr,0,subset,n);
	
	for (int i = 0; i < subset.size(); i++)
        cout<<subset[i]<<" ";
        
    cout<<sum;
	return 0;
}
