#include<bits/stdc++.h>
using namespace std;



void BubbleSort(int arr[], int n)
{
  int i, j,temp;
  bool swapped;
  for(i=n-1; i>=0; i--)
  {
    swapped = false;
    for(j = 0; j<i; j++)
    {
      if(arr[j]<arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
        swapped = true;
      }
      
      if(swapped == false)
      {
        break;
      }
    }
  }
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i = 0 ;i<n; i++)
		{
			cin>>arr[i];
		}
		// int max = MaxValue(arr,n);

		// CountSort(arr,n,max);
		BubbleSort(arr,n);
	
		cout<<endl;
		int sum = 0;
		for(int i=0; i<n; i+=2)
		{
		  sum = sum + arr[i];
		}
		
		cout<<sum<<endl;
		
	}
	return 0;
}
