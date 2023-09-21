


#include<bits/stdc++.h>

using namespace std;

int FindSum(int n)
{
    int sum = 0;
    if(n==0 || n==1)
        return 2;
    
    for(int i=1; i<n; i++)
    {
        sum+= 2 * FindSum(i) * FindSum(i-1);
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
    cout<<FindSum(n);
    return 0;
}
