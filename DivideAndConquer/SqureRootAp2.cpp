/*
    HERE WE USE BINARY SEARCH APPORACH
*/

#include<bits/stdc++.h>

using namespace std;

int SquareRoot(int n,int &ans)
{
     if(n==1 || n==0)
    {
        return n;
    }
    int high = n/2;
    int low = 1;
    
    while(low<=high)
    {
        int mid =(high+low)/2;

        if(mid * mid == n)
        {
            return mid;
        }
        if(mid*mid < n)
        {
            ans = mid;
            low = mid+1;
            //Right side
        
        }
        else
        {
            //Left side
            
            high = mid-1;
        }


    }

    
    return ans;

}

int main(){

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans;
        
        cout<<SquareRoot(n,ans)<<endl;
    }
    return 0;
}