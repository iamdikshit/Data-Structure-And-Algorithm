#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        // check for 1 and 0
        if(n==1 || n==0)
        {
            cout<<n<<endl;
        }
        else{
            int i = 1;
            while(i*i<=n)
            {
                i++;
            }
            cout<<i-1<<endl;
        }
    }
    return 0;
}