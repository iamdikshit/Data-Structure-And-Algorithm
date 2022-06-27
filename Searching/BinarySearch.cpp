#include<bits/stdc++.h>
using namespace std;

class BinarySearch{
	public:
		int bsIteration(int arr[],int data,int low, int high)
		{
			int mid = (low+(high-low))/2;
			while(low<=high)
			{
				if(arr[mid]==data)
				return mid;
				else if (arr[mid]>data)
				high = mid-1;
				else
				low = mid+1;
			}
			return -1;
		}
};
int main()
{
	BinarySearch b;
	int n;
	int arr[n];
	int data;
	cin>>n;
	for(int i = 0; i<n; i++)
	{
		cin>>arr[i];
	}
	cin>>data;
	cout<<"Binary Search Iteration"<<endl;
	int res = b.bsIteration(arr,data,0,n-1); 
	if ( res!= -1)
	cout<<data<<" Found at position "<<res+1<<endl;
	else
	cout<<data<<" is not present";
	
	return 0;
}
